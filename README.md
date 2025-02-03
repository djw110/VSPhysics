### Welcome to VS-Physics
##### By Daniel Whooley
VSPhysics is a container of multiple apps that simulate various physics scenarios.
Currently I have created ***1***: *Basic Simulation*.

#### Basic Simulation
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
- A functional application that runs and validates user input (Takes which key the user presses and responds accordingly)
- Zero bugs at time of submission.

#### Dependencies & Citations
This application is written entirely by Daniel Whooley with the exception of including the SFML Graphical Library.
SFML allows basic shapes to be drawn into a render window on windows devices, and I have incorporated their library into VSPhysics to demonstrate.

#### Score Proposal
**Main Program Complexity** :: 15-20 pts
The main program expresses decent functionality, it opens an entire application window and game instance, handles a variety of events and functions (checks for user interaction with the close button, escape key) and also allows users to add to the game world by pressing A and inserting random bodies into the world.

**Concept: C++ Class** :: 20 pts
The various classes and types created need to be very specific, and given their readability, modularity and level of abstraction, I suggest this score.

**Concept: Overloaded operator, enum** :: 3-4 pts
I do have several overloaded functions, but no overloaded operators were necessary for this project. I do have a single enumerated type that is used, but not very extensively.

**Style and Documentation** :: -0 pts
I believe I have documented all ambiguous code and programmed in an organized efficient manner.

**Video** :: -0 pts

**Lifespan of Project** :: -0 pts
I started in the *main branch* over a week ago however moved to the *visual* branch once I switched from CMake to a VS solution.

In total, I suggest this project earn ~40-45 points.

#### Future Work
This entire project was designed to be worked on over the entire course of the semester. I have organized all my code in such a way that will allow me to add tons of features in the coming months, which is why there is not much functionality in the main program just yet. I will first implement the physics functions to be drawn on-screen in real time, I will allow players to specify the size shape and orientation of objects they add in, and more.
