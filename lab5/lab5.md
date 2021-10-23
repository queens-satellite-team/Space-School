# Introduction 
Hello! Welcome to the fifth lab of Space School! In this lab we are going to begin with some soldering basics to help prepare for the undertaking of soldering your entire payload. In this lab you will find some basic guidelines and tips to perform various soldering tasks sush as installing a component and removing components.

If you have any questions, please feel free to reach out to Emma Paczkowski, Sean Tedesco, Piper Steffen, Thomas Sears, or any other member of the QSAT Team. Contact info can be found in the [readme](https://github.com/queens-satellite-team/Space-School) of this repository. 

# Goals of Lab 5

We will learn how to...

1️⃣ Prepare our design, and work station in order to solder. 

2️⃣ Solder components together. 

3️⃣ Remove components that have been soldered. 

4️⃣ Clean up the mess left behind. 

# Section 1 - Motivation 

There are many ways to assemble a circuit together. The most common way to start is with a [breadboard](https://en.wikipedia.org/wiki/Breadboard). Breadboards have internal connections that allow for quick work when piecing together new components of a ciruit. In the photo below, we see all the shared connections inside of a breadboard. The centre ciruit area in green has a shared connection for each column along with a divider in the middle (the top of the column and the bottom of the column are not connected), and the rows coloured blue and red show that there is a shared connection across the entire line (the top blue and red lines are not connected to the bottom blue and red lines). 

![image](https://user-images.githubusercontent.com/48306876/138555396-737f73e0-560d-4cb3-94b0-bc2318304226.png)

Let us take a look at some pros and cons of using a breadboard. 

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

So we want a solution that is a bit more permanate, can allow our ciruit to be a bit more compact, and allow us align our components the way we want. Our solution will be to solder! 

# Section 2 - Soldering Tools 
[Soldering](https://en.wikipedia.org/wiki/Soldering) is the process of joining two or more items together by melting an additional filler metal (solder) into the joint. When you solder a circuit together you are providing a **strong electrical connection**. While a solder connection can stay together with greater strength than a breadboard, it is up to you to make sure all components also have a **strong mechanical connection** by twisting wires together and ensuring compontents are not under stress. A typical soldering setup will have the following:

**Soldering Iron:** this supplies the heat in order to melt the solder so that it can flow into the joint. A soldering iron is composed of a heated metal tip and an insulated handle.❗ Please do not touch any part of the metal end when the soldering iron is on.❗  

<img src="https://user-images.githubusercontent.com/48306876/138555772-d5ea32e9-71ab-46a6-b17e-90f50688157f.png" width=200 height=200)>

**Flux Pen:** this prepares the metal surfaces for soldering by cleaning and removing any oxides and impurities. Flux allows the heat to be transferred to the metals more easily.❗ If using rosin core solder, you do not need to use flux when soldering. ❗

<img src="https://user-images.githubusercontent.com/48306876/138556039-b4a0b860-b751-4b91-874d-a6db35f763eb.png" width=200 height=200)>

**Sponge:** this is used to clean the tip of the soldering iron, removing any excess soldering that has been left behind. ❗ Make sure that the sponge is slightly damp before wiping away any solder. ❗

<img src="https://user-images.githubusercontent.com/48306876/138556208-8e7add71-cffe-4ce9-85de-7eed264e7dd0.png" width=200 height=200)>

**Brass Wool:** this is also used to clean the tip of the soldering iron by removing any excess soldering that has been left behind. ❗ Brass wool is soft and will not scratch the soldering iron tip. Steel wool is not a replacement. ❗

<img src="https://user-images.githubusercontent.com/48306876/138556310-ae29be8c-cb34-4fc4-8b09-c25c16393bf2.png" width=200 height=200)>

**Solder:** this is the filler material used to fill in the joint of the solder connection. Solder is a metal alloy which means it is a combination of atleast two different types of metal, typically lead (Pb) and tin (Sn); however, lead-free solder may also contain copper, silver, bismuth, indium, zinc, antimony, and traces of other metals. ❗ You can also find rosin- and acid-core solder. These have rosin or acid in the centre of the solder wire. Acid core is used for plumbing application, while rosin-core is used for electronics. Rosin-core solder has a _flux_ like material at its centre to assist in the soldering process just like using a flux pen. ❗

