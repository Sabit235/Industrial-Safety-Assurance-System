#include <Arduino.h>
#include "DHT.h"
#include <Adafruit_Sensor.h>

//! Pin Definitions modify pin here
int gasSensorInputPin = 13;
int gasSensorOutputPin = 23;
int gasSensorThreshold = 2000;

//int tempSensorInputPin = 32;
int tempSensorOutputPin = 22;

#define DHTPIN 32    // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);
//!---------------------------------

void setup() {
  Serial.begin(9600);
  pinMode(gasSensorInputPin, INPUT);
  pinMode(gasSensorOutputPin, OUTPUT);

  // pinMode(tempSensorInputPin, INPUT);
  // pinMode(tempSensorOutputPin, OUTPUT);

  dht.begin();

  Serial.println("Initialization Complete");
}

void loop() {

  int gasSensorValue = analogRead(gasSensorInputPin);
  Serial.println(gasSensorValue);

  if (gasSensorValue > gasSensorThreshold)
  {
    digitalWrite(gasSensorOutputPin, HIGH);
  }
  else
  {
    digitalWrite(gasSensorOutputPin, LOW);
  }
  
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");

  delay(250);
}