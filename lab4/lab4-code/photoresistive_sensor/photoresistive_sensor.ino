/*
  Photoresistive Sensor

  This example shows how to read from a photoresistive snesor
  The circuit:

*/
#define photoresistivePin 11

void setup()
{
 Serial.begin(9600);
}
void loop()
{
 if (digitalRead(photoresistivePin)){
    Serial.println("Dark");
 } else {
    Serial.println("Light");
 }
 delay(100);
}
