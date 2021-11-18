/* 
 * Title:         System Safety Satellite 
 * Last Updated:  November 1st, 2021
 * Author:        Queen's Space Engineering Team - Satellite 
 * Breif:         Example of a toastSat payload that measures the temperature of the satellite
 *                  in three different locations, produces an average value, and sets LED 
 *                  indicators if temperature goes above or below a threshold
 */

/*****************************************************************
 * NOTES / HARDWARE SETUP
 *  - PIN CONFIGURATION IS MEANT FOR ARDUINO NANO 
 *  - TMP36 TEMPERATURE SENSORS POWERED WITH 5.0 VOLTS
 *  
 *  - TEMP_SENS1 --> ANALOG PIN A0
 *  - TEMP_SENS2 --> ANALOG PIN A1
 *  - TEMP_SENS3 --> ANALOG PIN A2
 *  
 *  - GREEN LED --> DIGITAL PIN 2
 *  - RED LED   --> DIGITAL PIN 3
 *  - BLUE LED  --> DIGITAL PIN 4
 *  
 *  - THE SD CARD MUST BE CONNECTED TO A LOGIC LEVEL SHIFTER 
 *  - SD CARD CSN  --> LV1 --> HV1 --> DIGITAL PIN 5
 *  - SD CARD MOSI --> LV1 --> HV1 --> DIGITAL PIN 11
 *  - SD CARD MISO --> LV1 --> HV1 --> DIGITAL PIN 12
 *  - SD CARD SCLK --> LV1 --> HV1 --> DIGITAL PIN 13
 *  - ARDUINO 3.3V --> LV
 *  - ARDUINO 5.0  --> HV
 *  - ARDUINO GND  --> GND
 */


/*****************************************************************
 * INCLUDES
 */
#include <SPI.h>
#include <SD.h>


/*****************************************************************
 * PIN SETUP and GLOBAL VARIABLES
 */
#define SD_PIN        5
#define NUM_TEMP_SENS 3
#define TEMP_THRESHOLD 20.0

int temp_sens_pins[] = {A0, A1, A2};    // arduino MCU, battery, and external temperature sensors
int led_pins[] = {2, 3, 4};             // green, red, blue leds in that order 

float temperature_values[NUM_TEMP_SENS];
float temp_average;
float temp_celsius;
float raw_voltage;
int analog_input;
unsigned long time_stamp; 

File myFile;


/*****************************************************************
 * FUNCTION DECLARATIONS
 */
float get_average_temperature(float *t_vals);


/*****************************************************************
 * SETUP 
 */
void setup(){
    
  // set up the temperature sensor pins 
  for(int i=0; i<NUM_TEMP_SENS; i++){
      pinMode(temp_sens_pins[i], INPUT);
  }

  // set up the LED pins
  for(int i=0; i<NUM_TEMP_SENS; i++){
      pinMode(led_pins[i], INPUT);
  }

  //turn on the green LED to let the user know the system is working
  digitalWrite(led_pins[0], HIGH);
  Serial.println("System started.");
  
  // Open serial communications and wait for port to open
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  Serial.print("Initializing SD card... ");
  if (!SD.begin(SD_PIN)) {
    Serial.println("initialization failed!");
    digitalWrite(led_pins[0], LOW);
    while (1);
  }
  Serial.println("initialization done.");
  
  //open the file we will be saving our data to 
  myFile = SD.open("temperature_data.csv", FILE_WRITE);
  
  // if the file opened properly, write to it: in the setup, we write the header columns to a csv file
  if (myFile) {
    Serial.print("Printing CSV header... ");    
    myFile.println("time,temp1,temp2,temp3,avg");
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error
    Serial.println("error opening temperature_data.csv");
  }
}


/*****************************************************************
 * LOOP
 */
void loop(){
  
  // we loop through all of our temperature sensors
  for(int i=0; i<NUM_TEMP_SENS; i++){
    
    // read the analog input at each sensor
    analog_input = analogRead(temp_sens_pins[i]);

    // convert analog input to a voltage value
    raw_voltage = analog_input * (5.0/1024.0); 

    // convert voltage value to a temperature value
    temp_celsius = (raw_voltage - 0.5) * 100;

    // store that value into an array
    temperature_values[0] = temp_celsius;     
  } 

  // determine the average temperature value
  temp_average = get_average_temperature(temperature_values);

  //open our file to save the data
  myFile = SD.open("temperature_data.csv", FILE_WRITE);
  
  // if the file opened properly, write to it
  if (myFile) {
    Serial.print("Saving temperature data... ");

    //save the time
    myFile.print(millis()); myFile.print(",");

    //save the individual temperature values 
    for(int i=0; i<NUM_TEMP_SENS; i++){
      myFile.print(temperature_values[0]); myFile.print(",");  
    }

    //save the average temperature value 
    myFile.print(temp_average); myFile.println(",");
    
    // close the file
    myFile.close();
    Serial.println("done.");
    
  } else {
    // if the file didn't open, print an error and flash the green led
    myFile.close();
    Serial.println("error opening temperature_data.csv");
    digitalWrite(led_pins[0], LOW);
    delay(100);
    digitalWrite(led_pins[0], HIGH);
    delay(100);
    digitalWrite(led_pins[0], LOW);
    delay(100);
    digitalWrite(led_pins[0], HIGH); 
  }

  // update the leds to indicate the temperature
  if(temp_average >= TEMP_THRESHOLD){
    digitalWrite(led_pins[1], HIGH);  // red on
    digitalWrite(led_pins[2], LOW);   // blue off
  } else {
    digitalWrite(led_pins[1], LOW);   //red off
    digitalWrite(led_pins[2], HIGH);  //blue on
  }

  delay(1000);  //wait one second
}


/*****************************************************************
 * @brief:  gets the average temperature value from an array of temperature values
 * @param:  t_vals: the array that contains all of the temperature values 
 * @return: the average temperature value 
 */
float get_average_temperature(float *t_vals){
  float sum = 0.0;
  for(int i=0; i<NUM_TEMP_SENS; i++){
    sum += t_vals[i]; 
  }
  return sum / NUM_TEMP_SENS;
}
