# Introduction 
Salut! Welcome to the third lab of Space School! In this lab we take a small step back from the technical work done in the last two labs of Space School and pay some attention to the mission behind our toastSats. We look at the wide breadth of mission types on how satellites are used in order to gain some inspiration for developing our own simplified missions. We are then introduced to the design constraints and information regarding the balloon launch in order to guide our thoughts and implementation of our sensor suite. 


If you have any questions please feel free to reach out to Sydney Caulfeild, Emma Paczkowski, Sean Tedesco, Thomas Sears, or any other member of the QSAT Team. Contact info can be found in the [readme](https://github.com/queens-satellite-team/Space-School) of this repository. 

# Goals of Lab 3 

1️⃣ Determine mission for toastSat payload. 

2️⃣ Determine payload instrumentation to begin designing your sensor suite.

3️⃣ Consider constraints on the toastSat payload to guided implementation of your sensor suite.

# Satellite Mission Concepts 

## Communications
**Description** 

Connecting people through satellites can be easier than vast networks on the ground. 

**Topics** 

- [internet of things](https://en.wikipedia.org/wiki/Internet_of_things)
- [radio communications](https://en.wikipedia.org/wiki/Radio)
- [store-and-forward](https://en.wikipedia.org/wiki/Store_and_forward#:~:text=Store%20and%20forward%20is%20a,or%20to%20another%20intermediate%20station.)

**Examples**

- [TARS aka Kepler-2](https://space.skyrocket.de/doc_sdat/kepler-3.htm) (IoT and M2M communications) 
- [LEO Vantage 1](https://space.skyrocket.de/doc_sdat/leo-vantage-1.htm) (high-speed communications)

<img src="https://space.skyrocket.de/img_sat/kepler-3__1.jpg" height="250"> <img src="https://space.skyrocket.de/img_sat/telesat-leo-sstl__1.jpg" height="250">

## Earth Observation - Human
**Description** 

Provides a new perspective of life on Earth. 

**Topics** 
- [traffic](https://www.esa.int/esapub/bulletin/bullet115/chapter7_bul115.pdf)
- [pollution](https://www.epa.gov/sciencematters/tempo-new-era-air-quality-monitoring-space)
- [navigation](https://en.wikipedia.org/wiki/Satellite_navigation)

**Examples**

- [exactView 9](https://space.skyrocket.de/doc_sdat/exactview-1.htm) (tracking of marine vessels)
- [Claire](https://www.ghgsat.com/en/what-we-do/) (GHGSat-D, a GHG monitor) 

<img src="https://space.skyrocket.de/img_sat/exactview-1__1.jpg" height="250"> <img src="https://utias-sfl.net/wp-content/uploads/GHGSat-D-in-clean-room.jpg" height="250">


## Earth Observation - Other
**Description** 

There is plenty more than silly little people to watch from space. 

**Topics** 
- [Farming](https://www.farmersedge.ca/satellite-imagery/)
- [Ecosystems](https://www.asc-csa.gc.ca/eng/satellites/everyday-lives/monitoring-and-protecting-our-ecosystems-from-space.asp)
- [Mapping](https://www.cgg.com/geoscience/satellite-mapping)
- [General Imaging](https://www.nrcan.gc.ca/maps-tools-and-publications/satellite-imagery-and-air-photos/10782)

**Examples**
- [Wyvern](https://wyvern.space/) (farm land health)
- [NEMO-HD](https://space.skyrocket.de/doc_sdat/nemo-hd.htm) (real-time video downlink)

<img src="https://media2.spaceq.ca/wp-content/uploads/2021/04/01115651/AAC_Clyde_Space_EPIC-6U_Wyvern-310x165.jpg" height="250"><img src="https://space.skyrocket.de/img_sat/nemo-hd__1.jpg" height="250">

## Earth and Space Science
**Description**

The Earth and its atmosphere are worth studying from space!

**Topics** 
- [ionospheric measurements](https://en.wikipedia.org/wiki/Ionosphere)
- [space environment](https://en.wikipedia.org/wiki/Space_environment)
- [remote Earth measurements](https://earthdata.nasa.gov/learn/backgrounders/remote-sensing)

**Examples**
- [ConSat 1](https://space.skyrocket.de/doc_sdat/consat-1.htm) (South-Atlantic anomaly monitor)
- [Ex-Alta 1](https://albertasat.ca/ex-alta-1/) (space plasma physics), Killick-1 (sea ice)

<img src="https://space.skyrocket.de/img_sat/consat-1__1.jpg" height="250"><img src="https://space.skyrocket.de/img_sat/ex-alta-1__1.jpg" height="250">

## Astronomy
**Description** 

From space we can monitors stars and planets in a way that cannot be accomplished on Earth

**Topics** 
- [space weather](https://en.wikipedia.org/wiki/Space_weather)
- [astrophysics](https://en.wikipedia.org/wiki/Astrophysics)

**Examples**
- [CanX-3 BRITE constellation](https://space.skyrocket.de/doc_sdat/unibrite.htm) (stellar luminosity)
- [NEOSSAT](https://www.asc-csa.gc.ca/eng/satellites/neossat/Default.asp) (near Earth object monitor)

<img src="https://space.skyrocket.de/img_sat/canx-3__1.jpg" height="250"><img src="https://directory.eoportal.org/documents/163813/4315931/NeosSat_AutoD.jpeg" height="250">

## Chemical and Biological Experimentation
**Description** 

New reactions and behaviours occur in zero-gravity environments.

**Topics** 
- [drug performance](https://www.nasa.gov/feature/space-life-physical-sciences-research-and-applications-spacex-15-experiments-payloads)
- [biological behaviour](https://en.wikipedia.org/wiki/Astrobiology)

**Examples**
- [HERON Mk II](https://www.iai.co.il/p/heron-mk-ii) (infection experiment)

<img src="https://www.airforce-technology.com/wp-content/uploads/sites/4/2020/07/Image-2-Heron-MK-II-MALE-UAV.jpg" height="250">

## Technology Demonstration
**Description** 

Want to prove something works in a low-risk mission. 

**Topics** 
- [new materials](https://www.realclearscience.com/articles/2019/09/23/what_materials_keep_satellites_safe_in_space.html)
- [mechanism](https://www.ruag.com/en/products-services/space/spacecraft/satellite-mechanisms)
- [system](https://solarsystem.nasa.gov/basics/chapter11-1/)
- [hardware/software](https://www.nasa.gov/smallsat-institute/space-mission-design-tools)

**Examples**
- [CanX-4 and CanX-5](https://space.skyrocket.de/doc_sdat/canx-4.htm) (propulsion and formation flight)
- [CanX-7](https://directory.eoportal.org/web/eoportal/satellite-missions/c-missions/canx-7) (debris mitigation and aircraft monitor)

<img src="https://space.skyrocket.de/img_sat/canx-4__1.jpg" height="250"><img src="https://directory.eoportal.org/documents/163813/2954149/CanX7_Auto1E.jpeg" height="250">

## Education, Entertainment, Culture
**Description** 

With prices going down, opportunities for other missions go up.

**Topics** 
- [art](https://en.wikipedia.org/wiki/Art)
- [outreach](https://communityoutreach.ca/)
- [community building](https://www.nten.org/article/community-building-digital-inclusion/)
- [virtual reality](https://en.wikipedia.org/wiki/Virtual_reality)

**Examples**
- [AuroraSat](https://nwtresearch.com/research-projects/projects/sky-and-space/cubesat) (share indigenous culture with imagery and stories)
- [YukonSat](https://yukoncubesatellite.com/) (coding challenges for youth, sharing recordings)
- [Western CubeSat](https://cpsx.uwo.ca/research/Missions%20and%20Instruments/cubesat_project/index.html) (VR-ready camera)

<img src="http://beta12321.aurorapt.fi/wp-content/uploads/2020/11/Aurora_AuroraSat1_img_03-400x489.jpg" height="250"><img src="https://albertasat.ca/wp-content/uploads/sites/43/2021/03/YU-DEPLOYED-CDR.png" height="250"><img src="https://www.ctvnews.ca/polopoly_fs/1.5117213.1600891709!/httpImage/image.jpg_gen/derivatives/landscape_960/image.jpg" height="250">

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

[Resource Link](https://create.arduino.cc/projecthub/kiranpaul/light-magic-using-lm393-and-arduino-uno-14eadc)

### Accelerometer / Gyroscope
<img src="https://github.com/queens-satellite-team/Space-School/blob/c912eb47ebdadc9f7dc569c38bc38e4d7393ae3b/lab3/lab3-images/accelerometer.png" width="250">

[Resource Link](https://learn.adafruit.com/adafruit-mma8451-accelerometer-breakout/wiring-and-test)

### Barometric Pressure Sensor
<img src="https://github.com/queens-satellite-team/Space-School/blob/c912eb47ebdadc9f7dc569c38bc38e4d7393ae3b/lab3/lab3-images/barometric-pressure-sensor.jpeg" width="250">

[Resource Link](https://learn.sparkfun.com/tutorials/bmp180-barometric-pressure-sensor-hookup-/all)

### IR Sensor
<img src="https://github.com/queens-satellite-team/Space-School/blob/c912eb47ebdadc9f7dc569c38bc38e4d7393ae3b/lab3/lab3-images/ir-receiver-sensor.jpeg" width="250">

[Resource Link](https://create.arduino.cc/projecthub/Raushancpr/arduino-with-ir-sensor-1579b6)

### TMP36 Temperature Sensor 
<img src="https://github.com/queens-satellite-team/Space-School/blob/c912eb47ebdadc9f7dc569c38bc38e4d7393ae3b/lab3/lab3-images/temperature-sensor.jpeg" width="250">

[Resource Link](https://cdn-learn.adafruit.com/downloads/pdf/tmp36-temperature-sensor.pdf)

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
