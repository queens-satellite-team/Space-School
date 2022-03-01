# Introduction 
Hello! Welcome to the eleventh lab of Space School! In this lab we are going to begin with some soldering basics to help prepare for the undertaking of soldering your entire toastSat payload. In this lab you will find some basic guidelines and tips to perform various soldering tasks sush as installing components and removing components.

If you have any questions, please feel free to reach out to Emma Paczkowski, Sean Tedesco, Piper Steffen, Thomas Sears, or any other member of the QSAT Team. Contact info can be found in the [readme](https://github.com/queens-satellite-team/Space-School) of this repository. 

# Goals of Lab 11

We will learn...

1️⃣ What soldering is. 

2️⃣ How to prepare our design, and workstation in order to solder. 

3️⃣ How to solder components together. 

4️⃣ How to remove components that have been previously soldered. 

5️⃣ How to clean up the mess left behind after soldering. 

# Section 1: Motivation 

Right now, our circuit is assembled on a breadboard. Let us look at some pros and cons of using a breadboard. 

| Breadboard Advantages | Breadboard Disadvantages | 
| --- | --- | 
| It has easy to quick to check for easy and complex circuits both and it has easily verified circuits at the initial stage, so it can save time. | It is unreliable. |
| Quick to check component around. | Difficult to replicate. |
| It is easy to adjust. | It is temporary. |
| It is flexible. | It is heavier. |
| No drilling holes. | A breadboard can cause signals to be [noisy](https://en.wikipedia.org/wiki/Noise_(signal_processing)). |
| No soldering required. | Prone to human error and some poor connections problem. |
| You can fix mistakes quickly | It almost always, take up more physical space than the final circuit board design. |
| A solderless connection makes it reusable. | Difficult to modify complex SMD component for prototyping. |
| Cheap and connections can be changed. | It works very poorly for high-speed design. |

Looking at these pros and cons, and knowing that we have certian mass, power, and volume constrains, can we think of anything that might be a bit better than a breadboard? We will want a solution that is a bit more permanent, can allow our circuit to be a bit more compact, and allow us to align our components the way we want. Our solution will be to solder! 

# Section 2: Soldering Tools 
[Soldering](https://en.wikipedia.org/wiki/Soldering) is the process of joining two or more items together by melting an additional filler metal (solder) into the joint. When you solder a circuit together you are providing a **strong electrical connection**. While a solder connection can stay together with greater strength than a breadboard, it is up to you to make sure all components also have a **strong mechanical connection** by twisting wires together and ensuring components are not under stress. A typical soldering setup will have the following:

### 2.1 Soldering Iron
This supplies the heat in order to melt the solder so that it can flow into the joint. A soldering iron is composed of a heated metal tip and an insulated handle.❗ Please do not touch any part of the metal end when the soldering iron is on.❗  

<p align="center">
  <img src="https://user-images.githubusercontent.com/48306876/138555772-d5ea32e9-71ab-46a6-b17e-90f50688157f.png" width=200 height=200)>
</p>

### 2.2 Flux Pen
This prepares the metal surfaces for soldering by cleaning and removing any oxides and impurities. Flux allows the heat to be transferred to the metals more easily.❗ If using rosin core solder (a special kind of solder we will talk a bit more later), you do not need to use flux when soldering. ❗

<p align="center">
<img src="https://user-images.githubusercontent.com/48306876/138556039-b4a0b860-b751-4b91-874d-a6db35f763eb.png" width=200 height=200)>
</p>

### 2.3 Sponge
This is used to clean the tip of the soldering iron, removing any excess soldering that has been left behind. ❗ Make sure that the sponge is slightly damp before wiping away any solder. ❗

<p align="center">
<img src="https://user-images.githubusercontent.com/48306876/138556208-8e7add71-cffe-4ce9-85de-7eed264e7dd0.png" width=200 height=200)>
</p>
  
### 2.4 Brass Wool
This is also used to clean the tip of the soldering iron by removing any excess soldering that has been left behind. ❗ Brass wool is soft and will not scratch the soldering iron tip. Steel wool is not a replacement. ❗

<p align="center">
<img src="https://user-images.githubusercontent.com/48306876/138556310-ae29be8c-cb34-4fc4-8b09-c25c16393bf2.png" width=200 height=200)>
</p>

### 2.5 Solder
This is the filler material used to fill in the joint of the solder connection. Solder is a metal alloy which means it is a combination of at least two different types of metal, typically lead (Pb) and tin (Sn); however, lead-free solder may also contain copper, silver, bismuth, indium, zinc, antimony, and traces of other metals. ❗ You can also find rosin- and acid-core solder. These have rosin or acid in the centre of the solder wire. Acid core is used for plumbing application, while rosin-core is used for electronics. Rosin-core solder has a _flux_ like material at its centre to assist in the soldering process just like using a flux pen. ❗

