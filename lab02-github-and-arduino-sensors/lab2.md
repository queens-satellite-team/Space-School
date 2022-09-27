# Goals of Lab 2

1️⃣  Read values from a temperature sensor on your Arduino.

2️⃣  Understand the basics and benefits of GitHub. Start your first repository and upload your code using Git.

# Part 1: Temperature Sensors and Arduino

## Step 1.0 - TMP36 Overview
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

## Step 2 - Hardware Connections 
As we saw in the [datasheet](https://cdn-learn.adafruit.com/assets/assets/000/010/131/original/TMP35_36_37.pdf), the style of the TMP36 sensor we are using is the "TO-92" package. This means the chip is housed in a plastic semi-cylinder with three legs. The legs can be bent easily to allow the sensor to be plugged into a breadboard. 

These sensors have little chips in them and while they're not that delicate, they do need to be handled properly. Be careful of [static electricity](https://en.wikipedia.org/wiki/Electrostatic_discharge) when handling them and make sure the power supply is connected correctly.

Remember that you can use anywhere between 2.7V and 5.5V as the power supply. For this example, I'm showing it with a 5V supply but note that you can use this with a 3.3v supply just as easily. No matter what supply you use, the analog output voltage reading will range from about 0V (ground) to about 1.75V. We can connect our sensor to the arduino board without any intermittent connections, so our basic hardware setup will be as follows: 

![TMP36 hardware setup v1](https://github.com/queens-satellite-team/Space-School/blob/labs_in_progress/lab02-github-and-arduino-sensors/tmp36_arduino.png)

Please recreate this using your Arduino, and that will be it for our hardware requirements! Please note that this diagram is of an Arduino Uno, so you're going to need to look up the pins for an Arduino Nano Every. 

### 2.1 - Analog Inputs
Before going forward with the software, we should take a moment to understand how the arduino board will interpret the voltage that it receives from the TMP36 sensor. The arduino uses an analog-to-digital converter or an [ADC](https://en.wikipedia.org/wiki/Analog-to-digital_converter) to convert the output of the sensor to something the microcontroller can understand. The microcontroller has an ADC to convert a *continuous real number* such as a voltage of 0.65418... volts to something that is a *discrete natural number* like a series of 0s and 1s. This means we have a second conversion or mapping to do. We must first convert temperature to a voltage, then we must convert the voltage into a digit. We will look at this more in Step 3.

## Step 3 - Software Implementation 
So let us begin writing some code! Open the text editor and copy the lines of code shown below into your own monitor. Our first iteration will be to show what happens when we only read the anlog input with no conversion and no mapping. 

### 3.1 Analog Input Reading

```
// Title:         TMP36 Read Temperature Program
// Last Updated:  September 29th, 2021
// Author:        < your name here >
// Breif:         Simple program that reads the input of an analog pin.   

int sensor_pin = 0;
int analog_data;

void setup() {
  Serial.begin(9600);
}

void loop() {

  analog_data = analogRead(sensor_pin);
  
  Serial.print("Analog Value: ");
  Serial.println(analog_data);
 
  delay(100);
}
```

`int sensor_pin = 0;`
- We want to assign a more readable name to the analog input pin on our arduino that we are using. This makes our code easier to read for us and for others, especially when we must revisit our code many months later. 

- This line is seperated as *data type* *variable name* = *value*. The equal sign does not really mean *equal* but more so *assign*. We assign the value of *0* to the variable *sensor_pin* of type *int*. Every variable will have a type, name, and a value. Specifying the variable type tells the microcontroller two things: 1) how much memory the microcontroller needs to set aside for this variable and 2) how the microcontroller should represent and handle this variable.

`int analog_data;`
- Similiar to what we did with the variable sensor_pin we want to have the variables we use throughout the program stated uptop so that it is easier to read lower down. Here we are declaring a variable called *analog_data* of type *int*. It is okay that we do not assign a value to it yet as we will do so in our main *loop()*.
  
`Serial.begin(9600);`
- Just like in lab 1, we want to open a communication connection between the arduino board and the serial monitor. This way we can see any output messages from the arduino such as our temperature data. 

`analog_data = analogRead(sensor_pin);`
- In this line, we are calling the function *analogRead()*. At a high level, functions have input arguements, a name, and a return value. So in this line, the function name is *analogRead()*, the input arguement is a variable with a value of (0,1,2,3,4, or 5) specifying which one of the six analog pins that the Arduino has that we will be using, and has a return value of a number between 0 and 1024. 

`Serial.print("Analog Value: ");` 
 - Just like we saw in LAB 1, we are able to print whatever is in the qoutes to our serial monitor. If working with a real arduino board, it will send this message from the arduino to your computer. In this line we send the character string "Analog Value: " to the serial monitor.
 
`Serial.println(analog_data);`
- Notice the difference between *Serial.println("");* and *Serial.print("")*? When we use the function with the extra -ln in the name this moves whatever is to be printed next to a new line underneath the current line. It adds a newline character '/n' to the end of what is printed. 

`delay(100);` 
- The delay pauses the arduino's execution of the code at this line for the number of milliseconds specified. In this case we are waiting for 0.1s between telling the arduino board to continue. 

1. Click Start Simulation
2. Open the serial monitor and observe the values (Tools -> Serial Monitor). 

❓ Does the value we print to the serial monitor match the temperature of the TMP36? If this was a voltage, would that seem pretty high? 

❓ What is missing so we can print the correct temperature value? 

❓ Where in our code do we include that? 

### 3.2 Including Conversion Factor
Let's now include the conversion factor we found by looking through the datasheet in the previous sections. We can keep the main structure of our code and just improve upon it. In the text editor copy the lines of code shown below into your own monitor.

```
// Title:         TMP36 Read Temperature Program
// Last Updated:  September 29th, 2021
// Author:        < your name here >
// Breif:         Simple program that reads the input of an analog pin and tries to ouput a correct temperature value.

// analog pin
int sensor_pin = 0;

int analog_data;
float temperatureC; 
  
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // read the analog input
  analog_data = analogRead(sensor_pin);
  
  // convert analog input to a temperature value
  temperatureC = (analog_data - 0.5) * 100; 
  
  // print out our values 
  Serial.print("Analog Value: ");
  Serial.println(analog_data);
  
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");
  Serial.println("");
  
  delay(1000); 
}
```

`float temperatureC; ` 
- Similiar to what we did with the variable *analog_data* we want to have the variables we use throughout the program stated uptop so that it is easier to read lower down. Here we are declaring a variable called *temperatureC* of type *float*. The float type lets us store floating point numbers, or numbers with a decimal / fractional part. 

`temperatureC = (analog_data - 0.5) * 100;`
- This is the same conversion factor we found above, but expressed in volts. We are converting from 10 mV per degree C with a 500 mV offset to degree C. 

We started with `Temperate C = [Vout in mV - 500mV] / (10mV / °C)` and converted 1) Vout = analog_data, 2) 500 mV = 0.5V, 3) 1 / (10mV / °C) = 1°C / 10 mV = 1°C / 0.010 V = 100°C / 1V to get the following `temperatureC = (analog_data - 0.5) * 100`.

