# Breakout-GO [![Build Status](https://dev.azure.com/huddeldaddel/huddeldaddel/_apis/build/status/huddeldaddel.breakout-go?branchName=master)](https://dev.azure.com/huddeldaddel/huddeldaddel/_build/latest?definitionId=1&branchName=master) [![Codacy Badge](https://api.codacy.com/project/badge/Grade/75bf58cc8f6e48e0974966a4449d7374)](https://app.codacy.com/app/huddeldaddel/breakout-go?utm_source=github.com&utm_medium=referral&utm_content=huddeldaddel/breakout-go&utm_campaign=Badge_Grade_Dashboard)

Breakout-GO is a Breakout clone for the [ODROID-GO Game Kit](https://www.hardkernel.com/shop/odroid-go/) written in C++.

![Breakout-Go start screen](/Documentation/game-start.jpg "ODROID-GO running Breakout-Go")

## Installation and Getting Started

### Project Structure

Breakout-GO is being developed in C++ using Microsoft Visual Studio 2019 and the Arduino IDE. The project therefore has a project structure that allows you to use both IDEs in parallel:

![Picture of an ODROID-GO showing text](/Documentation/breakout-project-structure.png "ODROID-GO running a demo application")

The full source code for the game is located in [/Breakout-Go](https://github.com/huddeldaddel/breakout-go/tree/master/Breakout-Go) - which is the project folder for the Arduino IDE. A Visual Studio 2019 Solution file is located at [/Breakout.sln](https://github.com/huddeldaddel/breakout-go/blob/master/Breakout.sln). Opening that file in Visual Studio will open a Solution with two projects: [/Breakout-Win](https://github.com/huddeldaddel/breakout-go/tree/master/Breakout-Win) is just an empty project - you can ignore it. [/Breakout-Win-Test](https://github.com/huddeldaddel/breakout-go/tree/master/Breakout-Win-Test) is the Unit Test project used to write, test and debug most of the code. It imports most of the C++ source files from /Breakout-Go.

This setup has several advantages over the exclusive use of the Arduino IDE:

*   The source code can be checked automatically via unit tests.
*   The unit tests can also be executed in the debugger. Critical parts of the code can thus be very easily examined at different input values.
*   Visual Studio is just the better editor for experienced developers.

### Compiling and Deploying to the ODROID-GO

*   Follow the [steps decribed in the ODROID Wiki](https://wiki.odroid.com/odroid_go/arduino/01_arduino_setup) to set up the development environment 
*   Get a copy of the source code by running `git clone https://github.com/huddeldaddel/breakout-go.git`
*   Connect your ODROID-GO via USB
*   Start your Arduino IDE and open [/Breakout-Go/Breakout-Go.ino](https://github.com/huddeldaddel/breakout-go/blob/master/Breakout-Go/Breakout-Go.ino)
*   Click "Upload" to compile the source code and upload the game
