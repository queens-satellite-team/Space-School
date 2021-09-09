# Introduction

Hello! Welcome to the first lab of Space School! In this lab we will begin with getting the Arduino IDE up and running, then we will start exploring some of the different ways we can program our Arduino board to do some fun little actions for us. 

If you have any questions please feel free to reach out to Thomas Sears, Emma Paczkowski, Kate Szabo, Piper Steffen, Sean Tedesco, or any other member of the QSAT Team. Contact info can be found at the bottom of the lab. 

# Step 1 - Setting up TinkerCad
We can simulate the Arduino hardware with a program called Tinkercad. To begin working with Tinkercad, we first need to sign up for an acount. Go to the [main page](https://www.tinkercad.com) of tinker card and select the log-in button. 

![TinkerCad Front Page](https://github.com/queens-satellite-team/Space-School/blob/79665e8ba8a807e1ad268ef5515d1499b6250be8/lab1/lab1-images/tinkercad-frontpage.png)

1. Select "Create a personal acount" and follow the steps to sign up. 
2. After following the prompts and entering in some basic information, your acount shall be created and you will be signed in. 
3. You should now be on your user dashboard. Select "Circuits" in the left-hand panel, and then select "Try Circuits". 
4. You should now see a simple hardware circuit consisting of a coin cell battery, a resitor, an LED, and wire. This is where we will start tinkering! 

Let's take a look at the dashboard now. 
![TinkerCad Getting Started Dashboard](https://github.com/queens-satellite-team/Space-School/blob/79665e8ba8a807e1ad268ef5515d1499b6250be8/lab1/lab1-images/tinkercad-dash-board-with-arrows.png)

1. This opens the text editor window where we can write our software in either block format or in the C/C++ language. We will be opting for the latter. 
2. This is essentially "uploading your code" and turning on the power to your arduino in the simulation. 
3. Here is a list of the available components that Tinkercad offers with the simulation. There is a good selection of passive and active components to choose from. 
4. This create a PCB design file to be used by another Tinkercad service. 
5. Create with others by sharing a link to your design. People with the link may view and make changes to your design.

# Step 2 - Hello World - Tinkercad
So let's write our first bit of code to see if we have everything working. A *Hello World!* test is the first and most basic program you can run to validate your setup, so that is what we will be doing.

1. We can start our first basic program by first removing the components on the dashboard (select component, and hit delete or backspace) to get a clean space. 
2. From the 'Components' drop-down menu select 'All', and then type 'arduino' into the search bar. 
3. Scroll down to the 'Starters' section, select 'Breadboard' to add an arduino uno with a breadboard to the dashboard. 
4. To begin writing our script, select 'Code', and change 'Blocks' to 'Text' in the drop down menu. You screen should look as below. 
5. Rename the design to *Hello World* be selecting *Start Simulating* at the top left of the screen and entering the new name. 

![Tinkercad Hello World Start](https://github.com/queens-satellite-team/Space-School/blob/79665e8ba8a807e1ad268ef5515d1499b6250be8/lab1/lab1-images/tinkercad-hello-world-v1.png)

5. In the text editor area, change the code to resemble the following. 
![Tinkercad Hello World Code](https://github.com/queens-satellite-team/Space-School/blob/79665e8ba8a807e1ad268ef5515d1499b6250be8/lab1/lab1-images/tinkercad-hello-world-v2.png)

Before running the simulation, let us take a look at what we just wrote. 

`Line 3: void setup()` 
- This is a function specific to working with Arduinos. This function will only be executed once, and is typically used to setup any variables, objects, data, etc. 

`Line 8: void loop()`
- This is another function specific to working with Arduinos. This function will be continuously executed in a loop while the Arduino is powered on. This is where we will be writing our code to collect and store our desired data. 

`Line 5: *Serial.begin(9600);`
- This line opens up a communication link between the arduino board and the serial monitor. The number 9600 specifies the baudrate. The baud rate - or symbol rate - is the rate at which information is transferred in a communication channel. For the serial monitor, *9600 baud* means that the serial monitor is capable of transferring / reading a maximum of 9600 bits per second. Another common rate is 115200 baud. 

`Line 10: Serial.println("Hello World!");`
- This line sends the message in qoutes along with a newline character from the arduino board to the serial monitor. This message is a C++ *string* data type which we will discuss more later. In this line of code, we are using *Serial.println()* to include a new line character for each message. This way each new message will apear on a new line, and not get mushed together. You can try removing the *ln* from *Serial.println()* to see what happens! 

`Line 11: *delay(1000);*`
- This line pauses the arduino's execution of the code at this line for the number of milliseconds specified. In this case we are waiting for 1s between telling the arduino board to send another message. 

More information regarding these and all the Arduino functions can be found [here](https://www.arduino.cc/reference/en/)!

6. Press *Start Simulation*, and open the serial monitor by clicking the *Serial Monitor* button on the buttom of the text window. 
7. You should now see the message *Hello World!* being printed out every second! 

![Hello World Output](https://github.com/queens-satellite-team/Space-School/blob/79665e8ba8a807e1ad268ef5515d1499b6250be8/lab1/lab1-images/tinkercad-hello-world-v3.png)

A really cool feature of Tinkercad is that the code written here for the simulation can be downloaded into an arduino file and then uploaded and run on a physical arduino board. This is a great feature for working in teams or even wanting to test some functionality without bringing your hardware everywhere you go. Even if we do not have an arduino board yet, having the program to run arduino scripts will be useful for later labs and future projects. 

# Step 3 - Setup Arduino IDE
The Arduino integrated development environment (IDE) is a multipurpose toool to write the software and upload code to the arduino board. To get started download the required software from the [Arduino Download Page.](https://www.arduino.cc/en/software)

### Step 3.1 - Arduino IDE For Windows
1. In the blue box titled *Download Options* select *Windows Win 7 and newer*. 
2. You should get an .exe file. Open the file and the Arduino installer program will open. 
3. Select next on the liscence agreement. 
4. Make sure all *components to install* are selected, and click next. 
4. It is recemonded to keep the install directory as default, but feel free to change if neccessary. Then select install. 
6. Note: there maybe multiple *Windows Security* pop-ups, these are expected, just click on *accept* for each one. 
7. Once installed, you can delete the arduino.1.8.15-windows.exe from your downloads folder. 
8. Note: If you do not have Java you may need to install this as well. Java has a good walk through found [here.](https://java.com/en/download/help/download_options.html#windows)
9. You should now have a desktop icon for the Arduino IDE, click on this to start programming! 

### Step 3.1 - Arduino IDE For Macs 
1. In the blue box titled *Download Options* select *MacOS X 10.10 or newer*. 
2. Once downloaded, you should get a .zip file. 
3. Click on the downloaded file, and Mac should unzip it for you and place the Arduino IDE application in your *Downloads* folder. 
4. Note: If Mac does not automatiically unzip the file, you can right click and select *open*. 
5. Move the Arduino IDE application into your *Application* folder. 
6. Click on the Arduino IDE application to start programming! 

# Step 4 - Hello World - Arduino IDE  
Now welcome to the Arduino IDE! This is what your screen should look like now.

![Blank Arduino IDE](https://github.com/queens-satellite-team/Space-School/blob/79665e8ba8a807e1ad268ef5515d1499b6250be8/lab1/lab1-images/blank-arduino-ide.png)

The Arduino IDE is similiar to that of Tinkercad's dashboard, but there are some features that can be pointed out right away. 

![Arduino IDE with Arrows Indicating IDE Functionality](https://github.com/queens-satellite-team/Space-School/blob/79665e8ba8a807e1ad268ef5515d1499b6250be8/lab1/lab1-images/ide-with-arrows.png)

Most noticabbly is the *Verify* and *Upload* buttons located on the top left. The *Verify* button makes checks for any errors in your code (it will only check syntax errors though, not logical or procedural errors!) and the *Upload* button will upload the software into the hardware so the Arduino can operate as you specify in the code. 

We will take the code we wrote in Tinkercad, download it to an arduino file, and verify it in the Arduino IDE. 
1. Go back to Tinkercad and select *Download Code* by selecting the button directly beside the *Text* drop down menu. 
2. Once downloaded, you should have a *.ino* file called *hello_world.ino*
3. Attempt to open the file, and you should be greeted by a message similiar to the one below. 

![Arduino Ino File Message](https://github.com/queens-satellite-team/Space-School/blob/79665e8ba8a807e1ad268ef5515d1499b6250be8/lab1/lab1-images/arduino-ino-file-mesg.png)

Ardiuno files have the extension *.ino* and must be placed in a folder with the same name as the file. Fortunately, when you save the file using the IDE, the IDE will generate this folder for you and place the *.ino* in there. For example, our hello_world.ino will have a path of *~/Arduino/hello-world/hello_world.ino*. So, select *OK* to continue. 

4. Select *Verify* in the Arduino IDE, and the message *Compiling Sketch* should appear near the bottom of the IDE. Once this is finished it will say *Done Compiling* and display memory information about your code. 

![Arduino Good Compile Message](https://github.com/queens-satellite-team/Space-School/blob/79665e8ba8a807e1ad268ef5515d1499b6250be8/lab1/lab1-images/arduino-good-compile-msg.png)

5. If you have an arduino ready to use please follow the steps in *4.1 Uploading and Reading Serial Monitor*, else skip to *Step 5 - Blinky Test - Tinkercad*

## 4.1 Uploading and Reading Serial Monitor 
1. Connect your arduino board to your computer with a USB cable. This will supply power as well as communication to and from the arduino board. You should see a red or orange LED turn on indicating that the arduino board is receiving power. 
2. Select *Tools*, then *Board* from the top menubar. Select the type of board you are using. 
3. Select *Tools*, then *Port* from the top menubar. Select the port that the arduino board is plugged into. 
- Note: On Windows, the port will be something like *COM4*, or *COM5*, while on Mac it will be something like */dev/cu.usbserial-1420*. 
4. If using an older arduino nano (or a cheap one bought from amazon), Select *Tools*, then *Processor* from the top menubar. Select *ATMega328P (Old Bootloader)*. 
5. Select *Upload* from within the IDE to upload the program onto the arduino board. 
- Note: if the program does not upload correctly make sure you have the correct board information and redo steps 2-4. 
6. Once successfully uploaded, open the serial monitor by selecting the far right bottun in the Arduino IDE.  
7. Change your baudrate to match what we specified in the programm: 9600 baud. 
8. You should now have "Hello World!" being printed to the monitor every second! Congrats so far! 

![Hello World! Serial Monitor Output](https://github.com/queens-satellite-team/Space-School/blob/79665e8ba8a807e1ad268ef5515d1499b6250be8/lab1/lab1-images/hello-world-serial-monitor.png)

# Step 5 - Blinky Test - Tinkercad 
So we made sure our software and our serial communication was working, now let us validate our hardware connections! We will first take a look at the pins on the Arduino Uno and see if there is one we can use to turn off and on an LED. 

![Arduino Uno Pinout](https://github.com/queens-satellite-team/Space-School/blob/79665e8ba8a807e1ad268ef5515d1499b6250be8/lab1/lab1-images/Pinout-UNOrev3_latest.png)

While some pins have some extra functionality, pins D2 to D8 are simple input and output pins that will fulfil our needs for now. Anyone of these will work, but we will choose pin 8 for this setup. 

## Step 5.1 - Blinky Hardware
1. Place an LED and a resistor from the component menu onto the breadboard. 
2. Change the value of the resistor to 330 Ohms. 
- The Arduino is limited to a 20 mA output current for each of it's input/output pins acording to the [specifications](https://store.arduino.cc/usa/arduino-uno-rev3) provided by Arduino. This resistor will ensure a controlled amount of current will be drawn from the output pin. 
- As an exercise, determine the minimum size resistor to be included in this circuit! Note that we can approxiate that the LED will have a constant voltage drop of ~0.7V in this circuit. 
3. Regarding the LED, these devices are polarity sensitive. So you can think of the cathode as the *negative terminal* and the anode as the *positve terminal*. 
- You can connect the cathode to ground, the anode to one end of the resitor, and the other end of the resitor to the arduino pinout. You circuit should be as follows. 

![Blinky Hardware Setup](https://github.com/queens-satellite-team/Space-School/blob/79665e8ba8a807e1ad268ef5515d1499b6250be8/lab1/lab1-images/blinky-hw-setup.png)

## Step 5.2 - Blinky Software
1. Replace your code in the text box with the following. 
![Blinky Software Setup](https://github.com/queens-satellite-team/Space-School/blob/79665e8ba8a807e1ad268ef5515d1499b6250be8/lab1/lab1-images/blinky-sw-setup.png)

Let us take a look at some of these new functions that we are using! 

`Line 5: pinMode(8, OUTPUT);`
- This lets the Arduino know that we want to use pin 8 as an ouput. This function can set pins to either input or output and can assign any of the digital pins. 

`Line 10: digitalWrite(8, HIGH);`
`Line 12: digitalWrite(8, LOW);`
- This changes wether or not the specified pin has a high voltage (5V) or a low voltage (0V). The digital pins are limited to these high and low states, and are typically 5V ouputs unless specified. 

Again, more information regarding these and all the Arduino functions can be found [here](https://www.arduino.cc/reference/en/). This is a wonderful reference tool, and something to keep handy going forward. 

2. Select *Start Simulation* and you should see your LED blinking. 

![LED Blink](https://github.com/queens-satellite-team/Space-School/blob/79665e8ba8a807e1ad268ef5515d1499b6250be8/lab1/lab1-images/led-do-flash.png)

We can now run simulations for implementing both software and hardware using tinkercad, and can download that code to be used in the Arduino IDE to iterate upon it and upload it to our arduino boards! Feel free to tinker away with more of the hardware provided by Tinkercad, and look into some of the reference documentation for the Arduino functions. 

# Contact Info 

Sean Tedesco: 17sart@queensu.ca

Emma Paczkowski: emma.paczkowski@queensu.ca

Thomas Sears: thomas.sears@queensu.ca

Kate Szabo: kate.szabo@queensu.ca

Piper Steffen: 16pis@queensu.ca
