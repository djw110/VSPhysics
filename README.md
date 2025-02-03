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

#### Dependencies & Citations
This application is written entirely by Daniel Whooley with the exception of including the SFML Graphical Library.
SFML allows basic shapes to be drawn into a render window on windows devices, and I have incorporated their library into VSPhysics to demonstrate.