<p align="center">
<img src="https://user-images.githubusercontent.com/48306876/138556671-38913eb7-b041-4ac7-bd50-7357fbd154db.png" width=200 height=200)>
</p>

# Section 3: Setup and Preparation

**Step 1: Confirm what needs to be done.**
  - Confirm that component part numbers, resistor values, etc. are all correct. 
  - Confirm the component orientation (headers, diodes, etc.). 
  - Confirm the nominal layout of your design (are buttons accessible, LEDs visible). 

**Step 2: Clean components and work area.**
  - Use a small brush to lightly brush away any foreign object debris (FODs) such a dust, hair, small particles.
  - Use isopropyl alcohol and a cotton swab to remove any residues or marks on your components. 

**Step 3: Determine what kind of soldering is being used.**
  - Solder can come leaded or lead-free. With QSET, you will be only using lead-free solder, but going out in industry you may encounter leaded solder.
  - If using leaded solder, ensure you have sufficient ventilation (it is better not to breathe it in). 
  - Turn on the fume extractor, or perform your soldering outside. 

**Step 4: Set your soldering iron temperature.**
  - If you have a temperature display you should set it for about ~760 °F or ~404 °C. 
  - You can increase the temperature if you are soldering something with a large thermal inertia (GND traces, large components).

# Section 4: Soldering Components

You can follow these steps for soldering [through-hole technology](https://en.wikipedia.org/wiki/Through-hole_technology) components. 

<p align="center">
<img src="https://user-images.githubusercontent.com/48306876/138556510-b7da9d1f-fc2c-4358-89bf-339ffa5820f1.png")>
</p>

⚠️ Through hole components are difficult to be de-soldered so make sure you’re doing the right thing. ⚠️

**Step 0:** Securely fasten component from the top side of the protoboard, flip protoboard to the back to expose solder pad and metal leg of the component. 

**Step 1:** Heat the solder pad for ~2 seconds. 

**Step 2:** Unwind some solder from the spool, and apply to the component and the pad. Do not just apply the solder to the iron. 

**Step 3:** Remove the solder when there is just enough, but do not let go off the iron. Let the heat from the iron flow the solder into a nice shape. 

**Step 4:** Quickly pull the soldering iron straight up (not directly away from the solder connection) to remove the soldering iron and you can move onto the next joint. 

**Tips**
  - Do not solder from solder destination side (solder from the bottom)!
  - [IPC-A-610](https://www.ipc.org/ipc-610-acceptability-electronics-assemblies-endorsement-program) Class III requirement is 75% vertical fill, starting from solder source side. 
  - If you are getting large balls of solder on your joints try reducing the amount of solder you are applying, increasing the heat slightly, or holding the iron on the solder pad for an additional second in step 1. 

## 4.1 Examples of Good and Bad Solder Joints

<p align="center">
<img src="https://user-images.githubusercontent.com/48306876/138556468-fb7db75c-0716-429c-b1d5-f39c1bee82f2.png")>
</p>

