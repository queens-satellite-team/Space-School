# Introduction 
Hello! Welcome to the fifth lab of Space School! In this lab we are going to focus on the data storage element of your toastSats. In this lab, you will find the required hardware connections, as well as some example code, to interact with the SD card reader. Every toastSat team will have an SD card on their payload regardless of their chosen sensor suite. As such, when you are thinking about the mass, power consumption, and volume of your toastSat, please keep this setup in mind. 

If you have any questions please feel free to reach out to Sydney Caulfeild, Emma Paczkowski, Sean Tedesco, Thomas Sears, or any other member of the QSAT Team. Contact info can be found in the [readme](https://github.com/queens-satellite-team/Space-School) of this repository. 

# Goals of Lab 5 
1️⃣ Understand why we need an SD card and what an SD card means. 

2️⃣ Create the hardware connection for a logic level shifter between the microcontroller and SD card reader.

3️⃣ Read through and then run the code to read and write to an SD card.

# Section 1: SD Card Reader Overview 
The SD card reader is used to store data that you collect during your flight on an SD card. Before powering on the SD card reader, we have to take note of what voltage levels we can use to talk to this device. This information can be found in the [data sheet](https://cdn-learn.adafruit.com/downloads/pdf/adafruit-microsd-spi-sdio.pdf) and this thinking is a good-practice working with any sort of electronic device. The SD card reader has 3.3 volt logic; however, Arduinos have a 5.0 volt logic. To clarifiy with a simplified example, _5-volt logic_ is when a component's communication pins use 5.0 volts to represent a "1" or a HIGH state, and 0.0 volts to represent a "0" or a LOW state when communicating with devices. However, this SD card reader can only handle a maximum of about 3.3 volts when communicating. This means we have to put an additional electronic device between these two devices so we do not damage the SD card reader. This is our [logic level shifter](https://www.sparkfun.com/products/12009), that will take the same communication signal output from the Arduino, but scale it down to a safer voltage. The wiring diagram for the sd-card reader, logic-level shifter, and an arduino nano (every) is given below. 

<p align="center">
	<image src="https://user-images.githubusercontent.com/48306876/162848601-cb52a35e-b6de-4f0a-89ba-3a23b0a15c55.png" width="900" height="800">
</p>

More information for each compontent is given below. 

## 1.1 SD Card Hardware Requirements 🛠️
<p align="center">
<image src="https://user-images.githubusercontent.com/48306876/140852743-43d21b8d-5aba-481d-93c1-825ad041c40c.png" width="300" height="300">
</p>

**Power Pins**
    
- **Pin 3V:** This is the power pin. MicroSD cards must use 3.3V, so take care to only hook 3.3V to this pin. Hooking 5V or VBAT to this pin will damage your microSD card.
- **Pin GND:** common ground for power and logic.
	
**Logic Pins**
	
- **Pin DET:** - Detect whether a microSD card is inserted. This pin is connected to **GND** internally when there's no card, but when one is inserted it is pulled up to **3V** with a 4.7kΩ resistor. That means that when the pin's logic level is **False** there's no card and when it's **True** there is. This is not required to communicate with the SD card reader.
- **PIN CLK:** - This is the SPI **C**lock pin / **SCLK** **S**erial **C**lock, its an input to the chip and controlls the timing of the communication between these two devices.
- **PIN SO:** - This is the SPI **M**aster **I**n **S**lave **O**ut pin, for data sent from the SD card to your Arduino. 
- **PIN SI:** - This is the SPI **M**aster **O**ut **S**lave **I**n pin, for data sent from your Arduino to the SD card.
- **PIN CS:** - this is the **C**hip **S**elect pin, pull the pin to a low state to start SPI communication.

Note that when inserted, the SD card extends slightly beyond the edge of the PCB. 

## 1.2 SD Card Software Requirements 💻
You will need to import 2 libraries. To import a library, in the Arduino IDE go to *Sketch -> Include Libraries -> (library name)*

- Import the **SPI** library. Note that an Arduino board only has 2 SPI connections.
- Import the **SD** card library.

# Section 2: Logic Level Shifter 

For some sensors and devices you can not connect them directly to the Arduino. For us, this is only the sd-card reader. We must change the high voltage outputs from the Arduino Nano Every to a samller voltage in order to protect these sensors from being fried.

<p align="center">
<image src="https://user-images.githubusercontent.com/48306876/140852633-a25e0dec-651b-4dfb-b579-adb0ea23dae9.png" width="300" height="300">
</p>

The PIN connections are as follows:
	
- HV  --> Arduino 5.0 V
- HV1 --> Arduino CSN  (Pin 10) 
- HV2 --> Arduino MOSI (Pin 11)
- HV3 --> Arduino MISO (Pin 12)
- HV4 --> Arduino SCLK (Pin 13)

- LV  --> Arduino 3.3 V
- LV1 --> Device CSN  
- LV2 --> Device MOSI 
- LV3 --> Device MISO
- LV4 --> Device SCLK

# Section 3: SD Card Software 
An example Arduino sketch to control the above SD card setup is provided in _lab 5's code folder_. This example sketch does not require - or implement - any sensors that we have worked with prior to, and should be used only to validate the working condition of the hardware setup of an arduino, sd-card reader, and logic-level shifter.
