# Introduction

Hello! Welcome to the 10th lab of Space School! This lab will outline the requirements for the ToastSat structure. It should be noted that this lab is structured differently than those in the past.  Instead of the usual format that resembles the steps to completion, you could think of lab 10 as an assignment.  We will outline the necessary assumptions to be made, provide resources and definition of done to outline the acceptance criteria.  Due to the midterm schedule the first week of lab 10 will be done on your team's own time. 

If you have any questions please feel free to reach out to Emma Paczkowski, Sean Tedesco, Piper Steffen, Thomas Sears, or any other member of the QSAT Team (especially the mech team). Contact info can be found in the [readme](https://github.com/queens-satellite-team/Space-School) of this repository. 

## Summary
Thus far in our ToastSat journey each team has selected a sensor suite that has been used to create their payload which encompases both the arduino software and circuitry. There remain a few steps between where we are currently and launching the balloon. One, is that we need to talk to circuitry you have created on the breadboards and transfer it to a proto board. Two, we need to create a structure to hold all our pieces together. In an ideal world we would have done the steps in the above order, however, due to the pandemic we are creating the structure first. 

To build your design you will need to use some sort of CAD software.  You are welcome to use whichever software you wish, however, the team is most familiar with SOLIDWORKS. We are assuming that for those of you in first year, you would have downloaded SOLIDWORKS and received a license.  If you do not have access to SOLIDWORKS through school, please message Emma and she will provide the instructions to get a license through the design team.

## Information

### Assumptions to make
- The balloon gondola will be a styrofoam box that you will place your toastSat inside along with the other team's toastSats.
- A Lithium polymer battery will be included in your design to power the ToastSat.
- The Arduino and sensors are going to be soldered to a proto board and resemble the following schematic:
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

### Resources
A [SOLIDWORKS guidbook](https://github.com/queens-satellite-team/Space-School/blob/lab-10/lab10_structure_requirements/SolidWorks_Guide.pdf) has been created by Tye Dougherty, a member of QSET that may be a useful reference. 
  
## Definition of Done
A completed ToastSat structure will abide by the following acceptance criteria:
- The CAD model is within its allocated mass as defined in the teams mass budget.
- The CAD model includes an attachment mechanism to the balloon gondola.
- The CAD model is within a 10*10*10cm volume.
- The CAD model keeps all components of your design secure throughout the duration of the flight.
- The stl file has been emailed to emma.paczkowski@queensu.ca for printing! 
