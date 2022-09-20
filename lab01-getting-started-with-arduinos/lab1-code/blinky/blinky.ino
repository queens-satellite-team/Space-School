// Title:         Blinky Program
// Last Updated:  September 20th, 2022
// Author:        < your name here >
// Breif:         Simple program to make sure our hardware setup is working.  

void setup() {
  pinMode(12, OUTPUT);
}

void loop() {
  digitalWrite(12, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(12, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
