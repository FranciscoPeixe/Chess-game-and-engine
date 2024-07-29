# Project description
This program consists of a simple chess game for two people to play on the same machine.
It is made to run in the command prompt (cmd).
![image](https://github.com/user-attachments/assets/1141f979-128d-40e7-aad3-30dd1044f4f0)

After the first move, the following are shown:
* the position's evaluation based on an engine with a depth of two moves;
* the pieces that each player captured;
* the amount of material that each player has captured;
* whose turn it is.

![image](https://github.com/user-attachments/assets/d61a40b8-fc9f-4902-ab93-55fd92880598)

In this example, white (the player with the red color) played 1. e4.

After each move the board inverts to show the current player's perspective.

This code only uses three libraries:
* stdio.h
* ctype.h
* stdlib.h

## Engine

Since the engine only has a two-move depth, in the position:

![image](https://github.com/user-attachments/assets/82dc8bee-3b09-48ad-b613-d79610f85a41)

It gives a +1.0 advantage, because regardless of what black plays white is able to capture the pawn (Black can defend it but the engine does not know that if black plays a move like 2...Nc6 after 3.Nxe5 black can play 3...Nxe5 and win material, the engine stops at 3.Nxe5).

# Installation instructions

To run the code  you first need to compile it.

## Installing GCC on Windows using MinGW

MinGW (Minimalist GNU for Windows) is a popular choice for installing GCC on Windows.

* ### Download the MinGW Installer
Visit the official MinGW website: https://osdn.net/projects/mingw/.
Download the mingw-get-setup.exe installer.
* ### Run the Installer
Double-click the downloaded installer to start the installation process.
Accept the license agreement.
* ### Select Components
The MinGW Installation Manager will open.   
Go to the "Basic Setup" tab.   
Select the following components:
mingw32-base
mingw32-gcc-g++ (for C++)
You can also select other components based on your needs.
* ### Install Selected Components
Click the "Installation" menu and select "Apply Changes".   
Wait for the installation to complete.
* ### Add GCC to Environment Variables (Optional)
To use GCC from any command prompt, add the MinGW bin directory to your system's PATH environment variable.   
The default path is usually C:\MinGW\bin.
Right-click on "This PC" -> Properties -> Advanced system settings -> Environment Variables.
Under "System variables", find the "Path" variable and edit it.   
Add the MinGW bin directory to the list of paths.   
* ### Verify Installation
Open a command prompt and type gcc --version.
If GCC is installed correctly, you should see the GCC version information.

## Compiling the code

To compile the code you just need to go (in cmd) to the directory that you file is in and type gcc [the file's name].c -o [the file's name].exe. This creates a file with a .exe extension that you can run
on Windows.

# How to use the code

To move a piece you just need to say the current coordinates of the square that the piece is in and the coordinate of the square that the piece is going to.

![image](https://github.com/user-attachments/assets/d625037f-e56f-416f-a8fd-e162dedd2c58)