<img src="https://user-images.githubusercontent.com/48306876/138556671-38913eb7-b041-4ac7-bd50-7357fbd154db.png" width=200 height=200)>

# Section 3 - Setup and Preparation

**Step 1: Confirm what needs to be done.**
  - Confirm that component part numbers, resistor values, etc. are all correct. 
  - Confirm the component orientation (headers, diodes, etc.). 
  - Confirm the nominal layout of your design (are buttons accesible, LEDs visible). 

**Step 2: Clean components and work area.**
  - Use a small brush to lightly brush away any foreign object debris (FODs) such a dust, hair, small particles.
  - Use isopropyl alcohal and a cotton swab to remove any residues or marks on your components. 

**Step 3: Determine what kind of soldering is being used.**
  - Solder can come leaded or lead-free. With QSET, you will be only using lead-free solder, but going out in industry you may encounter leaded solder.
  - If using leaded solder, ensure you have sufficient venthilation (it is better not to breathe it in). 
  - Turn on the fume extractor, or perform your soldering outside. 

**Step 4: Set your soldering iron temperature.**
  - If you have a temperature display you should set it for about ~760 °F. 
  - You can increase the temperature if you are soldering something with a large thermal inertia (GND traces, large components).

# Section 4.0 - Soldering Components

## 4.1 - Soldering Through-Hole Components

![Screen Shot 2021-10-23 at 8 36 20 AM](https://user-images.githubusercontent.com/48306876/138556510-b7da9d1f-fc2c-4358-89bf-339ffa5820f1.png)

⚠️ Through hole comonents are difficult to be de-soldered so make sure you’re doing the right thing. ⚠️

**Step 0:** Securly fasten component from the top side of the protoboard, flip protoboard to the back to expose solder pad and metal leg of the component. 

**Step 1:** Heat the solder pad for ~2 seconds. 

**Step 2:** Apply solder to the component and the pad. Do not just apply the solder to the iron. 

**Step 3:** Remove the solder when there is just enough, but do not let go off the iron. Let the heat from the iron flow the solder into a nice shape. 

**Step 4:** Quickly pull the soldering iron straight up (not directly away from the solder connection) to remove the soldering iron and you can move onto the next joint. 

**Tips**
  - Do not solder from solder destination side (solder from the bottom)!
  - IPC Class III requirement is 75% vertical fill, starting from solder source side. 
  - If you are getting large balls of solder on your joints try reducing the amount of solder you are applying, increasing the heat slightly, or holding the iron on the solder pad for an additional second in step 1. 

## 4.2 - Example 

![image](https://user-images.githubusercontent.com/48306876/138556468-fb7db75c-0716-429c-b1d5-f39c1bee82f2.png)

The above image mentions [wetting](https://www.adhesives.org/adhesives-sealants/science-of-adhesion/wetting#:~:text=Wetting%20is%20the%20ability%20of,greater%20the%20degree%20of%20wetting.). This is essentially the degree to how well the 'liquid' solder formed unto the metal surfaces. 

## 4.3 Practice 
We are going to create the blinky circuit we initially made in [Space School Lab One](https://github.com/queens-satellite-team/Space-School/blob/main/lab1/lab1.md) to practice our soldering skills prior to tackling the payload. Please assemble the required components (black and red wire, an LED, and a 1000 Ohm resistor, and a [perfboard](https://en.wikipedia.org/wiki/Perfboard) / protoboard) and make all the necceseccary solder connections. Your final result should look similiar to the photo below. 

![Screen Shot 2021-10-23 at 9 14 22 AM](https://user-images.githubusercontent.com/48306876/138557845-97b0a103-ef29-4b2b-a232-e5fd805e453e.png)

# Section 5 - Removing Components 

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

## 5.2 Example

## 5.3 Pracice 
My aplogies! I made a mistake earlier when I mentioned to solder a 1000 Ohm resistor for your blinky circuit -- it really should be a 330 Ohm resitory. To practice removing a component, please follow the steps outlined in Section 5 to remove the 1000 Ohm resistor for your blinky ciruit and replace it with a 330 Ohm resistor. 


# Section 6 - Cleaning 

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
