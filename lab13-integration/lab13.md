# Introduction

Hello! Welcome to the 13th lab of Space School! In this lab we will work towards the final assemebly of the toastSat structure. We take all the pieces we have built these last few sessions, assemble them, and perform full system verification tests to ensure our toastSats are ready for flight! 

If you have any questions please feel free to reach out to Sydney Caulfeild, Emma Paczkowski, Sean Tedesco, Thomas Sears, or any other member of the QSAT Team. Contact info can be found in the [readme](https://github.com/queens-satellite-team/Space-School) of this repository. 

# Goals of Lab 13

1️⃣ Assemble payload with structure. 

2️⃣ Perform a full system shake test.

3️⃣ Perform a full system power test. 

# 1.0 Assembly

The final design of the toastSat structure can be seen below (left most image). The .STL file of this design can be found in the lab13 directory with the name: `qset-toastsat-rev1.STL`. The payload, battery, and charging circuit was integrated with the structure using a set of nylon spacers, nuts, and bolts. 

<p align="center">
	<img src="https://user-images.githubusercontent.com/48306876/162849605-0b830ec6-0740-41f6-ae24-4eeefc6f940c.png", width="400" ><img src="https://user-images.githubusercontent.com/48306876/162849074-34312d47-1583-411a-aee9-a5608c4f5d90.JPG", width="400" >
</p>

Lessons learned from this design include:
- The placement of the battery charger should be moved. The charger's connector to the battery is located too close to the logic-level converter and payload proto-board. 
- The battery comparment should be extended so that the entire length of the battery may sit flat against the toastSat. The battery must currently be inserted on an angle causing unneccessary and possibly damaging strain on the battery's diode protection circuit. 

# 2.0 Shake Test

**Description:** This is a simple test to quasi-simulate the effects on the payload from the balloon acsension, and balloon popping event.

**Equipment:**
- The only equipment that is required are your hands.

**Acceptance Criteria:** 
- 1) All components stay attached to the toastSat structure. 
- 2) There is no permantent deformation of the toastSat structure. 
- 3) All components are in the same condition as before the test (nothing broke). 

**Procedure:**
- 1. Ensure all screws, fasteners, and adhesive are well mated to the toastSat structure.
- 2. Grip the toastSat structure firmly with 1 or 2 hands. 
- 3. Oscillate the toastSat strucutre side to side to simulate the swaying of a balloon ascension with EXTREME SPEED!
- 4. Oscillate the toastSat strucutre up and down to simulate the bursting of the balloon with EXTREME SPEED!

# 3.0 Power Test

**Description:** This is a simple test to verify the nominal operation of the toastSat as it is fully assembled with battey, charging circuit, and payload.

**Equipment:**
- 1x Charged battery
- 1x Multimeter

**Acceptance Criteria:** 
- 1) Arduino and all other electrical components are powered through the battery and charging circuit.
- 2) The current draw of the toastSat is as expected from your power budget. 
- 3) Data is saved to the SD card and you can read from it. 
- 3) All components are in the same condition as before the test (nothing broke). 

**Procedure:**
- 1. Using the multimeter, verify all connections are isolated from one another (no shorts).
- 2. USing the multimeter, connect it in series 

