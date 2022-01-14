# Introduction 
And we're back! Welcome to the eigth lab of Space School! We all hope you had an amazing holiday break, but now it is time for some more Space School. In this lab we are going to focus on a topic in engineering called `budgets`! These are extremely useful tools for engineers to characterize their space missions and start appling some real numbers to their mission design. 

If you have any questions, please feel free to reach out to Emma Paczkowski, Sean Tedesco, Piper Steffen, Thomas Sears, or any other member of the QSAT Team. Contact info can be found in the [readme](https://github.com/queens-satellite-team/Space-School) of this repository. 

# Goals of Lab 8

1️⃣ Learn what budgets are. 

2️⃣ Learn what budgets are included in spacecraft systems and how they are used.  

3️⃣ Begin working on your toastSat budgets. 

# Section 1: Budget Overview 📖

## What is a budget? 

A spacecraft budget, much like your own spending budget, tracks what you need and compares it against what you can afford. These include cost budgets, as your customer likely only wants to pay you a fixed amount of money and you need to buy the parts and pay for labour to build your satellite, but they extend into allocating how much power, memory, temperature, and control you can *spend*.

> We will be talking about **satellite budgets** primarly, but this discussion is applicable to rovers and rockets as well.

Budgets can be (and often are) as simple as a spreadsheet that tallys what you know about the need or demand in your spacecraft. These numbers are combined, sometimes by simple addition and other times through more complicated analysis, and compared against your capacity or limits that you can afford in your satellite. A tangible example of this is a mass budget; you have a limit to how heavy your satellite can be, so you add up all the components and you must be below that limit. Some budgets are definitive (i.e., they tell you a clear result) while others are estimations that serve as a first step towards more detailed analysis.

## What budgets are typically found on spacecraft?

There are no limits to what you can do a budget for on a spacecraft, but here is a list of some common examples.

1. Mass Budget
  - Tracks the mass of each component of the satellite as well as the uncertainty of the mass value (i.e., how confident we are in this value), sums all the values together, and reports how far off the current design is from the absolute limit for the spacecraft. 
  - Managed by a Systems Engineer or the Structure/Mechanical subsystem team
  - For a CubeSat, mass budgets are often tracked in [kg] (as the mass limit is usuall between 1 kg and 4 kg). 
  - The mass budget is often divided by subsystem so we can track what portion of the total mass each system is using.
  - The primary output of the mass budget is the **mass margin**, expressed as a percentage of the maximum mass. 
  - A positive margin indicates that the current mass is *below* the mass limit (i.e., good) and a negative margin indicates that the design is over budget (i.e., bad).
  - How much mass margin you want varies as the spacecraft moves through development, design, manufacturing, and launch preparation; start with a large mass margin and end with a small mass margin
  - You want to have a large mass margin (maybe 10-20%) early in the design of the spacecraft in case some major problem arises later in the project.
  - Only one mass budget is maintained (typically), although other subsystems could informally maintain their own mass budgets if desired.
2. Power Budget
3. Data Budget
4. Link Budget
5. Pointing Budget
6. Delta-V (Propellant) Budget
7. Cost Budget

## What budgets are to be included for out toastSats and why? 

# Section 2: toastSat Mass Budget 🏋️
Now that we have learned some of the ins and outs of spacecraft budgets, we are going to make the first budget for our toastSats. The goal for this section is to create your **mass budget**. Once teams are finished with their budgets, we hope to share them to the rest of Space School next session and highlight the creativity you can have with creating your budgets!  

## 2.1 Helpful Style Guides
While budgets are tools that engineers use to characterize their systems and missions, they are also documents that are _alive_, read by many team members, and iterated upon. As such, a budget should be able to read for team members from different backgrounds, and be able to be easily used. Below are some helpful pointers for you to think about while attempting to create your budgets. 

1. Budgets ask and answer the question: "Given these inputs, what are the ouputs?", so how may we highlight these two important properties?
1. Budgets may contain considerations and calculations that go into budgets, how may we share the justification that went into these?
1. Budgets may contain unknown symbols and colors, how may we provide an easy to read way for users to understand the meaning of these symbols and colors? 
1. Budgets may contain many numerical values, how may we differentiate and give context to these values from one another?  
1. Budgets may contain parameters with a level of uncertianty, how may we include this level of uncertianty? 

## 2.2 Additional Mass Budget Information 
The target mass of your toastSat is 100 grams. This include all of the components outlined in the image below (electrical components, protoboard, structure, and wired connection to the "Toaster" power system). 

<p align="center">
  <img src ="https://user-images.githubusercontent.com/48306876/148651483-f6d84dc8-4b3b-412c-906e-6323e64390ae.png" width = "450" alt ="Nominal toastSat system ">
</p> 
 
- Data Budget
- Pointing Budget
- Power Budget
- Mass Budget
- Propellent Budget
- [Link Budget](https://en.wikipedia.org/wiki/Link_budget)
- [Cost Budget](https://en.wikipedia.org/wiki/Budget)
