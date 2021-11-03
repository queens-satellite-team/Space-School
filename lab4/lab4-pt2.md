# Introduction 
Hello! Welcome to the second part of the fourth lab of Space School! This is an incomplete lab in order to provide supplimentary information to aid in the development of your toastSat payloads. **By the end of this lab you should have picked out one or two sensors, have all hardware connections made on a breadboard, and all software written.** 

As a note, the Arduinos we are using in these labs are the Arduino Nano Every and they are slightly different than the Arduino Nano. Please follow the steps in Section 2 to make sure you can communicate with your board correctly. 

# Section 1 - Breadboard Layout

There are many ways to assemble a circuit together. The most common way to start is with a [breadboard](https://en.wikipedia.org/wiki/Breadboard). Breadboards have internal connections that allow for quick work when piecing together new components of a ciruit. In the photo below, we see all the shared connections inside of a breadboard. The centre circut area in green has a shared connection for each column along with a divider in the middle (the top of the column and the bottom of the column are not connected), and the rows coloured blue and red show that there is a shared connection across the entire line (the top blue and red lines are not connected to the bottom blue and red lines). 

![image](https://user-images.githubusercontent.com/48306876/138555396-737f73e0-560d-4cb3-94b0-bc2318304226.png)

# Section 2 - Uploading Code To An Arduino 

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

# Section 3 - Payload Up To Date

Before moving on to lab 5 your payload should look something like the photo below with the addition of an SD card writer (the toastSat Payload below does not include one yet, but yours should). 

![IMG_0207](https://user-images.githubusercontent.com/48306876/140006482-feb81814-aeec-4860-9608-ca048084c2e8.jpg)
