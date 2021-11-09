// analog pin
int sensor_pin = 0;

int analog_data;
float voltage_reading;
float temperatureC; 
  
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // read the analog input
  analog_data = analogRead(sensor_pin);
  
  // convert analog input to a voltage value 
  // change 5.0 to 3.3 if using 3.3 volt supply
  voltage_reading = analog_data * (5.0/1024.0); 
  
  // convert voltage value to a temperature value
  temperatureC = (voltage_reading - 0.5) * 100; 
  
  // print out our values 
  Serial.print("Analog Value: ");
  Serial.println(analog_data);
  
  Serial.print("Voltage Value: ");
  Serial.print(voltage_reading);
  Serial.println(" V");
  
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");
  Serial.println("");
  
  delay(1000); 
}
