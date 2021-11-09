# Introduction 
Hello! Welcome to the fourth lab of Space School! In this lab we are going to design the software for your payload. In this lab you will find the hardware that we have purchased for the payloads along with the software requirements, hardware requirements and example code. In your groups you will be selecting which sensors you want to implement and developing the software to put them together.

If you have any questions, please feel free to reach out to Emma Paczkowski, Sean Tedesco, Piper Steffen, Thomas Sears, or any other member of the QSAT Team. Contact info can be found in the [readme](https://github.com/queens-satellite-team/Space-School) of this repository. 

# Goals of Lab 4
1️⃣ Select your sensors.

2️⃣ Use the example code to develop your software for your toastSat.

3️⃣ Use the hardware requirements to help piece you sensors all together.


# 1.0 Photoresistive Sensor
A photoresistor, or light-dependent resistor (LDR) is a resistor whose resistance will decrease when incident light intensity increase; in other words, it exhibits photoconductivity. This sensor has an adjustable dial so that you can set a light threshold for the sensor to detect. When the ambient light intensity does not reach the threshold value, the sensor output is high; when the ambient light level exceeds the set threshold, the sensor outputs a low value.

<img src="https://github.com/queens-satellite-team/Space-School/blob/fcfae3bbd3c562e2c20e1b6e5a6f9f731f0fa6e3/lab4/lab4-images/photosensitive-brightness-resistance-sensor-module.jpg" alt="Photoresistive Sensor" width="300">

## 1.1 Hardware Requirements
- Pin out:
	- VCC: This is the power connection to the sensor. Needs to be connected to 3.3 or 5.0 volt power supply. (On the Arduino Uno/Nano: 3V3) (the breakout board has a voltage regulator).
	-  GND: This is the ground connection to the sensor. Needs to be connected to the ground of the power supply. (On the Arduino Uno/Nano: GND)
	-D0 Digital Output: THis is the pin that sends the digital signal form the sensor to the arduino.
- adjustable potentiometer to adjust the sensitivity

## 1.2 Software Requirements
There are no extra software requirements 

## 1.3 Example
```
/*
  Photoresistive Sensor

  This example shows how to read from a photoresistive sensor
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
```

# 2.0 Accelerometer / Gyroscope 🧭
This is the [Gikfun GY-521 MPU-6050 3 Axis Accelerometer Gyroscope](https://www.amazon.ca/Gikfun-MPU-6050-Accelerometer-Gyroscope-EK1091x3C/dp/B07JPK26X2/ref=sr_1_32?crid=1JQ9V4LAR8E4I&dchild=1&keywords=arduino+sensor&qid=1632086125&sprefix=arduino+sen%2Caps%2C188&sr=8-32) This sensor contains a 3-axis gyroscope, a 3-axis accelerometer, a digital motion processor (DMP), and a temperature sensor. The digital motion processor can be used to process complex algorithms directly on the board. Usually, the DMP processes algorithms that turn the raw values from the sensors into stable position data. **[Datasheet](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Register-Map1.pdf)**

![accelerometer](https://github.com/queens-satellite-team/Space-School/blob/43b3b927f3488278fb81b365fd4e02bb42c2b63f/lab4/lab4-images/mpu_650_pinout.jpg)

## 2.1 🛠️ Hardware Requirements

- **Pin VCC:** This is the power connection to the sensor. Needs to be connected to 3.3 or 5.0 volt power supply. (On the Arduino Uno/Nano: 3V3) (the breakout board has a voltage regulator). 
- **Pin GND:** This is the ground connection to the sensor. Needs to be connected to the ground of the power supply. (On the Arduino Uno/Nano: GND) 
- **Pin SCL:** This is the I2C clock communication line. Neends to be connected to any pin labelled SCL. (On the Arduino Uno/Nano: A5)
- **Pin SDA:** This is the I2C data communication line. Needs to be connected to any pin labeled SDA. (On the Arduino Uno/Nano: A4) 
- **Pin XDA:** This is the I2C auxiliary data line. Used if the sensor is to be an I2C master while connected to external sensors.
- **Pin XCL:** This is the I2C auxiliary clock line. Used if the sensor is to be an I2C master while connected to external sensors.
- **Pin AD0:** If this pin is LOW, the I2C address of the board will be 0x68. Otherwise, if the pin is HIGH, the address will be 0x69.
- **Pin INT:** This is the interrupt pin. The sensor uses this digital output to send an interrupt to another sensor or controller.

## 2.2 💻 Software Requirements

- Import the **Wire** card library. This library is required for any I2C device. To learn more about the I2C communication protocol check out [Harrison Gordon's work in our documentation repository](https://github.com/queens-satellite-team/documentation/blob/master/obc/i2c.md). 
- The sensor stores the acceleration and gyroscopic data in things called [registers](https://www.javatpoint.com/computer-registers). You can read and write to these registers to get the desired data. The [datasheet](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Register-Map1.pdf) contains all of the names, address, and purpose for each register. These explain where the numbers like `0x3B` and `0x68` come from in the example below. 

There is also an outstanding library that can be used to interact with the accelerometer / gyroscope [found here!](https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/MPU6050) This library has support for [Processing](https://processing.org/) which can be used to visualize the motions of the accelerometer. 

## 2.3 Example
```
#include<Wire.h>
const int MPU=0x68; 
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
  Serial.begin(9600);
}
void loop(){
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);  
  AcX=Wire.read()<<8|Wire.read();    
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read();  
  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read();  
  
  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(AcX);
  Serial.print(" | Y = "); Serial.print(AcY);
  Serial.print(" | Z = "); Serial.println(AcZ); 
  
  Serial.print("Gyroscope: ");
  Serial.print("X = "); Serial.print(GyX);
  Serial.print(" | Y = "); Serial.print(GyY);
  Serial.print(" | Z = "); Serial.println(GyZ);
  Serial.println(" ");
  delay(333);
}
```


# 3.0 Barometric Pressure Sensor ☁️ 
The BMP180 is a high precision digital pressure sensors for consumer applications. **[Datasheet](https://cdn-shop.adafruit.com/datasheets/BST-BMP180-DS000-09.pdf)**

<img src="https://user-images.githubusercontent.com/48306876/139978245-86f47086-f2b6-4a24-8435-6ca59ab14615.png" width="500" height="500">

## 3.1 🛠️ Hardware Requirements

- **Pin + (VDD):** This is the power connection to the sensor. Needs to be connected to 3.3 volt power supply. (On the Arduino Uno/Nano: 3V3)
- **Pin - (GND):** This is the ground connection to the sensor. Needs to be connected to the ground of the power supply. (On the Arduino Uno/Nano: GND) 
- **Pin DA (SDA):** This is the I2C data communication line. Needs to be connected to any pin labeled SDA. (On the Arduino Uno/Nano: A4) 
- **Pin CL (SCL):** This is the I2C clock communication line. Neends to be connected to any pin labelled SCL. (On the Arduino Uno/Nano: A5) 
- **Pin IO (VDDIO):** This is the input/output voltage control line. Leave this disconnected unless you're connecting to a lower-voltage microprocessor. 

## 3.2 💻 Software Requirements
To easily communicate with this sensor, we can use a pre-written library. Libraries are collections of software functions geared towards a single purpose, such as communicating with a specific device. Fortunately, there is a pre-written Arduino library called SFE_BMP180 that allows you to easily talk to the BMP180 sensor. This library is not included with the stock Arduino software, but don't worry, installing new libraries is easy.

1. Follow this link: https://learn.sparkfun.com/tutorials/bmp180-barometric-pressure-sensor-hookup-/all#res
2. Follow the instructions in the **_Installing the Arduino Library_** section. 
3. Open any example sketch from _File > Examples > Examples from Custom Libraries_ 
4. Compile the sketch to verify that the software is working correctly. 

Notes About Using the BMP180 Library.
- You must first get a temperature measurement to perform a pressure reading.
- Using the .startTemperature() and .startPressure() methods returns the time required to wait before using the .getTemperature() and .getPressure() methods. 
- The .getTemperature() and .getPressure() methods return 0 if the measurement failed, or 1 if successful. 
- The pressure sensor returns absolute pressure with .getPressure(), which varies with altitude. To remove the effects of altitude, use the sea-level function and your current altitude.

This sensor also uses the Wire.h library used to communicate to sensors with the I2C communication protocol. To learn more about the I2C communication protocol check out [Harrison Gordon's work in our documentation repository](https://github.com/queens-satellite-team/documentation/blob/master/obc/i2c.md). 

## 3.3 Example

```
#include <SFE_BMP180.h>
#include <Wire.h>

#define ALTITUDE 1655.0 

SFE_BMP180 pressure_sensor;

void setup()
{
    // start up the pressure sensor 
    pressure_sensor.begin(); 
}

void loop()
{
    char status;
    double T,P,p0,a;
    
    // You must first get a temperature measurement to perform a pressure reading.
    status = pressure.startTemperature();
    delay(status);
    
    // Retrieve the completed temperature measurement, measurement is stored in the variable T.
    status = pressure.getTemperature(T);
    
    // Start a pressure measurement: the parameter is the oversampling setting, from 0 to 3 (highest res, longest wait).
    status = pressure.startPressure(3);
    delay(status);
    
    // Retrieve the completed pressure measurement, measurement is stored in the variable P.
    status = pressure.getPressure(P,T);
    
    // Retrieve the relative (sea-level) pressure, measurement is stored in the variable p0. 
    p0 = pressure.sealevel(P, ALTITUDE);
    
    // Retreive the current altitude from the pressure reading
    a = pressure.altitude(P,p0);
    
    // include a delay to not overwork the sensor
    delay(5000); 
}
```

# 4.0 Temperature Sensor 🌡️
The TMP35/TMP36/TMP37 are low voltage, precision centigrade temperature sensors. They provide a voltage output that is linearly proportional to the Celsius (centigrade) temperature. The TMP35/ TMP36/TMP37 do not require any external calibration to provide typical accuracies of ±1°C at +25°C and ±2°C over the −40°C to +125°C temperature range. **[Datasheet](https://cdn-learn.adafruit.com/assets/assets/000/010/131/original/TMP35_36_37.pdf)**

<img src="https://github.com/queens-satellite-team/Space-School/blob/18f2d531abfe9a697c59f18389db6cbc8da6a0c9/lab4/lab4-images/temperature-sensor.jpeg" width="500" height="500">

## 4.1 🛠️ Hardware Requirements
- 2.7 V to 5.5 V Maximum Input Supply 
- The TMP36 is specified from −40°C to +125°C, provides a 750 mV output at 25°C. 
- Analog Signal Output 

## 4.2 💻 Software Requirements
- Analog to Digital Conversion : Digital Voltage Value = Analog Input Voltage * Input Voltage / 1024.0  
- Conversion Factor: Temperate C = [Vout in mV - 500mV] / (10mV / 1 °C)

## 4.3 Example

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
   analog_input = analogRead(input_pin);
  
   // convert analog input to a voltage value
   voltage_reading = analog_input * (5.0/1024.0); 
  
   // convert voltage value to a temperature value
   temperatureC = (voltage_reading - 0.5) * 100; 
}
``` 
