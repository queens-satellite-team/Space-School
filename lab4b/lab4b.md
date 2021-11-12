# Introduction 
Hello! Welcome to the fourth lab (part b) of Space School! In this lab we are going to focus on the data storage element of your toastSats. In this lab you will find the required hardware connections, as well as some example code to interact with the SD card reader. Every toastSat team will have an SD card on their payload regardless of their chosen sensor suite. As such, when you are thinking about the mass, power consumption, and volume of your toastSat, please keep this setup in mind. 

If you have any questions, please feel free to reach out to Emma Paczkowski, Sean Tedesco, Piper Steffen, Thomas Sears, or any other member of the QSAT Team. Contact info can be found in the [readme](https://github.com/queens-satellite-team/Space-School) of this repository. 

# Goals of Lab 4 B
1️⃣ Implement the SD Card reader into your toastSat. 

# 1.0 SD Card Reader/Writer
The SD card reader is used to store data that you collect during your flight on an SD card. More information can be found with the [data sheet](https://cdn-learn.adafruit.com/downloads/pdf/adafruit-microsd-spi-sdio.pdf). Before powering on the SD card reader, we have to take note of what voltage levels we can use to talk to this device. The SD card reader has 3.3 volt logic; however, Arduinos typically have 5.0 volt logic. This means the communication pins on the Arduino use 5.0 volts to represent a "1" or a HIGH state, and 0.0 volts to represent a "0" or a LOW state when communicating with devices. However, this SD card reader can only handle a maximum of about 3.3 volts when communicating. This means we have to put an additional piece of electronics between these two devices so we do not damage the SD card reader. This is our [logic level shifter](https://www.sparkfun.com/products/12009), that will take the same communication signal output from the Arduino, but scale it down to a safer voltage.  

<p align="center">
<image src="https://user-images.githubusercontent.com/48306876/140852743-43d21b8d-5aba-481d-93c1-825ad041c40c.png" width="300" height="300"><image src="https://user-images.githubusercontent.com/48306876/140852633-a25e0dec-651b-4dfb-b579-adb0ea23dae9.png" width="300" height="300">
</p>

# 1.1 🛠️ Hardware Requirements
<p align="center">
	<image src="https://user-images.githubusercontent.com/48306876/140847317-a65d1230-d4b2-425a-8e64-ec22f1ff5486.png" width="900" height="800">
</p>

**Power Pins**
    
- **Pin 3V:** This is the power pin. MicroSD cards must use 3.3V, so take care to only hook 3.3V to this pin. Hooking 5V or VBAT to this pin will damage your microSD card.
- **Pin GND:** common ground for power and logic.
	
**Logic Pins**
	
- **Pin DET:** - Detect whether a microSD card is inserted. This pin is connected to **GND** internally when there's no card, but when one is inserted it is pulled up to **3V** with a 4.7kΩ resistor. That means that when the pin's logic level is **False** there's no card and when it's **True** there is. This is not required to communicate with the SD card reader.
- **PIN CLK:** - This is the SPI **C**lock pin /** SCLK** **S**erial **C**lock, its an input to the chip and controlls the timing of the communication between these two devices.
- **PIN SO:** - This is the **S**erial **O**ut / **M**aster **I**n **S**lave **O**ut pin, for data sent from the SD card to your Arduino. 
- **PIN SI:** - This is the **S**erial **I**n / **M**aster **O**ut **S**lave **I**n pin, for data sent from your Arduino to the SD card.
- **PIN CS:** - this is the **C**hip **S**elect pin, pull the pin to a low state to start SPI communication.

Note that when inserted, the SD card extends slightly beyond the edge of the PCB. 

## 1.2 💻 Software Requirements
You will need to import 2 libraries. To import a library, in the Arduino IDE go to *Sketch -> Include Libraries -> (library name)*

- Import the **SPI** library. Note that an Arduino board only has 2 SPI connections.
- Import the **SD** card library.

## 1.3 Example
```
/*
  SD card read/write

  This example shows how to read and write data to and from an SD card file
  The circuit:
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 10 (for MKRZero SD: SDCARD_SS_PIN)

  This example code is in the public domain.

*/

#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test.txt", FILE_WRITE);

  // if the file opened properly, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  // re-open the file for reading:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void loop() {
  // nothing happens after setup
}
```
