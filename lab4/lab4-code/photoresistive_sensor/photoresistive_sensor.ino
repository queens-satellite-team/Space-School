/*
  Photoresistive Sensor

  This example shows how to read from a photoresistive snesor
  The circuit:

*/
#define photoresistivePin A0

void setup()
{
 Serial.begin(9600);
}
void loop()
{
 if (analogRead(photoresistivePin) > 20) Serial.println("Light");
 else Serial.println("Dark");
 delay(100);
}
