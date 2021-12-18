/* 
 * Title:         Weather Systems Satellite 
 * Last Updated:  November 17th, 2021
 * Author:        Queen's Space Engineering Team - Satellite
 * Breif:         Example of a toastSat payload that utilizes the BMP180 pressure sensor
 *                  and the TMP36 temperature sensor. The time, temperature from the TMP36,  
 *                  and the temperature and pressure from the BMP180 are measured and
 *                  recorded onto an SD card. 
 *                Note: The contents of the SD card is overwritten upon reset of the Arduino. 
 *                  
 * Requirements:
 *  BMP180 Library: https://learn.sparkfun.com/tutorials/bmp180-barometric-pressure-sensor-hookup-/all#res
 */

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
 */


/*****************************************************************
 * INCLUDES
 */
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <SFE_BMP180.h>


/*****************************************************************
 * PIN SETUP and GLOBAL VARIABLES
 */
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

/*****************************************************************
 * FUNCTION DECLARATIONS
 */
double getPressure();

/*****************************************************************
 * SETUP 
 */
void setup(){

  // open serial communications 
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }
  
  //turn on the green LED to let the user know the system is working
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("system started.");
  
  // set up the temperature sensor
  pinMode(temp_sens_pin, INPUT);
  Serial.println("initializing tmp36 sensor... initialization done.");

  // set up the pressure sensor
  Serial.println("initializing bmp180 sensor... ");
  if (!pressure_sensor.begin()){
    Serial.println("initialization failed!");
    digitalWrite(LED_BUILTIN, LOW);
     while(1);
  }
  Serial.println("initialization done.");

  // Get the baseline pressure
  baseline = getPressure();

  // set up the sd card reader / writer  
  Serial.print("Initializing SD card...");
  if (!SD.begin(sd_card_csn)) {
    Serial.println("initialization failed!");
    digitalWrite(LED_BUILTIN, LOW);
    while (1);
  }
  Serial.println("initialization done.");


  if (SD.exists("weather.csv")){
    SD.remove("weather.csv");
    Serial.println("removed old weather file.");
  }
  myFile = SD.open("weather.csv", FILE_WRITE);
    // if the file opened properly, write to it:
    if (myFile) {
      Serial.print("writing to weather.csv...");
      myFile.println("time,temp1,time2,press");
      // close the file:
      myFile.close();
      Serial.println("done.");
    } else {
      // if the file didn't open, print an error:
      Serial.println("error opening weather.csv");
      digitalWrite(LED_BUILTIN, LOW);
      delay(100);
      digitalWrite(LED_BUILTIN, HIGH);
    }
}


/*****************************************************************
 * LOOP
 */
void loop(){

  time_stamp = millis();
    
  // read the analog input at each sensor
  analog_input = analogRead(temp_sens_pin);
  // convert analog input to a voltage value
  raw_voltage = analog_input * (5.0/1024.0); 
  // convert voltage value to a temperature value
  temp_celsius = (raw_voltage - 0.5) * 100;
  Serial.print("temp1: ");
  Serial.println(temp_celsius);

  delay(100);

  status = pressure_sensor.startTemperature();
  if (status != 0) {
    delay(status);
    status = pressure_sensor.getTemperature(T);
  }
  Serial.print("temp2: ");
  Serial.println(T);

  delay(100);
  
  P = getPressure();
  kpa = P*0.1;
  Serial.print("press: ");
  Serial.println(kpa);

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
    
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    Serial.println("error opening weather.csv");
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
  }

  myFile = SD.open("weather.csv");
  if (myFile) {
    Serial.println("weather.csv:");
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
  } else {
    Serial.println("error opening weather.csv");
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
  }
    
  delay(1000);
}

double getPressure() {
  status = pressure_sensor.startTemperature();
  if (status != 0) {
    delay(status);
    status = pressure_sensor.getTemperature(T);
    if (status != 0) {
      status = pressure_sensor.startPressure(3);
      if (status != 0) {
        delay(status);
        status = pressure_sensor.getPressure(P,T);
        if (status != 0) {
          return(P);
        } 
        else Serial.println("error retrieving pressure measurement\n");
      }
      else Serial.println("error starting pressure measurement\n");
    }
    else Serial.println("error retrieving temperature measurement\n");
  }
  else Serial.println("error starting temperature measurement\n");
}
