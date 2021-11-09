# Introduction 
Hello! Welcome to the fourth lab (part b) of Space School! In this lab we are going to focus on the data storage element of your toastSats. In this lab you will find the required hardware connections, as well as some example code to interact with the SD card reader. Every toastSat team will have an SD card on their payload regardless of their chosen sensor suite. As such, when you are thinking about the mass, power consumption, and volume of your toastSat, please keep this setup in mind. 

If you have any questions, please feel free to reach out to Emma Paczkowski, Sean Tedesco, Piper Steffen, Thomas Sears, or any other member of the QSAT Team. Contact info can be found in the [readme](https://github.com/queens-satellite-team/Space-School) of this repository. 

# Goals of Lab 4
1️⃣ Implement the SD Card reader into your toastSat. 

# 5.0 SD Card Reader/Writer
The SD Card reader/writer is used to store data that you collect during your flight on an SD card. More information can be found with the [data sheet](https://cdn-learn.adafruit.com/downloads/pdf/adafruit-microsd-spi-sdio.pdf)  

## 5.1 Hardware Requirements
### Pinouts 📌
<image src="https://github.com/queens-satellite-team/Space-School/blob/d50a7fe230cbf65b194a88ed02787b5a0b94e26a/lab4/lab4-images/sd_card_pinout.JPG" alt = "SD Card Reader Pinout Diagram" width="500" height="500"> 
	
  -  Power Pins
      - **3V** - This is the power pin. MicroSD cards must use 3.3V, so take care to only hook 3.3V to this pin. Hooking 5V or VBAT to this pin will damage your microSD card.
     - **GND** - common ground for power and logic.
  - Common Logic Pins
    - **DET** - Detect whether a microSD card is inserted. This pin is connected to **GND** internally when there's no card, but when one is inserted it is pulled up to **3V** with a 4.7kΩ resistor. That means that when the pin's logic level is **False** there's no card and when it's **True** there is.
   - SPI Logic Pins
     If you're using SPI to connect to your SD cards, the pins have the following functions:
      - **CLK** - This is the SPI **C**lock pin /** SCK** **S**erial **C**lock, its an input to the chip.
      - **SO** - this is the **S**erial **O**ut / **M**icrocontroller **I**n **S**erial **O**ut pin, for data sent from the SD card to your processor.
       - **SI** - this is the **S**erial **I**n / **M**icrocontroller **O**ut **S**erial **I**n pin, for data sent from your processor to the SD card. Its an input to the chip and can use 3V logic only.
      - **CS** - this is the **C**hip **S**elect pin, drop it low to start an SPI transaction. Its an input to the chip and can use 3V logic only.
Pull ups are provided on all SPI logic pin.

- SDIO Logic Pins     
If you're using SDIO to connect to your SD cards, the pins have the following functions:      
    - **CLK** - The SDIO clock pin. A clock signal is sent by the microcontroller to the SD card on this pin.   
    - **CMD**  - A bidirectional pin for communication between the microcontroller and the SD card, used for commands and information.   
    - **4 Data pins**  - Four bidirectional pins for communication between the microcontroller and the SD card, used for transferring bulk data. Take care to wire these in the correct order! The silk screen legends read: **D0, D1, DAT2, D3**. 

Pull ups are provided on all SDIO logic pins.
Note that when inserted, the SD card extends slightly beyond the edge of the PCB. 

## 5.2 Software Requirements
You will need to import 2 libraries. To import a library, in the Arduino IDE go to -> Sketch -> Include Libraries -> (library name)

- Import the **SPI** library. Note that an Arduino board only has 2 SPI connections.
- Import the **SD** card library.

## 5.3 Example
```
/*
  SD card read/write

  This example shows how to read and write data to and from an SD card file
  The circuit:
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

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

  if (!SD.begin(4)) {
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
