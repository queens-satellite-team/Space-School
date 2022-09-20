# Introduction

Hello! Welcome to the first lab of Space School! In this lab we will begin with getting the Arduino IDE up and running, then we will start exploring some of the different ways we can program our Arduino board to do some fun little actions for us. 

If you have any questions please feel free to reach out to Sydney Caulfeild, Thomas Sears, Emma Paczkowski, Sean Tedesco, or any other member of the QSAT Team. Contact info can be found at the main page of this repository. 

# Goals of Lab 1 

1️⃣  Setting up a working programming environment

2️⃣  Understanding the Arduino IDE

3️⃣  Building a blinky LED program and circuit

## What is an Arduino? 
An Arduino is a [microcontroller](https://www.youtube.com/watch?v=CqrQmQqpHXc), or a small computer than can perform instructions that we write. We can write a program - a series of instructions - that tells this small computer how it should interact with sensors, lights, and various input from human-users. We will be using these Arduinos as the on-board computer for our ToastSat, which is one of the six subsystems of our satellite. The basic parts of an Arduino Nano (the board you have today) are outlined below:

![Tour of the Arduino Nano](https://github.com/queens-satellite-team/Space-School/blob/main/lab01-getting-started-with-arduinos/lab1-images/arduino_nano_every_diagram.png)

Some key things to note:
- D stands for digital and A stands for analog. You can read more about signal types [here](https://learn.sparkfun.com/tutorials/analog-vs-digital/all).
- Notice hwere the USB connector is. This allows us to *upload* our set of instructions, or program, from our computer to the Arduino as well as supply power to it.

Note that we can also supply power to the Arduino through the power port with a battery. When the Arduino is powered this way, it will perform the program that was previously uploaded to it. Power configurations are shown below.

![USB Powered Arduino](https://github.com/queens-satellite-team/Space-School/blob/0c69e70192f59fa8af48e341d15ac462e6f01af3/lab1/lab1-images/arduino-powered-usb.jpeg) ![Battery Powered Arduino](https://github.com/queens-satellite-team/Space-School/blob/0c69e70192f59fa8af48e341d15ac462e6f01af3/lab1/lab1-images/arduino-powered-battery.jpeg)

# Step 1 - Setup Arduino IDE
The Arduino integrated development environment or [IDE](https://en.wikipedia.org/wiki/Integrated_development_environment) is a multipurpose toool to write the software and upload code to the arduino board. To get started download the required software from the [Arduino Download Page.](https://www.arduino.cc/en/software)

### Step 1.1 - Arduino IDE For Windows
1. In the blue box titled *Download Options* select *Windows Win 10 and newer*. 
2. You should get an .exe file. Open the file and the Arduino installer program will open. 
3. Select next on the liscence agreement. 
4. Make sure all *components to install* are selected, and click next. 
4. It is recemonded to keep the install directory as default, but feel free to change if neccessary. Then select install. 
6. Note: there maybe multiple *Windows Security* pop-ups, these are expected, just click on *accept* for each one. 
7. Once installed, you can delete the arduino.1.8.15-windows.exe from your downloads folder. 
8. Note: If you do not have Java you may need to install this as well. Java has a good walk through found [here.](https://java.com/en/download/help/download_options.html#windows)
9. You should now have a desktop icon for the Arduino IDE, click on this to start programming! 

### Step 1.1 - Arduino IDE For Macs 
1. In the blue box titled *Download Options* select *MacOS X 10.10 or newer*. 
2. Once downloaded, you should get a .zip file. 
3. Click on the downloaded file, and Mac should unzip it for you and place the Arduino IDE application in your *Downloads* folder. 
4. Note: If Mac does not automatiically unzip the file, you can right click and select *open*. 
5. Move the Arduino IDE application into your *Application* folder. 
6. Click on the Arduino IDE application to start programming! 

# Step 2 - Understanding the Arduino IDE  
Now welcome to the Arduino IDE! This is what your screen should look like now.

![Blank Arduino IDE](https://github.com/queens-satellite-team/Space-School/blob/79665e8ba8a807e1ad268ef5515d1499b6250be8/lab1/lab1-images/blank-arduino-ide.png)

The Arduino IDE has some important features: 

![Arduino IDE with Arrows Indicating IDE Functionality](https://github.com/queens-satellite-team/Space-School/blob/79665e8ba8a807e1ad268ef5515d1499b6250be8/lab1/lab1-images/ide-with-arrows.png)

Most noticeably is the *Verify* and *Upload* buttons located on the top left. The *Verify* button checks for any errors in your code (it will only check syntax errors though, not logical or procedural errors!) and the *Upload* button will upload the software into the hardware so the Arduino can operate as you specify in the code. 

# Step 3 - Blinky Test

## Step 3.1 - Blinky Hardware
We are going to be attaching all of our components on a breadboard. To understand how the holes in a breadboard are connected electrically, please see the diagram below. 

![Breadboard Connections](https://github.com/queens-satellite-team/Space-School/blob/main/lab01-getting-started-with-arduinos/lab1-images/breadboard_diagram.png)

Some things to note:
- The Arduino is limited to a 15 mA output current for each of it's input/output pins acording to the [specifications](https://docs.arduino.cc/hardware/nano-every) provided by Arduino. 
- As an optional exercise, determine the minimum size resistor to be included in this circuit! Note that we can approxiate that the LED will have a constant voltage drop of ~0.7V in this circuit. It is not expected that you know how to do this yet.

We are now going to connect our components on the breadboard using the diagram below as a reference.

Equipment:
- 1 Arduino Nano Every
- 1 breadboard
- 1 USB cable
- 1 220 ohm resistor
- 1 LED light
- 2 wires

Steps:
1. Connect your Arduino Nano Every to the breadboard.
2. Connect a wire from pin D12 (this pin was arbitrarily selected) to one end of your resistor.
3. Regarding the LED, these devices are polarity sensitive which means it matters which way you place it in the circuit. If you place it the wrong way the circuit will not work. The shorter leg of the LED is the cathode *(negative terminal)* and the longer leg is the anode *(positve terminal)*. Connect the anode to one end of the resistor.
4. Connect a wire from the cathode of your LED to the Arduion's ground pin.

Your setup should look something like this:

![Blinky Hardware Setup](https://github.com/queens-satellite-team/Space-School/blob/main/lab01-getting-started-with-arduinos/lab1-images/blinking_led_breadboard_ex.jpg)

## Step 3.2 - Blinky Software
1. Replace your code in the text box with the following. 

```
// Title:         Blinky Program
// Last Updated:  September 20th, 2022
// Author:        < your name here >
// Breif:         Simple program to make sure our hardware setup is working.  

void setup() {
  pinMode(12, OUTPUT);
}

void loop() {
  digitalWrite(12, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(12, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
```

Let us take a look at some of these new functions that we are using! 

`pinMode(12, OUTPUT);`
- This lets the Arduino know that we want to use pin 8 as an ouput. This function can set pins to either input or output and can assign any of the digital pins. 

`digitalWrite(12, HIGH);`
`digitalWrite(12, LOW);`
- This changes wether or not the specified pin has a high voltage (5V) or a low voltage (0V). The digital pins are limited to these high and low states, and are typically 5V ouputs unless specified. 

Again, more information regarding these and all the Arduino functions can be found [here](https://www.arduino.cc/reference/en/). This is a wonderful reference tool, and something to keep handy going forward.

2. Save your file with a name of your choice.

3. Go to Tools -> Board -> Boards Manager and install the package with the Arduino that your group has been given.

4. Verify your script using the Verify button in the top left corner. You should see a message "Done compiling" to indicate that it is complete as well as a message resembling:
```
Sketch uses 2838 bytes (5%) of program storage space. Maximum is 49152 bytes.
Global variables use 177 bytes (2%) of dynamic memory, leaving 5967 bytes for local variables. Maximum is 6144 bytes.
```

## Step 3.3 - Putting It All Together
1. Plug your Arduino into your computer using USB cable.

2. Go to Tools -> Port and select your board.

3. Upload your script using the Upload button in the top left corner. You should see a message "Done uploading".

4. You should now see your LED blinking!

