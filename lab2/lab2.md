# Introduction

Hello! Welcome to the second lab of Space School! In this lab we continue with our circuits and coding section of Space School by diving a bit deeper in working with our Arduino microcontroller. We will be working with the **TMP36** temperature sensor to learn some fundamental programming and circuit skills. The goal is to learn how to get a simple sensor working, so that you can be more comfortable getting your own more complex sensor to work on your payload. 

If you have any questions please feel free to reach out to Emma Paczkowski, Sean Tedesco, Piper Steffen, Thomas Sears, or any other member of the QSAT Team. Contact info can be found at the main page of this repository. 

# Goals of Lab 2

1️⃣  Simulate the hardware of a TMP36 temperature sensor

2️⃣  Write software to read values form a TMP36 temperature sensor

3️⃣  Use the TMP36's data sheet to guide our implementation of hardware and software

# Step 1 - TMP36 Overview
Our goal is to read the ambient temperature of our payload using a sensor. We can do this by using the TMP36 temperature sensor, which is an analog electronic device. In Step 1, we will figure out what exactly that means, and what are the characteristics of this sensor. 

## Analog vs. Digital Signals
Working with electronics means dealing with both analog and digital signals, inputs and outputs. Our electronics projects have to interact with the real, analog world in some way, but most of our microprocessors, computers, and logic units are purely digital components.

**Signal** - a thing that can convey information and that can change with time. 

**Digital** - a discrete signal that can only take on discrete states, such as ON or OFF. 

**Analog** - a continuous signal which represents physical measurements.

**DIGITAL SIGNAL**

