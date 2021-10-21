# Introduction 
Hello! Welcome to the fifth lab of Space School! In this lab we are going to begin with some soldering basics to help prepare for the undertaking of soldering your entire payload. In this lab you will find some basic guidelines and tips to perform various soldering tasks sush as installing a component and removing components.

If you have any questions, please feel free to reach out to Emma Paczkowski, Sean Tedesco, Piper Steffen, Thomas Sears, or any other member of the QSAT Team. Contact info can be found in the [readme](https://github.com/queens-satellite-team/Space-School) of this repository. 

# Goals of Lab 5

We will learn how to...

1️⃣ Prepare our design, and work station in order to solder. 

2️⃣ Solder components together. 

3️⃣ Remove components that have been soldered. 

4️⃣ Clean up the mess left behind. 

# Step 0 Motivation 

There are many ways to assemble a circuit together, with the most common way to start being with a breadboard. However, there are a few issues when working with breadboards. 

| Breadboard Advantages | Breadboard Disadvantages | 
| --- | --- | 
| It has easy to quick to check for easy and complex circuits both and it has easily verified circuits at the initial stage, so it can save time. | It is unreliable. |
| Quick to check component around. | Difficult to replicate. |
| It is easy to adjust. | It is temporary. |
| It is flexible. | It is heavier. |
| No drilling holes. | A breadboard is noisier than properly laid-out circuit boards, sometimes far too noisy. |
| No soldering required. | It is difficult to troubleshoot due to human error and some poor connections problem. |
| It can be debugged easily. | It almost always, take up more physical space than the final circuit board design. |
| A solderless connection makes it reusable. | Difficult to modify complex SMD component for prototyping. |
| Cheap and connections can be changed. | It works very poorly for high-speed design. |

## Step 1 - Setup and Preparation

Soldering is the process of A typical soldering setup will look like the setup below. 

<img src="https://user-images.githubusercontent.com/48306876/138369534-d5a16ec6-54cc-47ad-b637-541d8964920c.png" width=250 height=250> 

The tools in your arsenal include: 

- Soldering Iron
  - This is what melts the solder 
The sponge is to clean the tip of the soldering iron and remove any excess solder.


**Confirm what needs to be done!**
  - Confirm that component part numbers, resistor values, etc. are all correct. 
  - Confirm the component orientation (headers, diodes, etc.). 
  - Confirm the nominal layout of your design (are buttons accesible, LEDs visible). 

**Clean components and work area.**
  - Use a small brush to lightly brush away any foreign object debris (FODs) such a dust, hair, small particles.
  - Use isopropyl alcohal and a cotton swab to remove any residues or marks on your components. 

**Determine what kind of soldering is being used.**
  - Solder can come leaded or lead-free. With QSET, you will be only using lead-free solder, but going out in industry you may encounter leaded solder.
  - If using leaded solder, ensure you have sufficient venthilation (it is better not to breathe it in). 
  - Turn on the fume extractor, or perform your soldering outside. 

![image](uploads/85431f243382de70aaa384eb5055f91a/image.png)

- **Solder thickness** to be chosen depending on nature of rework. Usually:
  - Thinnest for SMT resistors
  - A bit larger for THT pins
- **Iron temperature**: ~760degF, a bit hotter if large thermal inertia (GND traces, large components)

## Removing resistors/capacitors

To remove a resistor or capacitor:

- Apply flux on both solder joints

![image](uploads/5de0662c32a5365de5e71f4955c12f10/image.png)
- Use 2 irons to reflow both joints simultaneously
  - The component should come off smoothly, sticking to one of the irons.
  - If it sticks to one pad, you can reflow that joint while gently pulling the component with tweezers

![image](uploads/e6abb2b53c5e86b7c1f7dc5a26214add/image.png)
- Clean the pads to remove leftover solder, using solder braid.
  - Common mistakes to avoid:
    - Using too large braid
    - Overheating the pads (re-apply flux as necessary)
  - The pads should end up clean and flat.

![image](uploads/a255e3f9eb986869d3a4eb57b9f63775/image.png)


## Soldering resistors/capacitors

To solder a resistor or capacitor:

- Check the resistor/capacitor value with a DMM
- Apply flux on pad A
- Put a tiny amount solder on the iron tip, then quickly transfer to pad A
  - To form a small shiny uniform dome on pad A 

![image](uploads/4d296528bcdc976c39a6df951d2692da/image.png)
- Position component and hold it in place with tweezers. 
  - Because of the presence of solder on pad A, it will rest at an angle from the PCB

![image](uploads/d067f00c6a5fcdf3a1669f77694b1b42/image.png)
- Reflow solder on pad A
  - The component should now be flush against the PCB.

![image](uploads/5ca400c836b9cf485265c8a1801b6653/image.png)
- Apply flux on pad B
- Put a tiny amount of solder on the iron tip, then quickly transfer to pad B

![image](uploads/225e88e751b2620c433d34cea8e77211/image.png)
- Touch-up either side that requires it to meet IPC Class III criteria (joint concavity, aspect, dimensions, quantity of solder, etc.)

![image](uploads/2f0f6accfd2f227ec8166a98a2df1040/image.png)

## Soldering THT connectors

![image](uploads/914af68417070c432f59f76ab9e50daa/image.png) **Through hole connectors cannot be de-soldered**, so make sure you’re doing the right thing!

To solder a power barrel/RJ45/header:

- Check connector integrity (cleanliness, no bent pin, no apparent short)
- Maintain connector in place against the PCB (usually with the hand) 
- With your other hand, apply flux on pins and pads, solder source side
- With your other hand, do the _tacking_ (quick incomplete solder to maintain the connector in place):
  - Put some solder on the iron tip, then quickly transfer to the joint
  - Do that on 1 or 2 opposite joints of the connector, so you can free up your first hand
  - Check the connector is correctly positioned before proceeding with other joints

![image](uploads/31e5eb37a5e4a68f8b621fa445e354ba/image.png)
- Reflow all other joints
- Touch-up the tacks so they have the right shape and aspect

![image](uploads/914af68417070c432f59f76ab9e50daa/image.png) **Do not solder from solder destination side**:
- This is prone to create air gaps in the hole
- The heat could damage the connector
- IPC Class III requirement is 75% vertical fill, starting from solder source side. 
  - If in doubt, reflow the solder source side bringing additional solder

![image](uploads/810ed42622a85ab84883fdfc8940a75a/image.png)

## Tips

- If you **struggle to get a good reflow**:
  - Re-apply flux on pads and pins
  - The trace may have a high thermal inertia (e.g. power barrel GND pins), in which case you can:
    - Increase the iron temperature
    - Increase the contact time between iron and pad before applying the solder
    - Change the iron tip for a larger tip
    - Move the iron on the pad around the pin during reflow
    - Use 2 irons simultaneously to reflow the solder joint 

![image](uploads/b58317e2b5074966847b141643c7881d/image.png)

- During rework, protect nearby sensitive areas with **Kapton tape** (U19 when soldering Ethernet connector on a Q7, connectors, SD card slots, mounting holes, some vias, etc.)
  - Be mindful that droplets of flux can spread several centimeters away from the solder joint during reflow.
- Whenever applying solder on the iron tip before putting in contact with joint, do not exceed a few seconds
  - Otherwise the flux core of the solder melts on the iron tip, and solder is harder to transfer to the joint 
- If you’re uncomfortable/inexperienced, try out a **dummy rework on a decommissioned Qcard** first

- ![image](uploads/4e9d84410d9145f7de175e63e82e2186/image.png) Be mindful that every time we rework a board, there is a **risk to damage something** (heat, sharp tools, handling jigs…)
  - No matter how rushed you are, cautiousness takes precedence.
  - We do not want to compromise quality for anything that we sell, but sometimes “the best is the enemy of the good”! 
    - IPC-A-610 is your friend to make a call on what is acceptable.
    - If in doubt, ask a colleague to cross-check.

# Guidelines for cleaning

![image](uploads/4e9d84410d9145f7de175e63e82e2186/image.png) Reworks require the microscope, **cleaning does require the microscope as well**.

![image](uploads/be8af2b761e9cd1415d875fa7f5c185f/image.png)

Several passes:

- **1.** Flux remover with cotton swabs
  - Several rounds may be required. Don’t be shy with the flux remover.
  - Cleaning dark flux traces can require a good scrubbing! You may have to exert quite some pressure for a few seconds.
- **2.** IPA with cotton swabs
  - Several rounds may be required. Don’t be shy with the IPA.
- **3.** IPA with light brush to remove whitish IPA traces
- **4.** (to remove the last dry IPA traces, you can use a dry cotton swab to scrub them) 

![image](uploads/a5315fb28aeed0aaf563bbcaa4e10067/image.png)
![image](uploads/b254db17c1d441c9158b6d6f1e9e1541/image.png)

- When possible, tilt the board so that flux remover/IPA do not flow below other components
- Bear in mind that that droplets of flux can spread several centimeters away from the solder joint during reflow.
- Make sure there is no FOD left on the board 
  - solder ball, loose component dropped on the board, hair, etc.
- For through-hole components, do not forget to clean the solder destination side

![image](uploads/cffc0023745510ef7b796853cfd2a478/image.png) ![image](uploads/03269b30f04adaa75588c7ec6ffd5c17/image.png)

- ![image](uploads/4e9d84410d9145f7de175e63e82e2186/image.png) After cleaning, the solder joints, nearby components, and PCB should be pristine!
  - The flux is corrosive
  - Wet flux residues may create conductive paths
  - Any residue from a no-clean process is a defect for IPC Class III
- Leave to dry at least 30min before powering-on again
  - Current procedure. Being discussed here though: https://gitlab.xiphos.ca/xiphos/internal/xiphos-qa/robotframework-hw-tests/-/issues/166

# When you're done

- Power off the irons
- Turn off the fume extractor
- Tidy up and clean-up the solder station
- ![image](uploads/4e9d84410d9145f7de175e63e82e2186/image.png) Update the Redmine HW ticket with your rework! 

![image](uploads/57d687d42ef55c004535faeb306f8ae1/image.png)
