# Introduction 
Salut! Welcome to the third lab of Space School! In this lab we take a small step back from the technical work done in the last two labs of Space School and pay some attention to the mission behind our toastSats. We look at the wide breadth of mission types on how satellites are used in order to gain some inspiration for developing our own simplified missions. We are then introduced to the design constraints and information regarding the balloon launch in order to guide our thoughts and implementation of our sensor suite. 

If you have any questions please feel free to reach out to Emma Paczkowski, Sean Tedesco, Piper Steffen, Thomas Sears, or any other member of the QSAT Team. Contact info can be found in the [readme](https://github.com/queens-satellite-team/Space-School) of this repository. 

# Goals of Lab 3 

1️⃣ Determine mission for toastSat payload. 

2️⃣ Determine payload instrumentation to begin designing your sensor suite.

3️⃣ Consider constraints on the toastSat payload to guided implementation of your sensor suite.

# Satellite Mission Concepts 

## Communications

## Earth Observation - Human

## Earth Observation - Other

## Earth and Space Science

## Astronomy

## Chemical and Biological Experimentation

## Technology Demonstration

## Education, Entertainment, Culture

# toastSat Design 
The design of the toastSat is to be the most simple and barebones product that can highlight key features of a potential large-scale mission. Each toastSat will be put into a carrier vessel, dubbed the "Toaster", and that carrier vessel will be attached to a weather balloon. As there is limited space in the Toaster, each toastSat must be light weight, have low power cunsumption, and fit within a certian volume. The toastSats are also limited in their procesing power and how much memory they have so software intensive missions such as broadcasting and imaging may exist out of the scope of toastSats. The toastSats are to be built within a small timeframe of one semester so their mission scope must be also simplified. In order for a successful design and mission under all of these considerations, our toastSats will take on the KISS (keep it simple, silly) philosophy. Every aspect of the toastSat design will be simplified, but it will work. 

## Flight Details 
We must know the conditions of the flight in order to better design our toastSat. The flight details are listed below and some guiding questions are asked in order for you to start thinking how these conditions may affect your toastSat design. As an additional note, we have control of our own launch so we can ensure that these flight conditions will always be met. 

🎈🎈🎈

|Flight Details| |
| --- | --- |
|Flight Duration | 4 hours |
|Maximum Altitude | 30 km |
|Time of Day at Launch | Daytime (afternoon) |
|Weather | No rainfall, no snowfall. Wind speeds ideally less than 5 km/h. |

❓ Is the toastSat to collect data for the entire 4 hour duration of the flight? 

❓ Does the daytime launch affect your intially conceived mission? 

❓ What kind of conditions are present in the atmosphere 30 km above sea level? What are the expected temperatures? 

❓ What kind of motion do you think the toastSat will experience as it makes its ascent 30 km into the sky, and then its descent back to the Earth? 

## Constraints 
Spacecraft design is governed by what are called *budgets*. There are typically 7 budgets that space engineers must consider when undertaking a design. These budgets state what the spacecraft can afford or allow in their respected field. While not all of these budgets apply to the toastSat design, they are mentioned below. 

- **Mass Budget:** the mass budget outlines all the sources of mass to the satellite and provides a maximum mass that the space craft can be. 

- **[Delta-V and Propellant Budget](https://en.wikipedia.org/wiki/Delta-v_budget):** the delta-v budget outlines how much propellant is required for a spacecraft in order to perform all of its maneuvers in space given a mass and certian propulsion system.

- **Power/Energy Budget:** the power buget outlines all areas that generate power for the satellite and all areas that use up power in the satellite.

- **Data Budget:** the data budget outlines all the sources that generate data stating how much and at what frequency that data is procured. 

- **[Link Budget](https://en.wikipedia.org/wiki/Link_budget):** the link budget outlines all of the power gains and losses that a communication signal experiences when transmitted and states how much power ends up being received at the other end of a communication system. 

- **[Pointing Error Budget](http://peet.estec.esa.int/files/ESSB-HB-E-003-Issue1(19July2011).pdf):** the pointing error budget outlines all areas internal and external to the spacecraft that could cause the satellite to deviate away from where it needs to look (to point its antennas for communication, point its camera or sensor for the payload, or point towards the sun to recharge its batteries using its solar cells). 

- **Cost Budget:** the cost budget outlines the dollar value for all components within the satellite, as well as amount of engineering time put into the satellite with an associated hourly dollar rate.  

The budget for each toastSat is summarized in the table below. The values within the table outline the maximum allowable budget for the applicable areas of our toastSats. In a future lab you will characterize your toastSat in order to express if and how well your toastSat fits within each of its budget.  

🚀 🚀 🚀
| MASS | VOLUME | DELTA-V | POWER | DATA | LINK | POINTING | COST |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 100 grams | 10cm x 10cm x 5cm | N/A | 800 mAh @ 3.7 volts | 4 GB | N/A | N/A | N/A |

## toastSat Sensors 

### Photoresistive Sensor
<img src="https://github.com/queens-satellite-team/Space-School/blob/c912eb47ebdadc9f7dc569c38bc38e4d7393ae3b/lab3/lab3-images/photosensitive-resistance-sensor.png" width="250">

### Accelerometer / Gyroscope
<img src="https://github.com/queens-satellite-team/Space-School/blob/c912eb47ebdadc9f7dc569c38bc38e4d7393ae3b/lab3/lab3-images/accelerometer.png" width="250">

### Barometric Pressure Sensor
<img src="https://github.com/queens-satellite-team/Space-School/blob/c912eb47ebdadc9f7dc569c38bc38e4d7393ae3b/lab3/lab3-images/barometric-pressure-sensor.jpeg" width="250">

### IR Sensor
<img src="https://github.com/queens-satellite-team/Space-School/blob/c912eb47ebdadc9f7dc569c38bc38e4d7393ae3b/lab3/lab3-images/ir-receiver-sensor.jpeg" width="250">


### TMP36 Temperature Sensor 
<img src="https://github.com/queens-satellite-team/Space-School/blob/c912eb47ebdadc9f7dc569c38bc38e4d7393ae3b/lab3/lab3-images/temperature-sensor.jpeg" width="250">

# Homework
Before proceeding to the next lab, seriously consider how you want to use these sensors. Consider their hardware requirements, and a logical flow to acquiring data. Some guiding questions are asked below.

❓ How much current do the sensors draw, how much voltage do they need to operate?

❓ What kind of communication lines do you need between your Arduino and the sensor?

❓ Is the data from the sensors an analog value or a digital value?

❓ Is there more than a single value you can read from the sensor?

❓ What kind of code would go in a *setup function*?

❓ What kind of code would go into a function that would let the sensor continuouly run on *loop*?

❓ How often are you to measure data from the sensor?

❓ How should the data be displayed, or saved so it easy to read?
