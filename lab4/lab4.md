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

# 5.0 Temperature Sensor 🌡️
The TMP35/TMP36/TMP37 are low voltage, precision centigrade temperature sensors. They provide a voltage output that is linearly proportional to the Celsius (centigrade) temperature. The TMP35/ TMP36/TMP37 do not require any external calibration to provide typical accuracies of ±1°C at +25°C and ±2°C over the −40°C to +125°C temperature range. **[Datasheet](https://cdn-learn.adafruit.com/assets/assets/000/010/131/original/TMP35_36_37.pdf)**

## 5.1 🛠️ Hardware Requirements
- 2.7 V to 5.5 V Maximum Input Supply 
- The TMP36 is specified from −40°C to +125°C, provides a 750 mV output at 25°C. 
- Analog Signal Ouput 

## 5.2 💻 Software Requirements
- Analog to Digital Conversion : Digial Voltage Value = Analog Input Voltage * Input Voltage / 1024.0  
- Conversion Factor: Temperate C = [Vout in mV - 500mV] / (10mV / 1 °C)

## 5.3 Example

```
// set the analog input pin
int input_pin = 0;

// set global variables 
int analog_data;
float voltage_reading;
float temperatureC; 
  
void setup()
{
}

void loop()
{
  // read the analog input
  analog_input = analogRead(sensor_pin);
  
  // convert analog input to a voltage value
  voltage_reading = analog_input * (5.0/1024.0); 
  
  // convert voltage value to a temperature value
  temperatureC = (voltage_reading - 0.5) * 100; 
}
```

# 6.0 SD Card Writer

## 6.1 Hardware Requirements

## 6.2 Software Requirements

## 6.3 Example

