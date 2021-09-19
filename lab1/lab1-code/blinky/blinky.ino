// Title:         Blinky Program
// Last Updated:  September 15th, 2021
// Author:        < your name here >
// Breif:         Simple program to make sure our hardware setup is working.  

void setup() {
  pinMode(8, OUTPUT);
}

void loop() {
  digitalWrite(8, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(8, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
