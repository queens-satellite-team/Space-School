# Introduction

Hello! Welcome to the 10th lab of Space School! This lab will outline the requirements for the toastSat structure. It should be noted that this lab is structured differently than those in the past; instead of the usual format that resembles the steps to completion, you can think of lab 10 as an **assignment**. We will outline the necessary assumptions that can be made regarding the housing for all of the toastSats (the Toaster), provide resources to help guide the design of the structure, and a definition of what a completed assignment looks like (a _definition of done_).  Due to the midterm schedule the first week of lab 10 will be done on your team's own time. 

If you have any questions please feel free to reach out to Emma Paczkowski, Sean Tedesco, Piper Steffen, Thomas Sears, or any other member of the QSAT Team (especially the mech team). Contact info can be found in the [readme](https://github.com/queens-satellite-team/Space-School) of this repository. 

## Summary
Thus far in our toastSat journey each team has selected a sensor suite that has been used to create their payload which encompases both the arduino software and circuitry. There remain a few steps between where we currently are and launching the balloon. These include:

1. Take the circuitry you have created on the breadboards and transfer it to a proto board by soldering.
2. Create a structure to hold all our pieces together. 
 
In an ideal world we would have done the steps in the above order; however, due to the pandemic we are creating the structure first. In a future lab, we will solder all our components currently on our breadboards to the protoboard. 

To build your design you will need to use some sort of CAD software. You are welcome to use whichever software you wish; however, the team is most familiar with SOLIDWORKS. We are assuming that for those of you in first year, you would have downloaded SOLIDWORKS and received a license. If you do not have access to SOLIDWORKS through school, please message Emma and she will provide the instructions to get a license through the design team.

## Information

### Assumptions about the Toaster
- The balloon gondola (the Toaster) will be a styrofoam box that you will place your toastSat inside. Every teams' toastSat must fit within this box so each team is given a set amount of real estate.
- A lithium polymer battery and a voltage converter will be included in your design to power the toastSat.
- The Arduino and sensors are going to be soldered to a proto board: 
<p align="center">
	<img src="https://github.com/queens-satellite-team/Space-School/blob/bdc5d253e56b7bd8f739a648554446e31c1b4820/lab10_structure_requirements/lab10_images/toastSat_protoboard.jpg"  width="350" height="400">
</p>  

-  Your overall toastSat payload will resemble the following schematic:
<p align="center">
	<img src="https://github.com/queens-satellite-team/Space-School/blob/8c393409f64878e1a0354ddb222df66c70fc3d28/lab10_structure_requirements/lab10_images/toasSat_schematic.JPG"  width="350" height="400">
</p>    

### Part Dimensions
- Protoboard:
  - 5cm x 7cm x 0.16cm (length x width x height)
  - Hole Diameter: 2mm
  - Lengthwise mounting hole distance: 66mm
  - Widthwise mounting hole distance: ~46.4mm
  - Link: https://www.adafruit.com/product/  
<p align="center">
	<img src="https://github.com/queens-satellite-team/Space-School/blob/8c393409f64878e1a0354ddb222df66c70fc3d28/lab10_structure_requirements/lab10_images/proto-board.jpg"  width="400" height="350">
</p> 

- Lithium Ion Polymer Battery
   - Dimensions: 6x34x50mm  
   - Link: https://www.pishop.ca/product/lithium-ion-polymer-battery-3-7v-1200mah-603450/  
<p align="center">
	<img src="https://github.com/queens-satellite-team/Space-School/blob/8c393409f64878e1a0354ddb222df66c70fc3d28/lab10_structure_requirements/lab10_images/lithium_ion_polymer_battery.jpg"  width="400" height="350">
</p>  

- Power Boost Converter
	- Dimensions  (in mm) see below image: 
	- Link: https://www.adafruit.com/product/2465
<p align="center">
	<img src="https://github.com/queens-satellite-team/Space-School/blob/3156feea53e19a08fa2a44ec755f1e6d3d0984d0/lab10_structure_requirements/lab10_images/toastSat_boost_converter.jpg"  width="400" height="350"><img src="https://github.com/queens-satellite-team/Space-School/blob/b6a4e73f920efe0eff00390e7f78dc009a870e7f/lab10_structure_requirements/lab10_images/toastSat_boost_converter_dimensions.jpg"  width="400" height="350">
</p> 



### Resources
A [SOLIDWORKS guidbook](https://github.com/queens-satellite-team/Space-School/blob/lab-10/lab10_structure_requirements/SolidWorks_Guide.pdf) has been created by Tye Dougherty, a member of QSET that may be a useful reference. 
  
## Definition of Done
A completed ToastSat structure will abide by the following acceptance criteria:

- [ ] The CAD model is within its allocated mass as defined in the teams mass budget (the total system mass is less than 94 grams).
- [ ] The CAD model includes an attachment mechanism to the balloon gondola.
- [ ] The CAD model is within a 10 x 10 x 10 cm volume.
- [ ] The CAD model keeps all components of your design secure throughout the duration of the flight.
- [ ] The stl file has been emailed to emma.paczkowski@queensu.ca for printing!
