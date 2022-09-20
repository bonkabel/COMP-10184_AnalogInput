#include <Arduino.h> 
// Author: Amy Abel, 000749165, September 19th 2022

// arduinos map() function, but for floats!
float mapFloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/// @brief Translates a temperature to a descriptor of that temperature
/// @param temp The temperature to translate
/// @return A descriptor of the temperature
String getTempRating(float temp) {
  if (temp < 10) {
    return "Cold!";
  }
  else if (temp >= 10 && temp < 15) {
    return "Cool";
  }
  else if (temp >= 15 && temp < 25) {
    return "Perfect";
  }
  else if (temp >= 25 && temp < 30) {
    return "Warm";
  }
  else if (temp >= 30 && temp < 35) {
    return "Hot";
  }
  else if (temp >= 35) {
    return "Too Hot!";
  }
  else {
    return "woops";
  }
}
 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
} 
 
void loop() { 
  int iVal; 
 
  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0); 

  float temp = mapFloat(iVal, 0, 1024, 0, 50);

  String tempRating = getTempRating(temp);
 
  // print value to the USB port 
  Serial.println("Digitized Value of " + String(iVal) + " is equivalent to a temperature input of " + String(temp) + " dog. c, which is " + tempRating);
 
  // wait 0.5 seconds (500 ms) 
  delay(2000); 
}

