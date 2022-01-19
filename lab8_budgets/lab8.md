# Introduction 
And we're back! Welcome to the eighth lab of Space School! We all hope you had an amazing holiday break, but now it is time for some more Space School. In this lab we are going to focus on a topic in engineering called `budgets`! These are extremely useful tools for engineers to characterize their space missions and start applying some real numbers to their mission design. 

If you have any questions, please feel free to reach out to Emma Paczkowski, Sean Tedesco, Piper Steffen, Thomas Sears, or any other member of the QSAT Team. Contact info can be found in the [readme](https://github.com/queens-satellite-team/Space-School) of this repository. 

# Goals of Lab 8

1️⃣ Learn what budgets are. 

2️⃣ Learn what budgets are included in spacecraft systems and how they are used.  

3️⃣ Begin working on your toastSat budgets. 

# Section 1: Budget Overview 📖

## 1.1 What is a budget? 

A spacecraft budget, much like your own spending budget, tracks what you need and compares it against what you can afford. These include cost budgets, as your customer likely only wants to pay you a fixed amount of money and you need to buy the parts and pay for labor to build your satellite, but they extend into allocating how much power, memory, temperature, and control you can *spend*.

> We will be talking about **satellite budgets** primarily, but this discussion is applicable to rovers and rockets as well.

Budgets can be (and often are) as simple as a spreadsheet that tallies what you know about the need or demand in your spacecraft. These numbers are combined, sometimes by simple addition and other times through more complicated analysis, and compared against your capacity or limits that you can afford in your satellite. A tangible example of this is a mass budget; you have a limit to how heavy your satellite can be, so you add up all the components and you must be below that limit. Some budgets are definitive (i.e., they tell you a clear result) while others are estimations that serve as a first step towards more detailed analysis.

## 1.2 What budgets are typically found on spacecraft?

There are no limits to what you can do a budget for on a spacecraft, but here is a list of some common examples.

### 1.2.1 Mass Budget
**Goal:** To ensure that the satellite stays within its mass budget.  
**Subsystems:** Usually the mechanical/structural subsystem is responsible for this budget, however, as all subsystems have a mass the consideration extends to all subsystems.  
**Constraints**: CubeSats have a predefined list of requirements which include a mass constraints. In the case of the toastSats by law the balloon has to stay within a mass constraint.  
**More Information:**  
  - Tracks the mass of **each component** of the satellite as well as the **uncertainty** of the mass value (i.e., how confident we are in this value), sums all the values together, and reports how far off the current design is from the absolute limit for the spacecraft;
  - Managed by a Systems Engineer or the Structure/Mechanical subsystem team;
  - For a CubeSat, mass budgets are often tracked in **kg** (as the mass limit is usually between 1 kg and 4 kg);
  - The mass budget is often divided by subsystem so we can track what portion of the total mass each system is using;
  - The primary output of the mass budget is the **mass margin**, expressed as a percentage of the maximum mass;
  - A positive margin indicates that the current mass is *below* the mass limit (i.e., good) and a negative margin indicates that the design is over budget (i.e., bad);
  - How much mass margin you want varies as the spacecraft moves through development, design, manufacturing, and launch preparation; start with a large mass margin and end with a small mass margin;
  - You want to have a large mass margin (maybe 10-20%) early in the design of the spacecraft in case some major problem arises later in the project;
  - Only one mass budget is maintained (typically), although other subsystems could informally maintain their own mass budgets if desired.

<p align="center">
  <img src ="https://user-images.githubusercontent.com/48306876/150068120-45627b82-f121-499e-9833-9c702d81ad09.png" width = "450" alt ="satellite component breakout">
</p> 

### 1.2.2 Power Budget  
**Goal:** To ensure the satellite can generate and store enough power to sustain the satellite on its mission.   
**Subsystem:** The Electric Power System (EPS)  
**Constraints**: The solar panels ability to generate power, the satellites orbit, how much power can be stored in the batteries, the speed at which the batteries change, discharge rate of the battery, power requirements from the rest of the satellite subsystems...  
**More Information:**

This budget will determine how well balanced power generation is with power consumption, with additional consideration for storage limitations of a battery system. Unlike the mass budget, the power generation and consumption is **dynamic**. We will need to explore these dynamics a little further in order to determine a simple way to estimate the power budget before moving on to more advanced techniques. To get started, let's discuss the basics of power generation, storage, and consumption.

#### Power Generation
Power generation occurs when the solar panels are exposed to the sunlight. We can estimate our input power as `P_in = I_solar * A_effective * e_panels`, where:
- `I_solar = 1361` W/m^2 is the [solar irradiance](https://en.wikipedia.org/wiki/Solar_irradiance#Irradiation_at_the_top_of_the_atmosphere) at the top of the Earth's atmosphere (i.e., the amount of useful solar power per unit area in orbit);
- `A_effective` (m^2) is the projected area of the satellite's solar panels perpendicular to the solar vector; and
- `e_panels` is the efficiency of the solar panels in converting solar power, which will vary depending on the unit selected (20% - 30%) as well as the age.

As long as we are about 1 AU from the Sun, we can assume `I_solar` will remain constant. Although constant, if/when the satellite ever enters a partial or complete shadow of the Earth, that irradiance will drop. For a first pass at estimating the power budget per orbit, we will need to determine how much time is spent in sunlight and eclipse.

To determine `A_effective`, we will need to know how much of the solar panels are exposed to sun. For body mounted solar panels, we need to know the orientation of the satellite. If a face covered with solar panels is directly facing the sun, `A_effective = A_solar-panels`. If the satellite is at an obscure angle to the sun, we will need to determine the projected area of the panels as well as the loss due to incidence angle [need more info]. If a satellite face without panels is facing the sun, then `A_effective = 0`. This factor is driven by the design of the satellite as well as the attitude at a given time. For an initial estimate, this can be determined by which **mode** the satellite is expected to be operating in.

#### Power Storage


#### Power Consumption


<p align="center">
  <img src ="https://user-images.githubusercontent.com/48306876/150068307-02cdcd60-a80a-4f97-95a8-0f02a54da525.png" width = "450" alt ="the little satellite that could">
</p> 

### 1.2.3 Link Budget
**Goal:** To ensure the communication system is going to be able to send and receive a clear signal  
**Subsystem:** Communication System (comms)  
**Constraints**: power gain from an amplifier, different antenna configurations, losses and gains...  
**More Information:**  
- Tracks all of the power gains and losses that a communication signal experiences during it's time starting from the transmitter, traveling through a medium, and picked up by the receiver;
- Gain is anything that provides additional power to the communication signal. This may include power sent from the transmitter, power from an amplifier, and using different antenna configurations;
- Losses are anything that takes away from the power (or introduces [noise](https://en.wikipedia.org/wiki/Noise_(signal_processing))) to the communication signal. This may include propagation loss, atmospheric absorption, resistances and impedances in the communication signal's path, and polarization mis-match;
- Power levels are expressed in decibel-milliwatt (dBm), and power gains and losses are expressed in decibels (dB). Both are logarithmic measurements; adding decibels is equivalent to multiplying the actual power; 
- For a satellite with two-way (duplex) communication, there is typically an uplink budget as well as a downlink budget. The direction of which is typically defined as an uplink from the ground to the satellite, and a downlink from the satellite to the ground;
- The primary output of the link budget is the **link margin**, expressed as a measure of power and is the amount by which the received power exceeds the sensitivity of the receiver;
- If the received power is sufficiently large (relative to the sensitivity of the receiver), which may be dependent on the communications protocol in use, the link will be useful for sending data;
- A good link budget will also provide a measure in power of how much your communication signal can be discerned from the surrounding noise level. This is called the [signal-to-noise ratio](https://en.wikipedia.org/wiki/Signal-to-noise_ratio). This is to ensure that the signal we are listening for is intelligible;

<p align="center">
  <img src ="https://user-images.githubusercontent.com/48306876/150067611-ca874038-5767-4beb-88c3-8bae0e72709d.png" width = "450" alt ="Friis Free-Space Radio Circuit">
</p> 

### 1.2.4 Data Budget
**Goal:** To ensure there is enough memory onboard the satellite for the mission's purpose.  
**Subsystem:** On Board Computer (OBC)  
**Constraints**: The amount of memory the satellite has access to, the information that your satellite is collecting, how long you need to store data for...  
**More Information:**
 - Data budget is tabulated calculation of data being generated in a system, data being stored and memory allocation for the same. 
 - In case of the satellite, the data budget will include data generated by payload instruments, health monitoring parameters, status variables, sensor data, etc. We need to ensure that sufficient data storage is available for them. 
 - In the case of your toastSats you would need to ensure that you have enough storage on your SD card to last you the duration of the flight.
### 1.2.5 Pointing Budget
**Goal:** Ensure the satellite is able to orient itself to a degree that is actually suitable for the mission. This is heavily dependent on the payload and may not be required
**Subsystem:** Attitude Determination and Control System (ADCS)
**Constraints**: satellite momentum, orbit, payload requirements
**More Information:**
Attitude Determination and Control System can be broken into two aspects. One, attitude determination which is the process of controlling the orientation of an aerospace vehicle with respect to an inertial frame of reference or another entity such as the celestial sphere. Two, attitude control which is what allows the satellite to maneuver itself to point at a specified location.  

### 1.2.7 Cost Budget
**Goal:** To ensure your satellite stays within the allocated cost.  
**Subsystem:** Operations.  
**Constraints**: How much money you have access to.  
**More Information:**  
You need money to build a satellite and without it you will not build a satellite. #sponsorQSET #sponsorSpaceSchool #GiveMeTheMoney #WhoLetsEmmaWriteTheseLabs  

## 1.3 What budgets are to be included for our toastSats and why? 

# Section 2: toastSat Mass Budget 🏋️
Now that we have learned some of the ins and outs of spacecraft budgets, we are going to make the first budget for our toastSats. The goal for this section is to create your **mass budget**. Once teams are finished with their budgets, we hope to share them with the rest of Space School next session and highlight the creativity you can have with creating your budgets!  

## 2.1 Helpful Style Guides
While budgets are tools that engineers use to characterize their systems and missions, they are also documents that are _alive_, read by many team members, and iterated upon. As such, a budget should be able to read for team members from different backgrounds, and be able to be easily used. Below are some helpful pointers for you to think about while attempting to create your budgets. 

1. Budgets ask and answer the question: "Given these inputs, what are the outputs?", so how may we highlight these two important properties?
1. Budgets may contain considerations and calculations that go into budgets, how may we share the justification that went into these?
1. Budgets may contain unknown symbols and colors, how may we provide an easy to read way for users to understand the meaning of these symbols and colors? 
1. Budgets may contain many numerical values, how may we differentiate and give context to these values from one another?  
1. Budgets may contain parameters with a level of uncertainty, how may we include this level of uncertainty? 

## 2.2 Additional Mass Budget Information 
The target mass of your toastSat is 100 grams. This includes all of the components outlined in the image below (electrical components, protoboard, structure, and wired connection to the "Toaster" power system). 

<p align="center">
  <img src ="https://user-images.githubusercontent.com/48306876/148651483-f6d84dc8-4b3b-412c-906e-6323e64390ae.png" width = "450" alt ="Nominal toastSat system ">
</p> 