1. Click Start Simulation
2. Open the serial monitor and observe the values. 

❓ Does the value we print to the serial monitor match the temperature of the TMP36?

❓ What is missing so we can print the correct temperature value? 

❓ Where in our code do we include that? 


### 3.3 Including ADC Mapping
Now let us include both the conversion factor and the ADC mapping and see if we can get a value that is reflective of the actual temperature. In the text editor copy the lines of code shown below into your own monitor.

```
// Title:         TMP36 Read Temperature Program
// Last Updated:  September 29th, 2021
// Author:        < your name here >
// Breif:         Simple program that reads the input of an analog pin and ouputs the temperature value.

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
```

`voltage_reading = analog_data * (5.0/1024.0);`
As stated in section 2.1, when we use the analog inputs we have to map the maximum voltage the sensor can have to the maximum value that the ADC can have. We can do this with a simple ratio shown below. This means that if we get a value from our ADC that is 1024 we know there will be 5.0 volts at the input pin; if we have a value from our ADC that is 0, we know there will be 0.0 volts at the input pin; and if we have something inbetween 1024 and 0, let us say 278, we know it will be some value between 5.0 and 0.0 volts. 


```
  5.0 V      voltage_reading
  -----  =  ----------------
  1024       analog_data
```



1. Click Start Simulation
2. Open the serial monitor and observe the values. 

