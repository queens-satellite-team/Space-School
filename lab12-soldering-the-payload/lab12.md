# Introduction

Hello! Welcome to the 12th lab of Space School! This lab will showcase the steps to soldering your payload. Each one of your toastSats will be slightly different, but this lab will cover some design considerations that you can use while undertaking your own soldering work.

If you have any questions please feel free to reach out to Emma Paczkowski, Sean Tedesco, Piper Steffen, Thomas Sears, or any other member of the QSAT Team (especially the mech team). Contact info can be found in the [readme](https://github.com/queens-satellite-team/Space-School) of this repository. 

# Goals of Lab 12

1️⃣ Solder all your payload components. 

2️⃣ Solder all your payload connections.

3️⃣ Verify all hardware connections. 

# 1.0 Layout

The first thing that we should do when undertaking a soldering project is determine the layout of components. This will ensure that all our components will fit onto our board, as well as help with routing wires as we will fix the termination points in place that we will connect with wires later on. 

As you are laying out your components there are a few things to consider: 
- Think ahead about how you want your wires routed. It is much easier for troubleshooting if wires are not crossed and tangled. 
- We are working with small connection points, so it is desirable to minimize that amount of wires that get connected to a single location. 
- Wires take up physical space and so do your fingers. Leave space between components to help yourself place wires and hold them down for soldering. 

An example layout is given below:

<p align="center">
	<img src="https://user-images.githubusercontent.com/48306876/155917109-3a89dd61-fdab-4631-ae89-aea3025d1ae6.png", width="400" >
</p>  

# 2.0 Soldering the Components

Now onto soldering! Here are some possibly helpful tips that I learned while soldering this payload: 

- Plastic burns. Avoid placing the soldering iron directly on the plastic shielding of the wire. 
- Different connection points and wires operate at different voltages and with different protocols. Use differently colored wires to distinguish between non-common circuitry. 
- It is diffcult to hold the component / wire in place while also soldering. Use a rubber band, sticky tack, or gripper to help secure things in place. 

<p align="center">
	<img src="https://user-images.githubusercontent.com/48306876/157448390-14d403fb-b6f8-4fa4-86f3-6ef9ef82ac2f.png"  width="200">
</p> 

There is limited room on the protoboard to route wires, and having all wires routed on the bottom may lead to unnecessary crossing and overlapping. I found using header pins as seen below helped by allowing wires to be routed on the top layer which I used to seperate the power and ground lines. This also helped if I had to replace a part or wanted to use any one in another project as there was no need for desoldering of the main components.

<p align="center">
	<img src="https://user-images.githubusercontent.com/48306876/157106854-d95d4ec4-4a6f-4b07-a13c-9391b4bc4593.png" width="200" >
</p> 

❗ **NOTE** ❗ These are optional tips, but highly encouraged. If you have any other helpful tips please share them with a member of the Space School team and we can include them in the lab. 

## 2.1 Soldering the Arduino and Temperature Sensor

Sean forgot to take photos of this step.... please excuse this foolishness. 

## 2.2 Soldering the Logic-Level Shifter

Sean also forgot to take photos of this step.... what a guy...

## 2.3 Soldering the SD-Card Reader

<p align="center">
	<img src="https://user-images.githubusercontent.com/48306876/157108013-cd44a7e6-4b2c-4964-a180-c7529be59a90.jpg"  width="400"><img src="https://user-images.githubusercontent.com/48306876/157110511-3232cf90-d1f6-4f9c-ab0d-e907f0995c21.png"  width="400">
</p>

## 2.4 Soldering the Pressure Sensor

<p align="center">
	<img src="https://user-images.githubusercontent.com/48306876/157110775-8d3aa1dc-3690-4324-bae5-607842ee921b.png"  width="400"><img src="https://user-images.githubusercontent.com/48306876/157110898-fa5697e0-64c4-4262-9e72-40df4e4605a3.png"  width="400">
</p>  

## 2.5 Soldering the LED Circuit

<p align="center">
	<img src="https://user-images.githubusercontent.com/48306876/157115223-0cbc66a6-bab5-4885-9929-472c500cacb2.jpg"  width="400"><img src="https://user-images.githubusercontent.com/48306876/157111291-d4274201-5c37-4455-8b22-0b8b79f2bc65.png"  width="400">
</p> 

## 2.6 Final Soldered Layout

<p align="center">
	<img src="https://user-images.githubusercontent.com/48306876/157106854-d95d4ec4-4a6f-4b07-a13c-9391b4bc4593.png" width="300" ><img src="https://user-images.githubusercontent.com/48306876/157107176-a7a7a06c-80e8-4da2-a19d-c3bf4e700c33.png" width="300"><img src="https://user-images.githubusercontent.com/48306876/155917277-68a2d10a-2332-46e3-8406-6a132b309a7c.png"  width="300">
</p>  

# 3.0 Soldering the Connections
## 3.1 Power and Ground

<p align="center">
	<img src="https://user-images.githubusercontent.com/48306876/157445668-a9fcffb3-f310-408a-ad5a-1283123bda8f.png"  width="400"><img src="https://user-images.githubusercontent.com/48306876/157445838-bdc015ae-c5a9-4fcd-b88f-988933cbbcf7.png"  width="400">
</p>  

## 3.2 Signals

### 3.2.1 BMP180 SCL and SDA

<p align="center">
	<img src="https://user-images.githubusercontent.com/48306876/157446463-309534e2-8763-47e9-9b7a-ad9af9b944ae.png"  width="400"><img src="https://user-images.githubusercontent.com/48306876/157446481-b1dfec78-a7c0-4d04-acc7-c1ff223c9baa.png"  width="400">
</p>  

### 3.2.2 SD Card Reader SPI

<p align="center">
	<img src="https://user-images.githubusercontent.com/48306876/157446773-f37b3664-fa21-497e-89c3-02f61cb44698.png"  width="400"><img src="https://user-images.githubusercontent.com/48306876/157446792-24f90ba2-cf22-46c4-8701-bb629ddcafe0.png"  width="400">
</p>


### 3.2.3 Logic Level Converter Lines

<p align="center">
	<img src="https://user-images.githubusercontent.com/48306876/157447162-03ee6f8e-0334-49a2-b339-36126135633b.png"  width="400"><img src="https://user-images.githubusercontent.com/48306876/157447196-b257f91b-54cc-40a7-b4b8-632a09440211.png"  width="400">
</p>

### 3.2.4 Arduino LED and TMP36 Sensor

<p align="center">
	<img src="https://user-images.githubusercontent.com/48306876/157447424-1cb2d382-8b7a-4233-9756-66eb61c655b4.png"  width="400"><img src="https://user-images.githubusercontent.com/48306876/157447470-4ab09ee4-23e8-454b-aaf5-9a97c95b1aed.png"  width="400">
</p>

## 3.3 Final Touches

<p align="center">
	<img src="https://user-images.githubusercontent.com/48306876/157447919-00b6136a-8d35-4ce0-b255-24bed98c1e92.png" width="300" ><img src="https://user-images.githubusercontent.com/48306876/157447903-0f8523da-26af-47de-ae3a-a2c5dd7ec90e.png" width="300"><img src="https://user-images.githubusercontent.com/48306876/157447913-42b78c16-87c1-444f-94db-54dd190ac153.png"  width="300">
</p>  

# 4.0 Verify Connections

After you are finsihed soldering, please do not power on your toastSat yet! You should verify if all conections are made between connection points, as well as there is no continuity between unlike pins. You can use a multimeter for this step in `resistance mode`. 

<p align="center">
	<img src="https://user-images.githubusercontent.com/48306876/157448216-20293ef7-8613-49d0-ad81-85fe48879c1d.png"  width="400">
</p>
