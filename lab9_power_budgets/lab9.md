# Introduction 
And we're back! Welcome to the ninth lab of Space School! We are continuing with our discussions on spacecraft budgets this week, focusing our attention to the power sub-system (EPS) and the `power budget`. Recall, that these budgets are extremely useful tools for engineers to characterize their space missions and start applying some real numbers to their mission design. The collection of budgets along with the list of system requirements is the foundation of any practical mission.

If you have any questions, please feel free to reach out to Emma Paczkowski, Sean Tedesco, Piper Steffen, Thomas Sears, or any other member of the QSAT Team. Contact info can be found in the [readme](https://github.com/queens-satellite-team/Space-School) of this repository. 

# Goals of Lab 9

1️⃣ Learn the ins and outs of a satellite power budget. 

2️⃣ Begin working on your toastSat power budget.  

# Section 1: Power Budget Overview 📖
- what is power?
- what is energy? 
- ohm's law and equations for power

To get started, let's discuss the basics of power generation, storage, and consumption.

## 1.1 Power Source and Generation
Power generation occurs when the solar panels are exposed to the sunlight. We can estimate our input power as `P_in = I_solar * A_effective * e_panels`, where:
- `I_solar = 1361` W/m^2 is the [solar irradiance](https://en.wikipedia.org/wiki/Solar_irradiance#Irradiation_at_the_top_of_the_atmosphere) at the top of the Earth's atmosphere (i.e., the amount of useful solar power per unit area in orbit);
- `A_effective` (m^2) is the projected area of the satellite's solar panels perpendicular to the solar vector; and
- `e_panels` is the efficiency of the solar panels in converting solar power, which will vary depending on the unit selected (20% - 30%) as well as the age.

As long as we are about 1 AU from the Sun, we can assume `I_solar` will remain constant. Although constant, if/when the satellite ever enters a partial or complete shadow of the Earth, that irradiance will drop. For a first pass at estimating the power budget per orbit, we will need to determine how much time is spent in sunlight and eclipse.

To determine `A_effective`, we will need to know how much of the solar panels are exposed to sun. For body mounted solar panels, we need to know the orientation of the satellite. If a face covered with solar panels is directly facing the sun, `A_effective = A_solar-panels`. If the satellite is at an obscure angle to the sun, we will need to determine the projected area of the panels as well as the loss due to incidence angle [need more info]. If a satellite face without panels is facing the sun, then `A_effective = 0`. This factor is driven by the design of the satellite as well as the attitude at a given time. For an initial estimate, this can be determined by which **mode** the satellite is expected to be operating in.

## 1.2 Power Storage

## 1.3 Power Distribution, Regulation, & Control

# Setion 2: toastSat Power Budget 🔋

## 2.1 Helpful Style Guides
While budgets are tools that engineers use to characterize their systems and missions, they are also documents that are _alive_, read by many team members, and iterated upon. As such, a budget should be able to read for team members from different backgrounds, and be able to be easily used. Below are some helpful pointers for you to think about while attempting to create your budgets. 

1. Budgets ask and answer the question: "Given these inputs, what are the outputs?", so how may we highlight these two important properties?
1. Budgets may contain considerations and calculations that go into budgets, how may we share the justification that went into these?
1. Budgets may contain unknown symbols and colors, how may we provide an easy to read way for users to understand the meaning of these symbols and colors? 
1. Budgets may contain many numerical values, how may we differentiate and give context to these values from one another?  
1. Budgets may contain parameters with a level of uncertainty, how may we include this level of uncertainty?

## 2.2 Additional Power Budget Information 
Each toastSat will be powered through its USB connector connected to a [3.3V-5.0V boost-converter](https://www.pishop.ca/product/powerboost-1000-charger-rechargeable-5v-lipo-usb-boost-1a-1000c/) and a [3V7 12000 mAh battery](https://www.pishop.ca/product/lithium-ion-polymer-battery-3-7v-1200mah-603450/). Note that the toastSats are powered with 5.0 volts, but the battery has a nominal voltage of 3.7 volts, so the power conversion must be made. 

<p align="center">
  <img src ="https://user-images.githubusercontent.com/48306876/150847412-c4bcf39c-c56c-4b6a-947d-5179428e49b0.png" width = "450" alt ="boost converter"><img src ="https://user-images.githubusercontent.com/48306876/150847198-2602ffab-c3d7-419e-a0dd-080b975f62a4.png" width = "450" alt ="toastSat battery">
</p> 

