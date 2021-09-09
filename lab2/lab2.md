# Introduction

Hello! Welcome to the second lab of Space School! In this lab we will look at some programming basics including functions, datatypes, and conditional statements in order to get an arduino to communicate with a sensor! We will also start getting comfortable with looking at datasheets as these guide both our hardware and software implementation. In this lab we will be working with the **TMP36** temperature sensor.

With respect, the majority of this lab was sourced by creater Lady Ada's [TMP36 Temperature Sensor Documentation](https://cdn-learn.adafruit.com/downloads/pdf/tmp36-temperature-sensor.pdf) from The Adafruit Learning System. If you have any questions regarding this lab or just want to reach out, please feel free to speak to Thomas Sears, Emma Paczkowski, Kate Szabo, Piper Steffen, Sean Tedesco, or any other member of the QSAT Team. Contact info can be found at the bottom of the lab. 

# Step 1 - Overview and Datasheet 
The TMP36 is an analog temperature sensor - it is a chip that tells you what the ambient temperature is! *As an aside, an analog signal is a continous signal where one time-varying variable represents another time varying variable. We say that the first time-varying signal is analogous to the other. In this lab, we will have a  voltage measurement that is analogous to temperature.*

![TMP36 Next to a Coin](https://github.com/queens-satellite-team/Space-School/blob/01efedf88740647ccd69433bf9f45f66f0af0abe/lab2/lab2-images/tmp36-overview.jpeg)

Back to our sensor! So long the days of [mercury](https://en.wikipedia.org/wiki/Mercury-in-glass_thermometer) rising with the heat; so long the days of [bimetallic](https://en.wikipedia.org/wiki/Bimetallic_strip) strips; so long the days where we must use [temperature dependent resistors](https://en.wikipedia.org/wiki/Thermistor) to tell the temperature. These TMP36 sensors use a solid-state technique to determine the temperature. They use the fact as temperature increases, the voltage across a diode increases at a known rate. By precisely amplifying the voltage change, it is easy to generate an analog signal that is directly proportional to temperature.

So let's look at some characteristics of our sensor now. Looking at the [datasheet](https://cdn-learn.adafruit.com/assets/assets/000/010/131/original/TMP35_36_37.pdf), we can pull out some very relevant information. Right on the front page are some highlighted features of the sensor.

![TMP36 Feature List](https://github.com/queens-satellite-team/Space-School/blob/7a96f4cc5526eacf4cb35bf12e6b0ef8bec684fd/lab2/lab2-images/tmp36-features.png)

1. *Low Voltage Operation (2.7 to 5.5 V)* - This is the range of acceptable voltages that the sensor can be powered with. Arduino boards have both a 3V3 and a 5V0 ouput voltage so we can choose either one without worrying that it will break the sensor. 

2. *Callibrated right in °C* - This is good news! So our output will be analogous to a temperature reading in Celcius. We can expect that our ouput would be linear then. We then may not need any serious math involved to change our one time-varying signal to another. 

3. *10mV / C Scale Factor* - This is the conversion between voltage and temperature and can be thought of as the slope (m) between their linear relationship. So to convert to one variable to another we use this scale factor, with perhaps plus or minus an offset (b) value. 

4. *±2 °C Accuracy over Temperature* This is how close the actual temperature is to what the sensor is reading. 

5. *±0.5 °C Linearity* - This is how close the sensor output will be to a linear equation. 

- As an aside, knowing the accuracing, precision, and the linearity of our sensor determines which applications this sensor can be used for. However, it is more typicall to start with outlining your required accuracy, precision, and linearity metrics first, then finding hardware to meet those requirements. 

6. *Specified –40 °C to +125 °C, Operation to +150 °C* This is our operating temperature range of the sensor. Going above or below may result in not just incorrect output readings but may damage the sensor as well. 

7. *Less than 50 uA Quiescent Current* This is the current draw when the device is not doing anything - when there is no output connection. 

8. *Low Self Heating* This is more than likely mentioned to say that the temperature of the sesnor does not interfere with the sensor's own reading. 

Okay, great! So we have lots of information right from the start, there are just a few more pieces we need. The first is the pinout, and the second is the possible offset (b) value to the linear relationship. The pinout can be found on the first page again and is shown below alongside a photo of the physical sensor. 

![TMP36 Pinout V1](https://github.com/queens-satellite-team/Space-School/blob/bb1df16b5dcc6b585fb614fad82e5aceec367c11/lab2/lab2-images/tmp36-pinout-v1.png) ![TMP36 Pinout V2](https://github.com/queens-satellite-team/Space-School/blob/bb1df16b5dcc6b585fb614fad82e5aceec367c11/lab2/lab2-images/tmp36-pinout-v2.png)

To find the offset (b) value we want to look for a graph of the output characteristics of the sensor. Fortunately, what we are looking for exactly can be found on top of page 4. 

![tmp36-voltage-temp-conversion-chart](https://github.com/queens-satellite-team/Space-School/blob/85e73e4f4b51446189f5e0e27c2e8949096455b9/lab2/lab2-images/tmp36-voltage-temp-conversion-chart.png)

We can see that at 0C the ouput voltage will be 0V5 or 500mV. This will be our offset value and our final conversion equation will look like:

**Temperate C = [Vout in mV - 500mV] / (10mV / °C)** 

So for example, if the voltage out is 1V that means that the temperature is ((1000 mV - 500) / 10) = 50 °C

# Step 2 - Hardware Connections 
As we saw in the [datasheet](https://cdn-learn.adafruit.com/assets/assets/000/010/131/original/TMP35_36_37.pdf), the style of the TMP36 sensor we are using is the "TO-92" package. This means the chip is housed in a plastic hemi-cylinder with three legs. The legs can be bent easily to allow the sensor to be plugged into a breadboard. You can also solder to the pins to connect long wires. 

# Step 3 - Software Implementation 
This is where we boop. 

# Step 4 - Verify Results 
This is where we beep boop and everything works! 

# Step 5 - Datasheet Examples 

# Contact Info 

Thomas Sears: thomas.sears@queensu.ca

Emma Paczkowski: emma.paczkowski@queensu.ca

Kate Szabo: kate.szabo@queensu.ca

Piper Steffen: 16pis@queensu.ca

Sean Tedesco: 17sart@queensu.ca
