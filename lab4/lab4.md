# Introduction 

# Goals of Lab 4

# 1.0 Photoresistive Sensor

## 1.1 Hardware Requirements

## 1.2 Software Requirements

## 1.3 Example

# 2.0 Accelerometer

## 2.1 Hardware Requirements

## 2.2 Software Requirements

## 2.3 Example

# 3.0 Barometric Pressure Sensor

## 3.1 Hardware Requirements

## 3.2 Software Requirements

## 3.3 Example

# 4.0 IR Sensor

## 4.1 Hardware Requirements

## 4.2 Software Requirements

## 4.3 Example

# 5.0 Temperature Sensor 🌡️
The TMP35/TMP36/TMP37 are low voltage, precision centigrade temperature sensors. They provide a voltage output that is linearly proportional to the Celsius (centigrade) temperature. The TMP35/ TMP36/TMP37 do not require any external calibration to provide typical accuracies of ±1°C at +25°C and ±2°C over the −40°C to +125°C temperature range. **[Datasheet](https://cdn-learn.adafruit.com/assets/assets/000/010/131/original/TMP35_36_37.pdf)**

## 5.1 🛠️ Hardware Requirements
- 2.7 V to 5.5 V Maximum Input Supply 
- The TMP36 is specified from −40°C to +125°C, provides a 750 mV output at 25°C. 
- Analog Signal Ouput 

## 5.2 💻 Software Requirements
- Analog to Digital Conversion : Digial Voltage Value = Analog Input Voltage * Input Voltage / 1024.0  
- Conversion Factor: Temperate C = [Vout in mV - 500mV] / (10mV / 1 °C)

## 5.3 Example

```
// set the analog input pin
int input_pin = 0;
// set global variables 
int analog_data;
float voltage_reading;
float temperatureC; 
	@@ -57,10 +64,10 @@ void setup()
void loop()
{
  // read the analog input
  analog_input = analogRead(sensor_pin);
  
  // convert analog input to a voltage value
  voltage_reading = analog_input * (5.0/1024.0); 
  
  // convert voltage value to a temperature value
  temperatureC = (voltage_reading - 0.5) * 100; 
  
``` 

   
# 6.0 [SD Card Writer](https://www.digikey.ca/en/products/detail/4682/1528-4682-ND/12822319?itemSeq=377815692)
[data sheet](https://cdn-learn.adafruit.com/downloads/pdf/adafruit-microsd-spi-sdio.pdf)  

## 6.1 Hardware Requirements
### Pinouts 📌
  -  Power Pins
      - **3V** - This is the power pin. MicroSD cards must use 3.3V, so take care to only hook 3.3V to this pin. Hooking 5V or VBAT to this pin will damage your microSD card.
     - **GND** - common ground for power and logic.
  - Common Logic Pins
    - **DET** - Detect whether a microSD card is inserted. This pin is connected to **GND** internally when there's no card, but when one is inserted it is pulled up to **3V** with a 4.7kΩ resistor. That means that when the pin's logic level is **False** there's no card and when it's **True** there is.
   - SPI Logic Pins
     If you're using SPI to connect to your SD cards, the pins have the following functions:
      - **CLK** - This is the SPI **C**lock pin /** SCK** **S**erial **C**lock, its an input to the chip.
      - **SO** - this is the **S**erial **O**ut / Microcontroller **I**n **S**erial **O**ut pin, for data sent from the SD card to your processor.
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

## 6.2 Software Requirements

## 6.3 Example

