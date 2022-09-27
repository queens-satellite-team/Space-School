# Goals of Lab 2

1️⃣  Read values from a temperature sensor on your Arduino.

2️⃣  Understand the basics and benefits of GitHub. Start your first repository and upload your code using Git.

## Part 1: Temperature Sensors and Arduino

### Step 1.0 - TMP36 Overview
Our goal is to read the ambient temperature of our payload using a sensor. We can do this by using the TMP36 temperature sensor, which is an analog electronic device. In Step 1, we will figure out what exactly that means, and what are the characteristics of this sensor.

### 1.1 Analog vs. Digital Signals
Working with electronics means dealing with both analog and digital signals, inputs and outputs. Our electronics projects have to interact with the real, analog world in some way, but most of our microprocessors, and computers are purely digital components. So lets define what we mean by [signal](https://en.wikipedia.org/wiki/Signal), [digital](https://en.wikipedia.org/wiki/Digital_signal), and [analog](https://en.wikipedia.org/wiki/Analog_signal). Before clicking on the dropdowns below, can you think of your own definitions of signal, digital, and analog (looking at the graphs below might help)? 

<details>
<summary> <b>Definition of Signal</b> </summary>
<br>
- a thing that can convey information and that can change with time.
</details>

<details>
<summary> <b>Definition of Digital</b> </summary>
<br>
- a discrete signal that can only take on one value at any given time, such as LOW, MEDIUM, or HIGH.
</details>

<details>
<summary> <b>Definition of Analog</b> </summary>
<br>
  - a continuous signal that at any given time represents a <i>real number</i> within a continuous range of values. Analog signals represents physical measurements, such as a light level of 1.236 <a href="https://en.wikipedia.org/wiki/Lumen_(unit)">lumens</a>. 
</details>

**DIGITAL SIGNAL**

![digitla_circuit](https://github.com/queens-satellite-team/Space-School/blob/05136f902023ba22127d2734c8aa126bb90d718e/lab2/lab2-images/digital_signal.png) 

**ANALOG SIGNAL**

![analog_circuit](https://github.com/queens-satellite-team/Space-School/blob/05136f902023ba22127d2734c8aa126bb90d718e/lab2/lab2-images/analog_signal.png)

So a good way to think of the difference between these two signals in an electrical engineering context is that a digital signal will turn ON and OFF an LED, but an analog signal will DIM the led making it a litter more or less bright. Fortunately our Arduino microcontroller has both digital and analog inputs and outputs, so we just have to figure out how to use them! (Pins on the Arduino diagram we have shown start with either D or A which indicates whether the signals are digital or analog).

❓ What are some other things you may want to measure using your toastSat that is going 30km into the atmoshere? 

❓ Are these measurements digital or analog?

### 1.2 Datasheet

Back to our sensor! So long the days of [mercury](https://en.wikipedia.org/wiki/Mercury-in-glass_thermometer) rising with the heat; so long the days of [bimetallic](https://en.wikipedia.org/wiki/Bimetallic_strip) strips; so long the days where we must use [temperature dependent resistors](https://en.wikipedia.org/wiki/Thermistor) to tell the temperature. These TMP36 sensors use a [solid-state technique](https://en.wikipedia.org/wiki/Solid-state_electronics) to determine the temperature. The technique is that as the ambient temperature increases, the voltage that apears across a diode (a solid-state device) increases at a known rate. We can then amplify this changing voltage to generate an analog signal that is directly proportional to temperature. That is the theory behind the sesnor, now let us look at it's characteristics as described winthin the [datasheet](https://cdn-learn.adafruit.com/assets/assets/000/010/131/original/TMP35_36_37.pdf).

![datasheet_frontpage](https://github.com/queens-satellite-team/Space-School/blob/1a2413b577641644c7a343283376942bbd899678/lab2/lab2-images/datasheet_frontpage.png)

We can get a good understanding of how to turn on our device, how it operates, and the conditions that the sensor can operate safely in all by looking at the [datasheet](https://cdn-learn.adafruit.com/assets/assets/000/010/131/original/TMP35_36_37.pdf). We will go through this document and pull out some relevant information. Right on the front page are some highlighted features of the sensor! 

❓ Can you find some of these important features before clicking on the dropdowns? 

#### 1.2.1 Features 

<details>
<summary> <b>Feature One</b> </summary>
<br>
<b><i>Low Voltage Operation (2.7 to 5.5 V)</i></b> - This is the range of acceptable voltages that the sensor can be powered with. Arduino boards have both a 3V3 and a 5V0 output voltage so we can choose either one without worrying that it will break the sensor. Just do not power this on with a 9V battery! 
</details>

<details>
<summary> <b>Feature Two</b> </summary>
<br>
<b><i>Calibrated right in °C</i></b> - This is good news! So our output will be analogous to a temperature reading in Celcius. We can expect that our output would be linear then. We then may not need any serious math involved to change our one time-varying signal to another. 
</details>

<details>
<summary> <b>Feature Three</b> </summary>
<br>
<b><i>10mV / C Scale Factor</i></b> - This is the conversion between voltage and temperature and can be thought of as the slope (m) between their linear relationship. So to convert one variable to another we use this scale factor, with perhaps plus or minus an offset (b) value.
</details>

<details>
<summary> <b>Feature Four</b> </summary>
<br>
<b><i>±2 °C Accuracy over Temperature</i></b> - This is how close the actual temperature is to what the sensor is reading. 
</details>

<details>
<summary><b>Feature Five</b></summary>
<br>
<b><i>±0.5 °C Linearity</i></b> - This is how close the sensor output will be to a linear equation. 
</details>

<details>
<summary><b>Feature Six</b></summary>
<br>
<b><i>Specified –40 °C to +125 °C, Operation to +150 °C</i></b> - This is our operating temperature range of the sensor. Going above or below may result in not just incorrect output readings but may damage the sensor as well. 
</details>

<details>
<summary><b>Feature Seven</b></summary>
<br>
<b><i>Less than 50 uA Quiescent Current</i></b> - This is the current draw when the device is not doing anything - when there is no output connection.
</details>

<details>
<summary><b>Feature Eight</b></summary>
<br>
<b><i>Low Self Heating</i></b> - This is more than likely mentioned to say that the temperature of the sensor does not interfere with the sensor's own reading. 
</details>

_As an aside, knowing the accuracy, precision, and linearity of our sensor determines which applications this sensor can be used for. However, it is more typical to start with outlining your required accuracy, precision, and linearity metrics first, then finding hardware to meet those requirements._

#### 1.2.2 Pin Connections 

Okay, great! So we have lots of information right from the start, there are just a few more pieces we need. The first is the pinout. This is a description of the functionality of each of a device's connection points. Knowing the pinout of a device makes sure we are connecting power to power, ground to ground, and the inputs and outputs are connected properly. The pinout can be found on the first page again and is shown below alongside a photo of the physical sensor. 

![TMP36 Pinout V1](https://github.com/queens-satellite-team/Space-School/blob/bb1df16b5dcc6b585fb614fad82e5aceec367c11/lab2/lab2-images/tmp36-pinout-v1.png) ![TMP36 Pinout V2](https://github.com/queens-satellite-team/Space-School/blob/bb1df16b5dcc6b585fb614fad82e5aceec367c11/lab2/lab2-images/tmp36-pinout-v2.png)

#### 1.2.3 Voltage to Temperature Equation
We know that this sensor has a linear relationship between its input and output. This means that we can model the input and output by the equation `y = mx + b`, where y is the temperature in °C and x is the output voltage (Vout) of the sensor. We know from looking at the datasheet that our (m) value will be (10mV / 1°C), so all we are left is to determine our offset or (b) value. 

To find the offset (b) value we want to look for a graph of the output characteristics of the sensor. Fortunately, what we are looking for exactly can be found on top of page 4 of the [datasheet](https://cdn-learn.adafruit.com/assets/assets/000/010/131/original/TMP35_36_37.pdf). 

![tmp36-voltage-temp-conversion-chart](https://github.com/queens-satellite-team/Space-School/blob/85e73e4f4b51446189f5e0e27c2e8949096455b9/lab2/lab2-images/tmp36-voltage-temp-conversion-chart.png)

❓ We can see that at 0 °C the ouput voltage will be 0.5 V or 500mV. With this being our offset value, and knowing our (m) value, can you determine what the final conversion factor equation will look like? 

<details>
<summary> 📈 Click here to show the final equation!</summary>
<br>
⭐ Temperate C = [Vout in mV - 500mV] / (10mV / 1 °C) ⭐
  
So for example, if the voltage out is 1V that means that the temperature is ((1000 mV - 500 mV) / 10 mV / °C) = 50 °C
</details>

# Step 2 - Hardware Connections 
As we saw in the [datasheet](https://cdn-learn.adafruit.com/assets/assets/000/010/131/original/TMP35_36_37.pdf), the style of the TMP36 sensor we are using is the "TO-92" package. This means the chip is housed in a plastic semi-cylinder with three legs. The legs can be bent easily to allow the sensor to be plugged into a breadboard. 

These sensors have little chips in them and while they're not that delicate, they do need to be handled properly. Be careful of [static electricity](https://en.wikipedia.org/wiki/Electrostatic_discharge) when handling them and make sure the power supply is connected correctly.

Remember that you can use anywhere between 2.7V and 5.5V as the power supply. For this example, I'm showing it with a 5V supply but note that you can use this with a 3.3v supply just as easily. No matter what supply you use, the analog output voltage reading will range from about 0V (ground) to about 1.75V. We can connect our sensor to the arduino board without any intermittent connections, so our basic hardware setup will be as follows: 

![TMP36 hardware setup v1](https://github.com/queens-satellite-team/Space-School/blob/labs_in_progress/lab02-github-and-arduino-sensors/tmp36_arduino.png)

Please recreate this in your own Tinkercad dashboard, and that will be it for our hardware requirements! 

## 2.1 - Analog Inputs
Before going forward with the software, we should take a moment to understand how the arduino board will interpret the voltage that it receives from the TMP36 sensor. The arduino uses an analog-to-digital converter or an [ADC](https://en.wikipedia.org/wiki/Analog-to-digital_converter) to convert the output of the sensor to something the microcontroller can understand. The microcontroller has an ADC to convert a *continuous real number* such as a voltage of 0.65418... volts to something that is a *discrete natural number* like a series of 0s and 1s. This means we have a second conversion or mapping to do. We must first convert temperature to a voltage, then we must convert the voltage into a digit. We will look at this more in Step 3.

## Part 2: Using GitHub

GitHub. Is. Amazing. Become friends with it now, and you can thank me later:) 

Here are some reasons GitHub is amazing:
- it stores your code online so you can access it from anywhere and easily collaborate with others.
- it allows for version control.
- it is a REALLY great thing to have for your resume. You can think of it as a personal portfolio of projects you have worked on. (We'll be adding your first one today!)
- it has tons of project management features (Issues, Tasks, etc.).

Some important definitions:
- **GitHub:** is an Internet hosting service for software development and version control. It provides the version control of Git plus access control, bug tracking, software feature requests, task management, continuous integration, and wikis for every project.
- **Git:** software for version control: tracking changes in files, usually used for coordinating work among programmers collaboratively developing source code.
- **Markdown:** a language that uses plain text formatting but contains inline text symbols that specify how to format the text. ".md" indicates that a file is written with markdown. Think of it as a fancy text file!
- **ReadMe:** a ReadMe file contains information about the other files in the directory. It is usually a plain text file called readme.md.
- **Repository:** a repository contains all of your project's files and each file's revision history. You can think of it as a folder.
- **Branch:** branches allow you to develop features, fix bugs, or safely experiment with new ideas in a contained area of your repository. Each repository has one default branch, and can have multiple other branches. How many branches does this repository have?
- **Commit:** You can save small groups of meaningful changes as commits. Similar to saving a file that's been edited, a commit records changes to one or more files in your branch. Git assigns each commit a unique ID, called a SHA or hash, that identifies the specific changes, when the changes were made, and who created the changes.

We are not going to be using GitHub to it's full potential in Space School; we just want you to get familiar with the UI and start a repository. However, if you are interested in learning more, here are some useful and quick tutorials:
- https://github.com/skills/introduction-to-github (~1 hour)
- https://docs.github.com/en/get-started/quickstart/hello-world