![digitla_circuit](https://github.com/queens-satellite-team/Space-School/blob/05136f902023ba22127d2734c8aa126bb90d718e/lab2/lab2-images/digital_signal.png) 

**ANALOG SIGNAL**

![analog_circuit](https://github.com/queens-satellite-team/Space-School/blob/05136f902023ba22127d2734c8aa126bb90d718e/lab2/lab2-images/analog_signal.png)

So a good way to think of the difference between these two signals in an electrical engineering context is that a digital signal will turn on and off an LED, but an analog signal will dim the led a litter more or less bright. 

❓ What are some other things you may want to measure using your toastSat that is going 30km into the atmoshere? 

❓ Are these measurements digital or analog? 

## Datasheet

![TMP36 Next to a Coin](https://github.com/queens-satellite-team/Space-School/blob/01efedf88740647ccd69433bf9f45f66f0af0abe/lab2/lab2-images/tmp36-overview.jpeg)

Back to our sensor! So long the days of [mercury](https://en.wikipedia.org/wiki/Mercury-in-glass_thermometer) rising with the heat; so long the days of [bimetallic](https://en.wikipedia.org/wiki/Bimetallic_strip) strips; so long the days where we must use [temperature dependent resistors](https://en.wikipedia.org/wiki/Thermistor) to tell the temperature. These TMP36 sensors use a solid-state technique to determine the temperature. They use the fact as temperature increases, the voltage across a diode increases at a known rate. By precisely amplifying the voltage change, it is easy to generate an analog signal that is directly proportional to temperature.

So let's look at some characteristics of our sensor now. Looking at the [datasheet](https://cdn-learn.adafruit.com/assets/assets/000/010/131/original/TMP35_36_37.pdf), we can pull out some very relevant information. Right on the front page are some highlighted features of the sensor.

![TMP36 Feature List](https://github.com/queens-satellite-team/Space-School/blob/7a96f4cc5526eacf4cb35bf12e6b0ef8bec684fd/lab2/lab2-images/tmp36-features.png)

1. *Low Voltage Operation (2.7 to 5.5 V)* - This is the range of acceptable voltages that the sensor can be powered with. Arduino boards have both a 3V3 and a 5V0 output voltage so we can choose either one without worrying that it will break the sensor. 

2. *Calibrated right in °C* - This is good news! So our output will be analogous to a temperature reading in Celcius. We can expect that our output would be linear then. We then may not need any serious math involved to change our one time-varying signal to another. 

3. *10mV / C Scale Factor* - This is the conversion between voltage and temperature and can be thought of as the slope (m) between their linear relationship. So to convert one variable to another we use this scale factor, with perhaps plus or minus an offset (b) value. 

4. *±2 °C Accuracy over Temperature* This is how close the actual temperature is to what the sensor is reading. 

5. *±0.5 °C Linearity* - This is how close the sensor output will be to a linear equation. 

- As an aside, knowing the accuracy, precision, and linearity of our sensor determines which applications this sensor can be used for. However, it is more typical to start with outlining your required accuracy, precision, and linearity metrics first, then finding hardware to meet those requirements. 

6. *Specified –40 °C to +125 °C, Operation to +150 °C* This is our operating temperature range of the sensor. Going above or below may result in not just incorrect output readings but may damage the sensor as well. 

7. *Less than 50 uA Quiescent Current* This is the current draw when the device is not doing anything - when there is no output connection. 

8. *Low Self Heating* This is more than likely mentioned to say that the temperature of the sensor does not interfere with the sensor's own reading. 

Okay, great! So we have lots of information right from the start, there are just a few more pieces we need. The first is the pinout, and the second is the possible offset (b) value to the linear relationship. The pinout can be found on the first page again and is shown below alongside a photo of the physical sensor. 

![TMP36 Pinout V1](https://github.com/queens-satellite-team/Space-School/blob/bb1df16b5dcc6b585fb614fad82e5aceec367c11/lab2/lab2-images/tmp36-pinout-v1.png) ![TMP36 Pinout V2](https://github.com/queens-satellite-team/Space-School/blob/bb1df16b5dcc6b585fb614fad82e5aceec367c11/lab2/lab2-images/tmp36-pinout-v2.png)

To find the offset (b) value we want to look for a graph of the output characteristics of the sensor. Fortunately, what we are looking for exactly can be found on top of page 4. 

![tmp36-voltage-temp-conversion-chart](https://github.com/queens-satellite-team/Space-School/blob/85e73e4f4b51446189f5e0e27c2e8949096455b9/lab2/lab2-images/tmp36-voltage-temp-conversion-chart.png)

We can see that at 0C the ouput voltage will be 0V5 or 500mV. With this being our offset value, can you determine what the final conversion factor equation will look like? 


<details>
<summary> 📈 Click here to show the final equation!</summary>
<br>
⭐ Temperate C = [Vout in mV - 500mV] / (10mV / °C) ⭐
  
So for example, if the voltage out is 1V that means that the temperature is ((1000 mV - 500) / 10) = 50 °C
</details>

# Step 2 - Hardware Connections 
As we saw in the [datasheet](https://cdn-learn.adafruit.com/assets/assets/000/010/131/original/TMP35_36_37.pdf), the style of the TMP36 sensor we are using is the "TO-92" package. This means the chip is housed in a plastic semi-cylinder with three legs. The legs can be bent easily to allow the sensor to be plugged into a breadboard. You can also solder to the pins to connect long wires. 

These sensors have little chips in them and while they're not that delicate, they do need to be handled properly. Be careful of static electricity when handling them and make sure the power supply is connected up correctly and is between 2.7 and 5.5V DC - so don't try to use a 9V battery!

Remember that you can use anywhere between 2.7V and 5.5V as the power supply. For this example, I'm showing it with a 5V supply but note that you can use this with a 3.3v supply just as easily. No matter what supply you use, the analog output voltage reading will range from about 0V (ground) to about 1.75V. We can connect our sensor to the arduino board without any intermittent connections, so our basic hardware setup will be as follows: 

![TMP36 hardware setup v1](https://github.com/queens-satellite-team/Space-School/blob/b5f909abff8ab9da178e1989abed70ed6fba3ad8/lab2/lab2-images/tmp36-hw-setup-v1.0.png)

And that is it for our hardware requirements! Once you get comfortable with working with the sensor see if you can include an LED light that turns on at certain temperatures with a similar hardware and software setup as we made in [LAB 1](https://github.com/queens-satellite-team/Space-School/tree/main/lab1). 

## Step 2 - Analog Inputs
Before going forward with the software, we should take a moment to understand how the arduino board will interpret the voltage that it receives from the TMP36 sensor. The arduino uses an analog-to-digital converter (ADC) to map a continuous-time-varying variable such as voltage into what a machine can understand - a digital signal consisting of 0's and 1's. The arduino we are using has a 10-bit ADC. This means that depending on the voltage at the arduino's analog input, the ADC can produce a range of values from 0 all the way to 2^10 or 1024. So this means we have another conversion to do, for a total of two. We must convert the ADC 10-bit value to a voltage value, then this voltage value to a temperature value. We will keep this in mind going forward. 

# Step 3 - Software Implementation 
So let us begin writing some code! Open the text editor within Tinkercad and copy the lines of code shown below into your own monitor. Our first iteration will be to show what happens 

![TMP36 Software Setup v1](https://github.com/queens-satellite-team/Space-School/blob/30fa3adc33bb848d88b189a41a39b36e814525b6/lab2/lab2-images/tmp36-sw-setup-v1.0.png)

`Line 4: int sensor_pin = 0;`
- We want to assign a more readable name to the analog input pin on our arduino that we are using. This makes our code easier to read for us and for others, especially when we must revisit our code many months later. 

- This line is seperated as *data type* *variable name* = *value*. The equal sign does not really mean *equal* but more so *assign*. We assign the value of *0* to the variable *sensor_pin* of type *int*. Every variable will have a type, name, and a value. 
  
`Line 8: Serial.begin(9600);`
- Just like in lab 1, we want to open a communication link between the arduino board and the serial monitor. We set the baudrate to 9600 baud.

`Line 13: int analog_data = analogRead(sensor_pin);`
- In this line, we are calling the function *analogRead()*. At a high level, functions have input arguements, a name, and a return value. So in this line, the function name is *analogRead()*, the input arguement is a variable of type int with a value of (0 - 5) specifying the analog pin input, and has a return value of type int with a value of (0-1024). 

`Line 15: Serial.print("Analog Value: ");` 
 - This line sends the character string "Analog Value: " to the serial monitor.
 - 
`Line 16: Serial.println(analog_data);`

  
`Line 18: delay(100);` 
- This line pauses the arduino's execution of the code at this line for the number of milliseconds specified. In this case we are waiting for 1s between telling the arduino board to send another message.

# Step 4 - Verify Results 
This is where we beep boop and everything works! 

# Step 5 - Stretch Goal / Datasheet Examples 


