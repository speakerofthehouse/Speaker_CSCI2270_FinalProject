# Speaker_CSCI2270_FinalProject

CSCI 2270 - final project README text file

Project Summary:
This code is created to model a D&D style of game. The user is suppose to find their way through many differently designed rooms to reach the end without losing all 3 of their lives. The main function is what drives the movement between different rooms through calling the specific room functions based off of the value returned by each room function in the .cpp and what is initially assigned. This code has a class with a .h and a .cpp file. The .h file includes the struct built for the code and the functions and the individual functions and other variables used throughout the main and .cpp; all those variables and functions are declared as public. The .cpp file contains all of the functions. It contains a buildnetwork function that creates each room as a class and creates the connections between the rooms that do and do not connect. While creating each room "node" an integer value is also created and set to a specific number based on the room it is created with and that is how the program recognizes which room to call/move to. Within the game itself each room function is slightly different but the general process is the same. Rooms will either have a trap or nothing and allow you to move to the next room. If allowed to move to a different room the user will be prompted for which direction they would like to move and their input will move them to the next room. If they hit a trap room they will have to answer a riddle and
their movement will be based on if that answer is a correct answer or not. If it is a correct answer they will be moved along a path that should lead them closer to the end. If they answer incorrectly then the user will "die"/lose a life and be sent back to the starting room. If their life counter reaches 0 then the game will end and they will have lost. In the final room before they reach the goal the user will be forced to answer 3 different riddles. If they get them correct then they will be moved to the room with their goal and if they get any of the 3 riddles wrong then they will lose the game, no matter how many lives they may have. The riddles in the room9 are taken from JRR Tolkein's book The Hobbit.
A map of the building is given in another file if you desire to see the layout of the rooms and how they connect.

How to Run:
The way to run this program should be simple.
Once in a proper coding space, that contains the main, .cpp & .h properly conected then all you should need to do is to hit the run button to activate this program. The movement between rooms is run through user input requiring a user response with the numbers 1,2,3. The riddles used in this program are designed to be answered by user response, the user must answer as specified with the question. All but one riddle, as currently designed, are answers that require one word answers with lowercase letters. One answer requires a number and that number should be entered as a number (like 1,2,3,4,etc).

Dependencies:
This program should not need any dependencies. It was build in the given Code::Blocks environment designed for use throughout this class and it should not require any additional downloads or installations.

System Requirements:
There are no additional system requirements that I built into the program. This code was designed on Code::Blocks so if your system can run Code::Blocks or is able to work with c++ as code blocks does it should be ok to use.

Group Members:
There were no other group members on this assignment.

Contributors:
There were no other contributors for this assignment.

Open issues/bugs:
There should be no immediate bugs or code errors that prevent the code from running.
However, there are a few things that could be done to make the project run more smoothly:

1. The menus and user inputs from those menus were build to handle numbers as the user inputs. If the user instead types a string or charthe program will fail and go through what looks like an endless loop.
2. 
2. The riddle answers are required to be lowercase because in the code i am comparing the userinputed string to a string that holds the correct answer. For example, if the answer is pie and the user types PIE it will be wrong because PIE is not the same as pie. If there isa way to take a userinput and make it all caps or all lowercase then that could clear up this potential issue.



Phase 1 readme description:
This project is designed to model, in a way, a basic D&D game structure. What it does is it builds a few connecting and non connection rooms and the user's objective is to get to the final room and find the treasure. The rooms are created and connected through the creation and connection of nodes. The 10 functions that are required in this assignment will come out to be the createnode function and a different function for each room. All of the room functions will be different because of the connections between rooms; however, some rooms will also have tasks for the user to complete before they can move on, such as answering riddles. This project also heavily requires on userinputs and menus for the user to select from. 

