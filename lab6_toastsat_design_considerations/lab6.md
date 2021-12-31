# Introduction 

Hello! Welcome to the sixth lab of Space School! In this lab we will review a complete example of a toastSat payload prototype. We will talk about some of the hardware features it has and the software associated with this prototype. This is a good opportunity to see some of the considerations that can go in a toastSat build as you continue working on your own toastSat. 

If you have any questions, please feel free to reach out to Emma Paczkowski, Sean Tedesco, Piper Steffen, Thomas Sears, or any other member of the QSAT Team. Contact info can be found in the [readme](https://github.com/queens-satellite-team/Space-School) of this repository. 

# Goals of Lab 6 

1️⃣ Hardware Review of the prototype toastSat payload.

2️⃣ Code Review of the prototype toastSat payload. 

# Section 1: Hardware Considerations
The example toastSat that we will be looking at contains the following components, and is pictured below. This build will be what is used for all future labs of Space School labs. Your toastSat payload may contain different components and thus look a little different, but that is okay. We are still going to make instructions that will be clear and easy-to-follow for all toastSats. 

<p align='center'>
  <img src="https://user-images.githubusercontent.com/48306876/147183755-14be98be-7868-46b0-a75a-b47cb541ea85.JPG", width=750> 
</p>

### 1.1 Component List
- 1x Arduino Nano Every
- 1x logic level shifter
- 1x sd-card reader
- 1x sd-card (32 GB)
- 1x TMP36 temperature sensor
- 1x BPM180 pressure sensor 

### 1.2 Design Considerations
- The Arduino power supply voltages (5.0 and 3.3 volts) were kept to different sides of the breadboard (top rail is powered with 5 volts, while the bottom is powered with 3.3 volts in the above photo). The justification for this is to prevent devices from being connected to incorrect voltage levels by grouping similiar devices together. 
- **Power supply** lines are identified with **red** wires, **ground** lines are identified with **black** wires. 
- **SPI** communication lines are consistent before and after the logic level shifter.
- **Signal** lines are identified with bright colored lines like **orange**, **yellow**, and **green**. 
- This build does not include any external LEDs circuits to indicate if the toastSat is working properly. Instead, the system utilizes the built-in LED on the Arduino to communicate its status to the user with three different states.
  - If the LED is on, the system is working as intended.
  - If the LED is off, the system needs to be rebooted and is not working at all.
  - If the LED is flashing, there was a problem working with the sensors and a measurement could not be collected. 

# Section 2: Software Considerations

The full code can be found in the _lab6-code directory_. For our code review, we will be looking at the _weatherSystemsSat_ example. To begin, we want to write code that is easy not just for yourself to read, but also easy for another team member to read as well. The justification for that is that it is easier for other team members to take your work and build on top of it. 

Looking at this example, we see the file contains two large comments blocks at the very top. These comments blocks are encouraged for all members of QSET to write in order to make it easier for other to understand the code other members write. The justification for the first comment block is to allow a new user to quickly understand the purpose of the file, know how recent it is, and who to contact if they have any questions. 

```
/* 
 * Title:         Weather Systems Satellite 
 * Last Updated:  November 17th, 2021
 * Author:        Queen's Space Engineering Team - Satellite
 * Brief:         Example of a toastSat payload that utilizes the BMP180 pressure sensor
 *                  and the TMP36 temperature sensor. The time, temperature from the TMP36,  
 *                  and the temperature and pressure from the BMP180 are measured and
 *                  recorded onto an SD card. 
 *                Note: The contents of the SD card is overwritten upon reset of the Arduino.     
 */
```

The second comment block tells the user everything they need to know to get this script working. It outlines the pins being used, any libraries that must be installed, and what voltages components must be powered with. The justification to include this comment block is to make it easier for someone else on the team, or even yourself, if you want to rebuild your system later.

```
/*****************************************************************
 * NOTES / HARDWARE SETUP
 *  - PIN CONFIGURATION IS MEANT FOR ARDUINO NANO EVERY 
 *  - TMP36 TEMPERATURE SENSORS POWERED WITH 5.0 VOLTS
 *
 *  - TEMP_SENS1 --> ANALOG PIN A6 (as INPUT) 
 *  
 *  - BMP180 SCL --> ANALOG PIN A5
 *  - BMP180 SDA --> ANALOG PIN A4
 *  
 *  - THE SD CARD MUST BE CONNECTED TO A LOGIC LEVEL SHIFTER 
 *  - SD CARD CSN  --> LV1 --> HV1 --> DIGITAL PIN 10
 *  - SD CARD MOSI --> LV1 --> HV1 --> DIGITAL PIN 11
 *  - SD CARD MISO --> LV1 --> HV1 --> DIGITAL PIN 12
 *  - SD CARD SCLK --> LV1 --> HV1 --> DIGITAL PIN 13
 *  - ARDUINO 3.3V --> LV
 *  - ARDUINO 5.0V --> HV
 *  - ARDUINO GND  --> GND
 *
 * Software Requirements:
 *  BMP180 Library: https://learn.sparkfun.com/tutorials/bmp180-barometric-pressure-sensor-hookup-/all#res
 */
```

A design consideration for clean-code is to provide headers for the different sections of the code. The justification for this is that it allows readers an easier reading experience and forces the writer to think for best to group certian aspects of their code together. 

```
/*****************************************************************
 * INCLUDES
 */
...

/*****************************************************************
 * PIN SETUP and GLOBAL VARIABLES
 */
 ...
 
 /*****************************************************************
 * FUNCTION DECLARATIONS
 */
 ...
```

Another design consideration for clean code is to create global variables for the hardware pins required for your toastSat. As a note, there are a couple of ways to set up global variables. You can use a `#define`, or `const int` to associate some name to a variable. In our example, we opted to use `const int` as this way clearly states what type of data is being used and is more consistent when you are creating other variables that are not just for your pins. The `#define` method is a simple text replacement so does not tell the user what data type is being used, and introduces a new way to read a variable making our code a slightly inconsistent in how we write it. 

```
int sd_card_csn = 10;   //output
int temp_sens_pin = A6; //input

// tmp36 temperature sensor
int analog_input;
float temp_average, raw_voltage, temp_celsius;

// bmp180 pressure sensor
SFE_BMP180 pressure_sensor;
char status;
double T, P, kpa, baseline;

// sd card reader / writer
File myFile;
unsigned long time_stamp; 
```

It is quite important when building a system, that at all times, you know what the state of the system is. This can be done through visual indications like a flashing LED, as well as writing text to the serial monitor. However, before launching your system, you may not have access to a serial monitor, so you must design your system to still indicate its working condition with such limitations, but stil be clear to the user on what is occuring with the toastSat. 

```
  //turn on the green LED to let the user know the system is working
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("system started.");

... 

  // set up the pressure sensor
  Serial.println("initializing bmp180 sensor... ");
  if (!pressure_sensor.begin()){
    Serial.println("initialization failed!");
    digitalWrite(LED_BUILTIN, LOW);
     while(1);
  }
  Serial.println("initialization done.");

...

  // set up the sd card reader / writer  
  Serial.print("Initializing SD card...");
  if (!SD.begin(sd_card_csn)) {
    Serial.println("initialization failed!");
    digitalWrite(LED_BUILTIN, LOW);
    while (1);
  }
  Serial.println("initialization done.");
```

This big chunk of code below is quite difficult to understand at first glance. This entire section creates a new entry in our weather data file on the sd-card with the current time, temperature, and pressure data that previously got collected; however, no where does it clearly say that. A simple comment would suffice to tell the user what is occurring, or this could be put into its own function with an appropriate name such as: `write_data_to_sd_card()`. If this section of code were to be reused anywhere else it would be encouraged to create this new function, but since this is the only place it is used in the code, a comment will work just fine. 

```
  // save this loop's collected data to the sd-card by printing the data to in .csv formatting 
  myFile = SD.open("weather.csv", FILE_WRITE);
  if (myFile) {
    Serial.print("writing to weather.csv... ");
    myFile.print("time,");
    myFile.print(time_stamp);
    myFile.print(",");
    myFile.print("temp1,");
    myFile.print(temp_celsius);
    myFile.print(",");
    myFile.print("temp2,");
    myFile.print(T);
    myFile.print(",");
    myFile.print("press,");
    myFile.println(kpa);
    
    // close the file
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file cannot be opened, flash the LED and print an error message
    Serial.println("error opening weather.csv");
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
  }
```

It is a good practice to provide a brief description of what your function does, what each one of its parameters is, and what is returned by the function. The justification for this is that, the reader will not have to read every single line of the internal working of the function, and be able to treat it as a black-box with certain inputs that provides certain outputs. 

```
@brief: gets the current pressure value as measured by the BMP180 sensor. 
@param: void
@return: pressure measurement in hPa, floating point number. 
double getPressure(void) {
...

}
```
