# Introduction 

# Goals of Lab 4

# 1.0 Photoresistive Sensor

## 1.1 Hardware Requirements

## 1.2 Software Requirements

## 1.3 Example

# 2.0 Accelerometer

## 2.1 Hardware Requirements

## 2.2 Software Requirements

## 2.3 Example

# 3.0 Barometric Pressure Sensor

## 3.1 Hardware Requirements

## 3.2 Software Requirements

## 3.3 Example

# 4.0 IR Sensor

## 4.1 Hardware Requirements

## 4.2 Software Requirements

## 4.3 Example

# 5.0 Temperature Sensor

## 5.1 Hardware Requirements

## 5.2 Software Requirements

## 5.3 Example

```
// set the analog input pin
int input_pin = 0;

int analog_data;
float voltage_reading;
float temperatureC; 
  
void setup()
{
}

void loop()
{
  // read the analog input
  analog_data = analogRead(sensor_pin);
  
  // convert analog input to a voltage value
  voltage_reading = analog_data * (5.0/1024.0); 
  
  // convert voltage value to a temperature value
  temperatureC = (voltage_reading - 0.5) * 100; 
}
```

# 6.0 SD Card Writer

## 5.1 Hardware Requirements

## 5.2 Software Requirements

## 5.3 Example