![final temperature reading](https://github.com/queens-satellite-team/Space-School/blob/3577567d6b1087e243e1dc69c2789a75a1a7469c/lab2/lab2-images/temperature_reading.png)

❓ Does the value we print to the serial monitor match the temperature of the TMP36?

❓ If they are different, why? 

Congratulations! You have sucessfully installed a sensor, used that sensor to produce an ouput voltage acording to the ambient temperature, converted that output voltage to a digital value, and display it to a human user. That is pretty sweet! Please feel free to try out some of the stretch goals and read though the extra information section if you are curious. 

## Step 4 - Stretch Goals 

### 4.1 LED Indicator 
Once you get comfortable with working with the sensor see if you can include an LED light that turns on within a certain temperature range, and another LED that turns on at a different temperature range. For example, turn on a RED LED and off a BLUE LED when the temperature is greater than or equal to 20 °C, and turn off a RED LED and turn on a BLUE LED when the temperature is less than 20 °C. 

🛠️ Hardware Consideration: We can use a similar hardware and software setup as we made in [LAB 1](https://github.com/queens-satellite-team/Space-School/tree/main/lab1) to get the LED powered. 

💻 Software Consideration: You will need to include some [conditional statements](https://www.geeksforgeeks.org/decision-making-c-c-else-nested-else/) to implement the decision making of turning on and off the LEDs. 

### 4.2 Multiple Inputs 
The temperature reading within a satellite may be different depending on the sensor's location. It may read warmer values closer to the battery, and microcontroller, while lower values closer to the outside structure. See if you can read values from multiple sensors at a time. Can you include some math in your code to average the results? How can you do this with the least amount of wiring? 

🛠️ Hardware Consideration: Repeat the same steps in this lab to build the hardware connections for the sensor. Can you use the same power and ground lines for multiple sensors? Do you need a seperate analog input pin for each connected sensor on the arduino?

💻 Software Consideration: Figuring out how best to display the results is important when you are reading values from multiple sources. We know that we can print characters and values to the serial monitor using the arduino function `Serial.print(" ");`, so see if you can display the input of the multiple sensors with where that sensor may be located. As an example:

```
Battery Temp: 28.5 °C
Microcontroller Temp: 32 °C
Outside Temp: 18 °C

Average Temp: 26.2 °C
```

⚠️ Warning ⚠️ Using multiple analog sensors may lead to them interfering with eachother providing inconsistent readings. Some relevant discussions can be found [here](https://forums.adafruit.com/viewtopic.php?f=25&t=11597) and [here](https://forums.adafruit.com/viewtopic.php?f=25&t=14332).

### 4.3 Datasheet Examples
Look through the remaining pages of the [datasheet](https://cdn-learn.adafruit.com/assets/assets/000/010/131/original/TMP35_36_37.pdf) and find some of the cool examples that it provides. These are out of the scope for Space School, as well as 1st and 2nd year engineering, but it is still cool to see some of the differenet applications these sensors can be put through.

### Extra Information 

<details>
<summary>❗ Extra Information on Analog Inputs</summary>
<br>

1. If we have 2 types of digits, such that each digit may have a value of 0 or 1, then we call this a binary number. We call each one of the digits a bit, so that if we have a binary number that is 10 digits long we can say this a 10-bit binary number. For our 10-bit ADC, the smallest value it can take on is 0000000000 and the largest is 1111111111. This means that if we have a number that has 2 types of digits and a maximum length of 10 different digits, we may have 2^10 = 1024 unique values of 0s and 1s. This means that no matter what the input is to the ADC it can only output a finite range of values including the number 0 to 1023. 

2. The arduino we are using has a 10-bit ADC. This means that when the ADC reads an analog input it can convert it to a digital value that is 10 digits long and each digit may have a value of 0 or 1. The digital value can be any discrete value in the range of 0000000000, 0000000001, 0000000010, 0000000011, 0000000100, 0000000101, ..., 1111111110, 1111111111. We can say that the value of 0000000000 can represent a voltage of 0 V, and a value of 1111111111 represents our maximum voltage (5.0 V or 3.3 V). However the ADC does not know what our maximum voltage is, so we must map this maximum voltage value to the maximum 10-bit ADC value. The maximum voltage will be our supply of 5.0 or 3.3 volts and the maximum 10-bit ADC value is 1024. Thus our conversion will be:

⭐ Voltage at analog pin in milliVolts = (reading from ADC) * (maxSuppliedVoltage/1024) ⭐
</details>

<details>
<summary> ❗ Extra Information on Data Types</summary>
<br>
Specifying the variable type tells the microcontroller two things: 1) how much memory the microcontroller needs to set aside for this variable and 2) how the microcontroller should represent and handle this variable. For example we can look at the digit of 9 and compare it to the character of 9. 

  <b> DIGIT </b> 
  
int my_variable = 9;
  
  When we specify a variable as an <i>int</i>, this is a numerical value. We can perform math operations on it. However, ints take up more memory than a character.
  
  <b> CHARACTER </b> 
  
char my_variable = '9'; 
  
  When we specify a variable as an <i>char</i>, this is a character value. It is like a written letter that can be combined with other characters to make a word, or a <i>string</i>
  
</details>

# Part 2: Using GitHub

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
- **Branch:** branches allow you to develop features, fix bugs, or safely experiment with new ideas in a contained area of your repository. Each repository has one default branch, and can have multiple other branches. The motivation is that say you have finished all your code, but you want to try out a different approach. You don't want to lose your original working copy incase the new approach doesn't work. To avoid this, you could make a branch (or a copy) of your working version and start working here. That way your original version stays untouched. If you like the new version you can merge them together. How many branches does this repository have?
![github branch](https://github.com/queens-satellite-team/Space-School/blob/labs_in_progress/lab02-github-and-arduino-sensors/lab2-images/branch_github.png)

Important Git commands:
- **Add:** The git add command adds a change in your working directory to the staging area. When you make changes to a file, these changes are "untracked", so you need to add them to the staging area. The staging area contains files that are going to be part of the next commit.
- **Commit:** You can save small groups of meaningful changes as commits. Similar to saving a file that's been edited, a commit records changes to one or more files in your branch. Git assigns each commit a unique ID, called a SHA or hash, that identifies the specific changes, when the changes were made, and who created the changes.
- **Push:** The git push command is used to upload local repository content (i.e. what you are working on) to a remote repository (in our case GitHub).
- **Pull:** If someone else has modified your code and uploaded it to GitHub, your local version will be out of date. This means you need to "pull" these new changes to your local working directory, so you use the pull command.

We are not going to be using GitHub to it's full potential in Space School; we just want you to get familiar with the UI and start a repository. However, if you are interested in learning more, here are some useful and quick tutorials:
- https://github.com/skills/introduction-to-github (~1 hour)
- https://docs.github.com/en/get-started/quickstart/hello-world

## Uploading Your Code

### Step 1 - Create a repository
- go to GitHub and click on your account icon -> Your Repositores. 
- click "New".
- Enter a Repository Name of your choosing (ex. qset-space-school).
- Leave the repository as Public.
- Select "Add a README file". We will not be filling that in today but if you're interested in learning markdown I recommend you add to this file describing what this repo is for (i.e. you are a student working on an engineering design team at Queen's and these are your projects).
- Click "Create repository".

### Step 2 - Download Git
- Go to https://git-scm.com/downloads and download Git.
- Once installed, open Git Bash. This is the command line you will be using to upload your changes to GitHub.
- Run `git config --global user.name "FIRST_NAME LAST_NAME"` and `git config --global user.email "MY_NAME@example.com"` to set your name and email.

### Step 3 - Team member with the script clones the repository
Now that you have a _remote_ repository on GitHub, you want to clone it to your local work station. 
The following steps should be done on the computer of the person who has the Arduino Script:
- You need to navigate to the parent folder of your Arduino script. You can do this by using `ls` to see which folder you are in right now, and `cd` to Change Directory into a directory that you want. `cd ../` goes up to the parent directory. For example, if I am in "Documents" and I want to move into a folder called "QSET", I would enter `cd QSET`.
- Open the repository you just made on GitHub. Click the green "Code" button and copy the HTTPS link under "Clone".
- Go back to Git Bash, and in your folder enter `git clone <URL>` (without the <>).
- Once this is complete, if you run `ls` you should now see your repository in your local folder!

### Step 4 - Add your code to the repository
Now we want to add our changes to the repo.
- Move your script using the `mv` command (as shown in the demo) into your repository.
- `cd` into your repository (`cd <repo_name>`).
- Enter `git status` to see what your untracked changes are. You should see your new script.
- Run `git add <script_name>`.
- Run `git commit -m "Adding Arduino script to measure the temperature with a TMP36 sensor."`
- Run `git push`.
- Go to your repository on GitHub and refresh the page. You should now see your Arduino script! Take a minute to look for your commit of this file.

### Step 5 - Add your teammates as collaborators
- Go to your repository on GitHub and go to Settings.
- Under "Access" click on "Collaborators and teams".
- Select "Add People" and add your teammates.

### Step 6 - Teammates clone the repo
- Follow the same cloning instructions as above.
- You should now also see the repo in your local folder that now has the Arduino script!
