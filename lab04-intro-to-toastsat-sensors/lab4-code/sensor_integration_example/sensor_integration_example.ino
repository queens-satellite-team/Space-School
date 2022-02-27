// Title:         Sensor Inegration Example
// Last Updated:  October 25th, 2021
// Author:        Emma Paczkowski
// Breif:         This program integrated all sensors used in the Space School Fall of 2021 program into a single sript as an example of what could be done with the sensor suite
// set the analog input pin
int input_pin = 0;


void setup()
{
}

void loop()
{
   // read the analog input
   int analog_input = analogRead(input_pin);
  
   // convert analog input to a voltage value
   int voltage_reading = analog_input * (5.0/1024.0); 
  
   // convert voltage value to a temperature value
   int temperatureC = (voltage_reading - 0.5) * 100; 
   Serial.println(temperatureC);
}
