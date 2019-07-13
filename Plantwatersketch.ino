#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define WIFI_SSID "NandipatiWifi"
#define WIFI_PASS "kalya1509"

#define MQTT_SERV "io.adafruit.com"
#define MQTT_PORT 1883
#define MQTT_NAME "pacchu"
#define MQTT_PASS "c92d91fe49fe423181e7722080b8adcb"

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, MQTT_SERV, MQTT_PORT, MQTT_NAME, MQTT_PASS);
Adafruit_MQTT_Subscribe relay1 = Adafruit_MQTT_Subscribe(&mqtt, MQTT_NAME "/f/relay1");
Adafruit_MQTT_Subscribe relay2 = Adafruit_MQTT_Subscribe(&mqtt, MQTT_NAME "/f/relay2");
Adafruit_MQTT_Subscribe relay3 = Adafruit_MQTT_Subscribe(&mqtt, MQTT_NAME "/f/relay3");
Adafruit_MQTT_Subscribe relay4 = Adafruit_MQTT_Subscribe(&mqtt, MQTT_NAME "/f/relay4");

void setup()
{
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(0,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(16,OUTPUT);



  Serial.begin(9600);
  //Connect to WiFi
  Serial.print("\n\nConnecting Wifi");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  digitalWrite(LED_BUILTIN, LOW);
  while (WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(16,HIGH);
    Serial.print(".");
    delay(50);
    digitalWrite(16,LOW);
  }
  delay(100);
  Serial.println("\nConnected!");
  digitalWrite(16,HIGH);

  mqtt.subscribe(&relay1);
  mqtt.subscribe(&relay2);
  mqtt.subscribe(&relay3);
  mqtt.subscribe(&relay4);
  
}

void loop(){

  MQTT_connect();
  Adafruit_MQTT_Subscribe * subscription;
  while ((subscription = mqtt.readSubscription(5000))){   
    //RELAY1
    if (subscription == &relay1){
      Serial.print("Water Plants : ");
      //Serial.println((char*) relay1.lastread);
      int read1 = atoi((char*)relay1.lastread);
      if(read1 == 1){
        digitalWrite(5,HIGH);
        Serial.println("ON");  
      }else if(read1 == 0){
        digitalWrite(5,LOW);
        Serial.println("OFF");
        
      }
    }

    //RELAY2

    
    if (subscription == &relay2){
      Serial.print("Washing Machine: ");
      Serial.println((char*) relay2.lastread);
      int read2 = atoi((char*)relay2.lastread);
      if(read2 == 1){
        digitalWrite(4,HIGH);
        Serial.println("ON");    
      }else if(read2 == 0){
        digitalWrite(4,LOW);
        Serial.println("OFF");
      }
    }

    //RELAY3

    if (subscription == &relay3){
      Serial.print("Sprinklers : ");
      Serial.println((char*) relay3.lastread);
      int read3 = atoi((char*)relay3.lastread);
      if(read3 == 1){
        digitalWrite(0,HIGH);
        Serial.println("ON");    
      }else if(read3 == 0){
        digitalWrite(0,LOW);
        Serial.println("OFF");
      }
    }

    //RELAY4

    
    if (subscription == &relay4){
      Serial.print("Bulb: ");
      Serial.println((char*) relay4.lastread);
      int read4 = atoi((char*)relay4.lastread);
      if(read4 == 1){
        digitalWrite(2,HIGH);
        Serial.println("ON");    
      }else if(read4 == 0){
        digitalWrite(2,LOW);
        Serial.println("OFF");
      }
    }

    
 }
}

void MQTT_connect(){

  //  // Stop if already connected
  if (mqtt.connected() && mqtt.ping())
  {
    //    mqtt.disconnect();
    return;
  }

  int8_t ret;

  mqtt.disconnect();

  Serial.print("Connecting to Adafruit IO Database. ");
  uint8_t retries = 2;
  while ((ret = mqtt.connect()) != 0) // connect will return 0 for connected
  {
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying connection in 5 seconds...");
    mqtt.disconnect();
    delay(5000);  // wait 5 seconds
    retries--;
    if (retries == 0)
    {
      ESP.reset();
    }
  }
  Serial.println("Connection sucessful!");
}
