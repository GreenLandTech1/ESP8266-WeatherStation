#include <Wire.h>
#include <BH1750.h>
 #include "DHT.h"
 #include <Adafruit_BMP085.h>
#ifdef ESP32
  #include <WiFi.h>
  #include <HTTPClient.h>
#else
  #include <ESP8266WiFi.h>
  #include <ESP8266HTTPClient.h>
#endif

HTTPClient http;
//WiFiClient client;

 
const char* ssid = "Bbox-4349589A";
const char* password = "6<ZbrA2)gufnFCKY"
String ServerIP="192.168.4.1";

#define seaLevelPressure_hPa 1013.25

Adafruit_BMP085 bmp;
#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11
 
BH1750 lightMeter;
 
 DHT dht(DHTPIN, DHTTYPE);
void setup(){
  Serial.begin(9600);
  lightMeter.begin();
  Serial.println("Running...");
dht.begin();
if (!bmp.begin()) {
  Serial.println("Could not find a valid BMP085 sensor, check wiring!");
  while (1) {}
  }
  WiFi.begin(ssid, password);
 Serial.print("Connecting..");
  while (WiFi.status() != WL_CONNECTED) {
  Serial.print(".");
    delay(1000);
    
 
  }
  Serial.println();
  Serial.println("connected");
}
 
 
void loop() {

    delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F(" Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("C "));
  Serial.print(f);
  Serial.print(F("F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("C "));
  Serial.print(hif);
  Serial.println(F("F"));
  uint16_t lux = lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  delay(1000);


Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    
    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");

    Serial.print("Altitude = ");
    Serial.print(bmp.readAltitude());
    Serial.println(" meters");

    Serial.print("Pressure at sealevel (calculated) = ");
    Serial.print(bmp.readSealevelPressure());
    Serial.println(" Pa");

    Serial.print("Real altitude = ");
    Serial.print(bmp.readAltitude(seaLevelPressure_hPa * 100));
    Serial.println(" meters");
    
    Serial.println();
    delay(500);
  BearSSL::WiFiClientSecure client;
 client.setInsecure();
 client.setTimeout(15000);
 String str="http://"+ServerIP+":443/readings.php?temp="+String(t)+"&hum="+String(h)+"&lux="+String(lux)+"&bpmtemp="+String(bmp.readTemperature())+"&pressure="+String(bmp.readPressure())+"&alt="+String(bmp.readAltitude());
    http.begin(client,str);
     Serial.println(str);
    int httpCode = http.GET();                                  //Send the request
 Serial.println(httpCode);
 //   if (httpCode > 0) { //Check the returning code
 
      String payload = http.getString();   //Get the request response payload
      Serial.println(payload);             //Print the response payload
 
  //  }
 
    http.end();   //Close connection
 
}
