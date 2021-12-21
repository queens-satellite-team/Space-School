# Introduction 
Hello! Welcome to the fourth lab of Space School! In this lab we are going to focus on building the hardware and software for our toastSats. We will begin by focusing on one electronic device at a time, and in future labs we will piece some of these different components together to make a payload system. **By the end of this lab you should have picked out one or two sensors, have all hardware connections made on a breadboard, and have all the required software written.** 

As a note, the Arduinos we are using in these labs are the _Arduino Nano Every_ and they are slightly different than the _Arduino Nano_. Please follow the steps in _Section 4: Uploading Code To An Arduino_ to make sure you can communicate with your board correctly. 

# Goals of Lab 4

1️⃣ Learn the layout of breadboards to assist in building your sensor circuit.  

2️⃣ Use the hardware requirements to help piece your selected sensor together.

3️⃣ Use the example code to develop the software for your selected sensors. 

4️⃣ Upload your code to the Arduino and verify the sensors are working. 

# Section 1: Breadboard Layout

There are many ways to assemble a circuit together. The most common way to start is with a [breadboard](https://en.wikipedia.org/wiki/Breadboard). Breadboards have internal connections that allow for quick work when piecing together new components of a ciruit. In the photo below, we see all the shared connections inside of a breadboard. The centre circut area in green has a shared connection for each column along with a divider in the middle (the top of the column and the bottom of the column are not connected), and the rows coloured blue and red show that there is a shared connection across the entire line (the top blue and red lines are not connected to the bottom blue and red lines). 

![image](https://user-images.githubusercontent.com/48306876/138555396-737f73e0-560d-4cb3-94b0-bc2318304226.png)

# Section 2: Building the Hardware

In this section, we focus on how to connect each one of the sensors to our Arduino Nano Every. Sensors are ordered below acording to their difficulty; the first sensor is the least difficult and increases to the most difficult. The pin out for the Arduino Nano Every is given below. 

<p align="center">
	<image src="https://user-images.githubusercontent.com/48306876/147003068-310568e6-bf67-4a1d-835d-a231ddbfba60.png" width="400" height="350">
</p>

## 2.1.0 Photoresistive Sensor
A photoresistor, or light-dependent resistor (LDR) is a resistor whose resistance will decrease when incident light intensity increase; in other words, it exhibits photoconductivity. This sensor has an adjustable dial so that you can set a light threshold for the sensor to detect. When the ambient light intensity does not reach the threshold value, the sensor output is high; when the ambient light level exceeds the set threshold, the sensor outputs a low value.

<img src="https://github.com/queens-satellite-team/Space-School/blob/fcfae3bbd3c562e2c20e1b6e5a6f9f731f0fa6e3/lab4/lab4-images/photosensitive-brightness-resistance-sensor-module.jpg" alt="Photoresistive Sensor" width="300">

### 2.1.1 🛠️ Hardware Requirements
- Pin out:
	- VCC: This is the power connection to the sensor. Needs to be connected to 3.3 or 5.0 volt power supply. (On the Arduino Uno/Nano: 3V3) (the breakout board has a voltage regulator).
	-  GND: This is the ground connection to the sensor. Needs to be connected to the ground of the power supply. (On the Arduino Uno/Nano: GND)
	-D0 Digital Output: THis is the pin that sends the digital signal form the sensor to the arduino.
- adjustable potentiometer to adjust the sensitivity

## 2.2.0 Temperature Sensor 🌡️
The TMP35/TMP36/TMP37 are low voltage, precision centigrade temperature sensors. They provide a voltage output that is linearly proportional to the Celsius (centigrade) temperature. The TMP35/ TMP36/TMP37 do not require any external calibration to provide typical accuracies of ±1°C at +25°C and ±2°C over the −40°C to +125°C temperature range. **[Datasheet](https://cdn-learn.adafruit.com/assets/assets/000/010/131/original/TMP35_36_37.pdf)**

<img src="https://github.com/queens-satellite-team/Space-School/blob/18f2d531abfe9a697c59f18389db6cbc8da6a0c9/lab4/lab4-images/temperature-sensor.jpeg" width="500" height="500">

### 2.2.1 🛠️ Hardware Requirements
- 2.7 V to 5.5 V Maximum Input Supply 
- The TMP36 is specified from −40°C to +125°C, provides a 750 mV output at 25°C. 
- Analog Signal Output 

## 2.3.0 Barometric Pressure Sensor ☁️ 
The BMP180 is a high precision digital pressure sensors for consumer applications. **[Datasheet](https://cdn-shop.adafruit.com/datasheets/BST-BMP180-DS000-09.pdf)**

<img src="https://user-images.githubusercontent.com/48306876/139978245-86f47086-f2b6-4a24-8435-6ca59ab14615.png" width="500" height="500">

### 2.3.1 🛠️ Hardware Requirements

- **Pin + (VDD):** This is the power connection to the sensor. Needs to be connected to 3.3 volt power supply. (On the Arduino Uno/Nano: 3V3)
- **Pin - (GND):** This is the ground connection to the sensor. Needs to be connected to the ground of the power supply. (On the Arduino Uno/Nano: GND) 
- **Pin DA (SDA):** This is the I2C data communication line. Needs to be connected to any pin labeled SDA. (On the Arduino Uno/Nano: A4) 
- **Pin CL (SCL):** This is the I2C clock communication line. Neends to be connected to any pin labelled SCL. (On the Arduino Uno/Nano: A5) 
- **Pin IO (VDDIO):** This is the input/output voltage control line. Leave this disconnected unless you're connecting to a lower-voltage microprocessor. 

## 2.4.0 Accelerometer / Gyroscope 🧭
This is the [Gikfun GY-521 MPU-6050 3 Axis Accelerometer Gyroscope](https://www.amazon.ca/Gikfun-MPU-6050-Accelerometer-Gyroscope-EK1091x3C/dp/B07JPK26X2/ref=sr_1_32?crid=1JQ9V4LAR8E4I&dchild=1&keywords=arduino+sensor&qid=1632086125&sprefix=arduino+sen%2Caps%2C188&sr=8-32) This sensor contains a 3-axis gyroscope, a 3-axis accelerometer, a digital motion processor (DMP), and a temperature sensor. The digital motion processor can be used to process complex algorithms directly on the board. Usually, the DMP processes algorithms that turn the raw values from the sensors into stable position data. **[Datasheet](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Register-Map1.pdf)**

![accelerometer](https://github.com/queens-satellite-team/Space-School/blob/43b3b927f3488278fb81b365fd4e02bb42c2b63f/lab4/lab4-images/mpu_650_pinout.jpg)

### 2.4.1 🛠️ Hardware Requirements

- **Pin VCC:** This is the power connection to the sensor. Needs to be connected to 3.3 or 5.0 volt power supply. (On the Arduino Uno/Nano: 3V3) (the breakout board has a voltage regulator). 
- **Pin GND:** This is the ground connection to the sensor. Needs to be connected to the ground of the power supply. (On the Arduino Uno/Nano: GND) 
- **Pin SCL:** This is the I2C clock communication line. Neends to be connected to any pin labelled SCL. (On the Arduino Uno/Nano: A5)
- **Pin SDA:** This is the I2C data communication line. Needs to be connected to any pin labeled SDA. (On the Arduino Uno/Nano: A4) 
- **Pin XDA:** This is the I2C auxiliary data line. Used if the sensor is to be an I2C master while connected to external sensors.
- **Pin XCL:** This is the I2C auxiliary clock line. Used if the sensor is to be an I2C master while connected to external sensors.
- **Pin AD0:** If this pin is LOW, the I2C address of the board will be 0x68. Otherwise, if the pin is HIGH, the address will be 0x69.
- **Pin INT:** This is the interrupt pin. The sensor uses this digital output to send an interrupt to another sensor or controller.

# Section 3: Writing the Software

All the required code can be found in the [lab 4 code directory](https://github.com/queens-satellite-team/Space-School/blob/main/lab4/lab4-code/). If you have built the hardware exactly as instructed in Section 2: Building the Hardware, you should be able to copy and paste the code found in the directory into your IDE and continue to Section 4: Uploading Code to An Arduino. 

## 3.1 Photodiode Software Requirements
There are no extra software requirements 

## 3.2 Temperature Software Requirements
- Analog to Digital Conversion : Digital Voltage Value = Analog Input Voltage * Input Voltage / 1024.0  
- Conversion Factor: Temperate C = [Vout in mV - 500mV] / (10mV / 1 °C)

## 3.2 Barometric Pressure Sensor Software Requirements
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

## 3.4 Accelerometer / Gyroscope Software Requirements

- Import the **Wire** card library. This library is required for any I2C device. To learn more about the I2C communication protocol check out [Harrison Gordon's work in our documentation repository](https://github.com/queens-satellite-team/documentation/blob/master/obc/i2c.md). 
- The sensor stores the acceleration and gyroscopic data in things called [registers](https://www.javatpoint.com/computer-registers). You can read and write to these registers to get the desired data. The [datasheet](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Register-Map1.pdf) contains all of the names, address, and purpose for each register. These explain where the numbers like `0x3B` and `0x68` come from in the example below. 

There is also an outstanding library that can be used to interact with the accelerometer / gyroscope [found here!](https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/MPU6050) This library has support for [Processing](https://processing.org/) which can be used to visualize the motions of the accelerometer. 

# Section 4: Uploading Code To An Arduino

The Arduino IDE is a tool we can use to write code as well as a tool to upload the code onto the Arduino once we are done writing it. We took a look at the Arduino IDE in [lab 1](https://github.com/queens-satellite-team/Space-School/blob/main/lab1/lab1.md), but as a refresher here are some of the more important features.

![Arduino IDE with Arrows Indicating IDE Functionality](https://github.com/queens-satellite-team/Space-School/blob/79665e8ba8a807e1ad268ef5515d1499b6250be8/lab1/lab1-images/ide-with-arrows.png)

Once you have your code written (or if you want to check for any syntax mistakes), you can attempt to compile your code. To compile your code:
1. Select *Verify* in the Arduino IDE, and the message *Compiling Sketch* should appear near the bottom of the IDE. Once this is finished it will say *Done Compiling* and display memory information about your code. 

Once the code is able to be succesfuly compiled, we can upload it to the Arduino board. 
1. Connect your Arduino board to your computer with a USB cable. This will supply power as well as communication to and from the Arduino board. You should see a red or orange LED turn on indicating that the Arduino board is receiving power. 
2. ❗❗❗ Add the Arduino megaAVR Core to the Arduino IDE. Select *Tools*, then *Boards* and last *Boards Manager*. Search for *megaAVR* and install the first option available.❗❗❗ 
3. Select *Tools*, then *Board* from the top menubar. Select the type of board you are using. 
4. Select *Tools*, then *Port* from the top menubar. Select the port that the arduino board is plugged into. 
- Note: On Windows, the port will be something like *COM4*, or *COM5*, while on Mac it will be something like */dev/cu.usbserial-1420*. 
5. If using an older arduino nano (or a cheap one bought from amazon), Select *Tools*, then *Processor* from the top menubar. Select *ATMega328P (Old Bootloader)*. 
6. Select *Upload* from within the IDE to upload the program onto the arduino board. 
- Note: if the program does not upload correctly make sure you have the correct board information and redo steps 2-4. 
7. Once successfully uploaded, open the serial monitor by selecting the far right bottun in the Arduino IDE.  

![image](https://user-images.githubusercontent.com/48306876/140007601-1c0ce126-b360-4b9d-a343-59c3ff612379.png)

# Section 5: Payload Up To Date

Before moving on to lab 5 your payload should look something like the photo below with the addition of an SD card writer (the toastSat Payload below does not include one yet, but yours should). 

<img src="https://user-images.githubusercontent.com/48306876/140006482-feb81814-aeec-4860-9608-ca048084c2e8.jpg" width=500 height=500>