The above image mentions [wetting](https://www.adhesives.org/adhesives-sealants/science-of-adhesion/wetting#:~:text=Wetting%20is%20the%20ability%20of,greater%20the%20degree%20of%20wetting.). This is essentially the degree to how well the 'liquid' solder formed unto the metal surfaces. 

## 4.2 Solder Practice 
We are going to create the blinky circuit we initially made in [Space School Lab One](https://github.com/queens-satellite-team/Space-School/blob/main/lab1/lab1.md) to practice our soldering skills prior to tackling the payload. Please assemble the required components (black and red wire, an LED, and a 1000 Ohm resistor, and a [perfboard/ protoboard](https://en.wikipedia.org/wiki/Perfboard)) and make all the necessary solder connections. Your final result should look similar to the photo below. 

<p align="center">
<img src="https://user-images.githubusercontent.com/48306876/138557845-97b0a103-ef29-4b2b-a232-e5fd805e453e.png")>
</p>

# Section 5: Removing Components 

## 5.1 Steps for Removing Components 

⚠️ The photos below are for surface mounted components ([SMT](https://en.wikipedia.org/wiki/Surface-mount_technology#:~:text=Surface%2Dmount%20technology%20(SMT),%2Dmount%20device%20(SMD).)), but the steps still apply to through-hole components (THT) like the resistor and LED we just soldered. ⚠️

**Step 1:** Apply flux on both solder joints. 

![image](https://user-images.githubusercontent.com/48306876/138558980-a3e0d14b-93b2-469c-b088-256776f63072.png)

**Step 2:** Apply heat to solder joint to reflow solder and pull out component when loose. 

![image](https://user-images.githubusercontent.com/48306876/138559055-4e320d01-4770-47c4-a1cc-e1f3a354026b.png)

_For SMD, use 2 irons to reflow both joints simultaneously. The component should come off smoothly, sticking to one of the irons. If it sticks to one pad, you can reflow that joint while gently pulling the component with tweezers_

_For THT, apply a small amount of new solder to the old solder joint to make the solder reflow faster._

**Step 3:** Clean the pads to remove leftover solder, using solder braid.

![image](https://user-images.githubusercontent.com/48306876/138559176-acc41ea9-49de-4e47-9bd5-cc1674bd9b7e.png)

## 5.2 Common Mistakes and Tips During Reworks 

_Mistake: Avoid using too large of braid. Spread out the copper braid so that it spans the entire solder pad, and apply heat on top of the braid. You should see the solder being sucked into the braid._

_Mistake: Be careful not to overheat the pads. You can re-apply flux as necessary so that the pads end up clean and flat._

_Mistake: Whenever applying solder on the iron tip before putting in contact with joint, do not exceed a few seconds. Otherwise the flux core of the solder melts on the iron tip, and solder is harder to transfer to the joint._

_Tip: If you struggle to get a good reflow, re-apply flux on pads and pins._

_Tip: If what you are soldering has a high thermal inertia (GND pins, large power resistors and capacitors), in which case you can:_
  - _Increase the iron temperature._  
  - _Increase the contact time between iron and pad before applying the solder._
  - _Change the iron tip for a larger tip._  
  - _Move the iron on the pad around the pin during reflow._
  - _Use 2 irons simultaneously to reflow the solder joint._

_Tip: During rework, protect nearby sensitive areas with tape, preferably **kapton tape**, if component is sensitive to [electrostatic discharge](https://en.wikipedia.org/wiki/Electrostatic_discharge)._

## 5.3 Practice Removing a Component 
My apologies! I made a mistake earlier when I mentioned to solder a 1000 Ohm resistor for your blinky circuit -- it really should be a 330 Ohm resistor. To practice removing a component, please follow the steps outlined in Section 5 to remove the 1000 Ohm resistor for your blinky circuit and replace it with a 330 Ohm resistor. 

# Section 6: Cleaning 

## 6.1 Steps for Cleaning  

**Step 1:** Use flux remover with cotton swabs. Several rounds may be required (don’t be shy with the flux remover). Cleaning dark flux traces can require a good scrubbing! You may have to exert quite some pressure for a few seconds.

**Step 2:** Use isopropyl alcohol with cotton swabs. Several rounds may be required (don’t be shy with the isopropyl alcohol).

![image](https://user-images.githubusercontent.com/48306876/138560484-d1e3f67d-3731-43a5-826f-3c6697398391.png)

**Step 3:** Use a light small brush, and a small amount of additional isopropyl alcohol to remove whitish traces of isopropyl alcohol. 

![image](https://user-images.githubusercontent.com/48306876/138560507-8e7e6da4-2a2f-4010-9acd-0d2997cd308e.png)

**Step 4:** Use a dry cotton swab to remove the last dry traces of isopropyl alcohol.  

![image](https://user-images.githubusercontent.com/48306876/138560521-b4e27857-d004-4e0f-a608-0c0ac00581df.png)

## 6.2 Good Cleaning Practices 

_Tip: When possible, tilt the board so that flux remover/isopropyl alcohol does not flow below other components._

_Tip: Bear in mind that that droplets of flux can spread several centimeters away from the solder joint during reflow._

_Tip: Make sure there is no debris left on the board (solder ball, loose component dropped on the board, hair, etc.)._

_Tip: For through-hole components, do not forget to clean the solder destination side._

_Tip: Remove all flux! The flux is corrosive, wet flux residues may create conductive paths._

_Tip: Leave to dry at least 30min before powering-on again. Solder needs time to completely solidify._

## 6.3 Finish Blinky Circuit 
Now that we have our components soldered (and we made sure they were the right components) and clean let's move on to getting this circuit blinking! Connect your hardware to your Arduino and follow the steps in [Space School Lab One](https://github.com/queens-satellite-team/Space-School/blob/main/lab1/lab1.md) to implement the software and verify the hardware connections to the Arduino for this circuit.
