// Title:         Hello World Program
// Last Updated:  September 15th, 2021
// Author:        < your name here >
// Breif:         Simple program to make sure our setup is working.  

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Hello World!");
  delay(1000);
}
