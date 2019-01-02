/*
  Example sketch Thingspeak.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  Based on WebClientSSL example by Bportaluri.
  http://kjll.cm/arduino-wifiesp

  Based on NeoPixel 60 Ring Wall Clock by Andy Doro
  http://kjll.cm/arduino-clock

  Using example code from the Rtc by Makuna Library
  https://github.com/Makuna/Rtc

*/


// Include the libraries
#include <Adafruit_NeoPixel.h>
#include <Adafruit_TiCoServo.h>
#include <RtcDS3231.h>
#include <SoftwareSerial.h>
#include "SSD1306AsciiWire.h"
#include "WiFiEsp.h"
#include <Wire.h>

// Declare and initialise global constants for Neopixel settings
const byte neoPixels = 24;
const byte neoPin = 10;

// Declare and initialise global arrays for WiFi settings
char ssid[] = "Kjellnet"; 
char pass[] = "metalotusinbingowebb";

// Declare and initialise global variables/arrays for Thingspeak connection
const char server[] = "thingspeak.com";
const char thingspeakAPIKey[] = "";
const int postingInterval = 30;

// Create new display object
SSD1306AsciiWire oled;

// Create new Neopixel object
Adafruit_NeoPixel ring = Adafruit_NeoPixel(neoPixels, neoPin, NEO_GRB);

// Create new RTC module object
RtcDS3231<TwoWire> rtcModule(Wire);

// Create new client object
WiFiEspClient client;

// Create new servo object
Adafruit_TiCoServo servo; 

// Create WiFi module object on GPIO pin 6 (RX) and 7 (TX)
SoftwareSerial Serial1(6, 7);

// Declare and initialise variable for radio status 
int status = WL_IDLE_STATUS;

// Declare global variables for time and temperature
int hours;
int minutes;
int seconds;
float temp;

// Declare global variables/arrays for timing
int oldMinute;
char lastSent[20];

void setup() {
  
  // Enable I2C communication
  Wire.begin();         

  // Start display on adress 0x3C
  oled.begin(&Adafruit128x64, 0x3C);
  oled.setFont(utf8font10x16);
  oled.clear();
  oled.print("Starting");
  
  // Initialise serial for debugging
  Serial.begin(115200);
  servo.attach(9);

  // Start RTC module
  rtcModule.Begin();

  // Start Neopixel ring
  ring.begin();
  ring.setBrightness(100);   
  ring.show();

  // Add dot to start up animation
  oled.print(".");

  // Initialise serial for ESP module
  Serial1.begin(9600);
  
  // Initialise ESP module
  WiFi.init(&Serial1);

  // Add dot to start up animation
  oled.print(".");

  // Check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // Don't continue
    while(true);
  }
  
  // Attempt to connect to WiFi network
  while(status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);

    // Add dot to start up animation
    oled.print(".");
  }
  printWifiStatus();
  printOled();
  updateTemp();
}

void loop(){
  updateTime();
  updateNeoRing();
  
  // Update channel on Thingspeak (every postingInterval)
  if(seconds%postingInterval == 0){
    updateTemp();
    sendThingspeak(temp);
  } 

  client.flush();
  client.stop();
  delay(500);
}

void sendThingspeak(float value) {
  if (client.connectSSL(server, 443)) {
    Serial.println("Connected to server.");
    client.println("GET /update?api_key=" + String(thingspeakAPIKey) + 
    "&field1=" + String(value) + " HTTP/1.1");
    client.println("Host: api.thingspeak.com");
    client.println("Connection: close");
    client.println();
    Serial.println("Sent to server.");
    
    // Save sent time as char-array
    sprintf(lastSent, "Sent: %02d:%02d:%02d", hours, minutes, seconds);
    
    // Update time on display
    printOled();
    delay(1000);
  }
}

void updateTime() {
  oldMinute = minutes;
  RtcDateTime now = rtcModule.GetDateTime();

  // Save time in variables
  hours = now.Hour();
  minutes = now.Minute();
  seconds = now.Second();

  // Update screen on minute update
  if(minutes != oldMinute) {
    printOled();
  } 

  // Update time on Neopixel ring
  updateNeoRing();
}


void printOled() {
  
  // Format and print time on display
  oled.clear();
  oled.setFont(lcdnums14x24);
  oled.setCol(20);
  char timeString[6];
  sprintf(timeString, "%02d:%02d", hours,minutes);
  oled.println(timeString);

  // Format and print temperature on display
  oled.setFont(utf8font10x16);
  oled.setRow(6);
  oled.setCol(100);
  oled.print(int(temp));
  oled.write(176);

  // Format and print last sent time on display
  oled.setCol(0);
  oled.print(lastSent);
}

// Display time on Neopixel ring
void updateNeoRing() {
  
  // Map minutes and hours to 24 pixels
  int neoMin = round(minutes/2.5-1);
  int neoHour = hours%12*2-1;
  
  // Declare variables for number of blue and red pixels
  int blue;
  int red;

  // Set colors on Neopixel according to time
  for(int i = 0; i <= neoPixels; i++){
    if (i <= neoMin) {
      blue = 255;
    } else {
      blue = 0;
    }
    
    if (i <= neoHour) {
      red = 255;   
    } else {
      red = 0;
    }
    
    ring.setPixelColor(i, ring.Color(red, 0, blue));
  }

  // Update Neopixel ring
  ring.show();
}

void updateTemp(){
  
  // Read temperature
  RtcTemperature rtcTemp = rtcModule.GetTemperature();
  temp = rtcTemp.AsFloatDegC();

  // Map temperature to servo
  int tempPointer = map(temp, 18, 28, 30, 140);

  // Turn servo to temperature
  servo.write(tempPointer);
}

void printWifiStatus() {
  
  // Print the SSID of the network
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // Print the IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}
