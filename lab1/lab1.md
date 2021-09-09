# Introduction

Hello! Welcome to the first lab of Space School! In this lab we will begin with getting the Arduino IDE up and running, then we will start exploring some of the different ways we can program our ARduino board to do some fun little actions for us. 

If you have any questions please feel free to reach out to Thomas Sears, Emma Paczkowski, Kate Szabo, Piper Steffen, Sean Tedesco, or any other member of the QSAT Team. Contact info can be found at the bottom of the lab. 


# Step 1 - Setup IDE
The Arduino integrated development environment (IDE) is a multipurpose toool to write the software and upload code to the arduino board. To get started download the required software from the [Arduino Download Page.](https://www.arduino.cc/en/software)

### Step 1 - For Windows
1. In the blue box titled *Download Options* select *Windows Win 7 and newer*. 
2. You should get an .exe file. Open the file and the Arduino installer program will open. 
3. Select next on the liscence agreement. 
4. Make sure all *components to install* are selected, and click next. 
4. It is recemonded to keep the install directory as default, but feel free to change if neccessary. Then select install. 
6. Note: there maybe multiple *Windows Security* pop-ups, these are expected, just click on *accept* for each one. 
7. Once installed, you can delete the arduino.1.8.15-windows.exe from your downloads folder. 
8. Note: If you do not have Java you may need to install this as well. Java has a good walk through found [here.](https://java.com/en/download/help/download_options.html#windows)
9. You should now have a desktop icon for the Arduino IDE, click on this to start programming! 

### Step 1 - For Macs 
1. In the blue box titled *Download Options* select *MacOS X 10.10 or newer*. 
2. Once downloaded, you should get a .zip file. 
3. Click on the downloaded file, and Mac should unzip it for you and place the Arduino IDE application in your *Downloads* folder. 
4. Note: If Mac does not automatiically unzip the file, you can right click and select *open*. 
5. Move the Arduino IDE application into your *Application* folder. 
6. Click on the Arduino IDE application to start programming! 

# Step 2 - Hello World 
Now welcome to the Arduino IDE! This is what your screen should look like now.

![Blank Arduino IDE](https://github.com/queens-satellite-team/Space-School/blob/1e01387ff4d3da24ef29785931619ad8ce6db5c4/images/blank-arduino-ide.png?raw=true)

## 2.1 - Getting Familiar with the IDE
There are a few things that can be pointed out right away. 

![Arduino IDE with Arrows Indicating IDE Functionality](https://github.com/queens-satellite-team/Space-School/blob/1e01387ff4d3da24ef29785931619ad8ce6db5c4/images/ide-with-arrows.png?raw=true)

Most noticabbly is the *setup* and *loop* areas in the body of the IDE. These are two functions that every arduino program must have. The *setup* function occurs once, while the *loop* function will continue to executue in a loop while the Arduino board is powered. 

## 2.2 Example Hello World! Code

So let's write our first bit of code to see if we have everything working. A *Hello World!* test is the first and most basic program you can run to validate your setup, so that is what we will be doing. The example code is as follows. 

![Hello World! Example Sketch](https://github.com/queens-satellite-team/Space-School/blob/5da6fc5b4ef3739f320422ec64ccfdf60c2cb7a6/images/hello-world-example.png?raw=true)

Write these lines into your Arduino IDE, and save the file. 
- Note: Ardiuno files have the extension *.ino* and must be placed in a folder with the same name as the file. Fortunately, when you save the file using the IDE, the IDE will generate this folder for you and place the *.ino* in there.
- For example, our hello-world.ino will have a path of *~/Arduino/hello-world/hello-world.ino*. 

Let us take a look at what is going on here.

__Line 3: *Serial.begin(9600);*__
- This line opens up a communication link between the arduino board and the serial monitor provided by the IDE (available by clicking the top right button). The number 9600 specifies the baudrate. The baud rate is the rate at which information is transferred in a communication channel. For the serial monitor, *9600 baud* means that the serial monitor is capable of transferring / reading a maximum of 9600 bits per second. Another common rate is 115200. 

__Line 8: *Serial.println("Hello World!");*__
- This line sends the message (or rather, *string*) in qoutes along with a newline character from the arduino board to the serial monitor. Instead of using *Serial.print()*, we are using *Serial.println()* to include a new line character for each message. This way each new message will apear on a new line, and not get mushed together. You can try removing the *ln* from *Serial.println()* to see what happens! 

__Line 9: *delay(1000);*__
- This line pauses the arduino at this line for the number of milliseconds specified. In this case we are waiting for 1s between telling the arduino board to send another message. 

## 2.3 Uploading and Reading Serial Monitor 
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

![Hello World! Serial Monitor Output](https://github.com/queens-satellite-team/Space-School/blob/70acc73a802000d13ea7bd14e14754109967e10e/images/hello-world-serial-monitor.png?raw=true)

# Step 3 - Hardware and Blinky Test 

# Step 4 - User Input and Conditional Statements 

# Step 5 - Functions 

# Contact Info 

Sean Tedesco: 17sart@queensu.ca

Emma Paczkowski: emma.paczkowski@queensu.ca

Thomas Sears: thomas.sears@queensu.ca

Kate Szabo: kate.szabo@queensu.ca

Piper Steffen: 16pis@queensu.ca
