## Welcome to VS-Physics
#### By Daniel Whooley
VSPhysics is a container of multiple apps that simulate various physics scenarios.
Currently I have created ***1***: *Basic Simulation*.
All of my source files are located in **BasicSimulation/src**

### Basic Simulation
Basic Simulation is an application that consists of balls and walls. When run, the user is given an open workspace called an instance.
In an instance, there are any number of "bodies" which are objects in the world. There are two types: ball and wall.

All classes and logic for the physics engine have been written and all functions have been declared and defined.
Each type of body has a unique way of responding to collisions, and all of the mathematical calculations have been stored in *Utils.h*
The relationships between objects use sound use of pointers and references which allows for good performance, zero memory leaks, and proper ownership of attributes.
The classes use deep levels of abstraction for better code readability and to reduce redundant code.
I've labelled all fields with a prefix of "f" and all parameters with a prefix of "p" for better readability.
The include chain is also kept simple for code readability and performance.

- Extensive use of abstract classes, pointers, references, and dividing headers and source properly
- An enumerated type used for determining rotation direction of a body
- A functional application that runs and validates user input: Takes key inputs and text inputs and validates if they are valid values
- Zero bugs at time of submission.

### Dependencies & Citations
This application is written entirely by Daniel Whooley with the exception of including the SFML Graphical Library.
SFML allows basic shapes to be drawn into a render window on windows devices, and I have incorporated their library into VSPhysics to demonstrate.

### Score Proposal
**Main Program Complexity :: 35-40 pts**
The main programs offers extensive interactibility and uses a variety of concepts from Mod 2. It allows users to add various objects to the game world, validates their input, and produces graphical output.
To accomplish this, several levels of class inheritance and component classes were used to create an organized and readable program.

**Concept: Is-A or Has-A class relationship :: 20 pts**
Each class depends on eachother in some form, developing an efficient relationship of 7 classes working together. Over three classes have components, and at least 2 classes inherit from Body.

**Concept: File input/output, enum :: 6-7 pts**
A text file is not necessarily edited in this program, however the program takes input from the keystrokes of the computer and outputs images to a graphics file to output in the render-window, which requires extensive validation.

**Style and Documentation :: -0 pts**
I believe I have documented all ambiguous code and programmed in an organized efficient manner.

**Video :: -0 pts**

**Lifespan of Project :: -0 pts**
This project has been worked on since module 1 and I have added to it consistently throughout module 2 as well.

In total, I suggest this project earn ~60-65 points.

### Future Work
This entire project was designed to be worked on over the entire course of the semester. I have organized all my code in such a way that will allow me to add tons of features in the coming months, which is why there is not much functionality in the main program just yet. I will first implement the physics functions to be drawn on-screen in real time, I will allow players to specify the size shape and orientation of objects they add in, and more.
