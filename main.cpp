/*
Cody made by: Eric Speaker
CSCI 2270 - Final Project
This code is created to model a D&D style of game. The user is suppose to find their way through many differently designed rooms
to reach the end without losing all 3 of their lives. The main function is what drives the movement between different rooms through
calling the specific room functions based off of the value returned by each room function in the .cpp. This code has a class with a .h
and a .cpp file. The .h file includes the struct built for the code and the functions and the individual functions and other variables
used throughout the main and .cpp; all those variables and functions are declared as public. The .cpp file contains all of the functions.
It contains a buildnetwork function that creates each room as a class and creates the connections between the rooms that do and do not
connect. While creating each room "node" an integer value is also created and set to a specific number based on the room it is created
with and that is how the program recognizes which room to call/move to.
Within the game itself each room function is slightly different but the general process is the same. Rooms will either have a trap or
nothing and allow you to move to the next room. If allowed to move to a different room the user will be prompted for which direction
they would like to move and their input will move them to the next room. If they hit a trap room they will have to answer a riddle and
their movement will be based on if that answer is a correct answer or not. If it is a correct answer they will be moved along a path
that should lead them closer to the end. If they answer incorrectly then the user will "die"/lose a life and be sent back to the
starting room. If their life counter reaches 0 then the game will end and they will have lost. In the final room before they reach
the goal the user will be forced to answer 3 different riddles. If they get them correct then they will be moved to the room with their
goal and if they get any of the 3 riddles wrong then they will lose the game, no matter how many lives they may have.
The riddles in the room9 are taken from JRR Tolkein's book The Hobbit.
*/
#include <iostream>
#include "GameBuilder.h"
using namespace std;

int main()
{
    //create necessary line to allow for implimentation of .cpp function
    GameBuilder roomfunction;
    //build the rooms and their connections
    roomfunction.buildNetwork();
    //create a "value" that allows for movement and make it part of the struct so it can use north,south,east & west as movement
        // --this is like how we would have used previous and next throughout the year
    Movement *currentroom = roomfunction.head;

    do{
        //each function returns a number or NULL and based on that number it goes to that particular if or else statement and runs that function
        //starting room = 0, room 1 = 1 and so on up until room 10 = 10
        //NULL is used as a quit property. If the user wins, loses in room9 or loses all their lives the room function returns NULL and the program exits.
        if(currentroom->movementroomvalue == 0){
            currentroom = roomfunction.StartRoom(currentroom);
        }
        else if(currentroom->movementroomvalue == 1){
        //cout<<"the current room is room1"<<endl;
            currentroom = roomfunction.Room1(currentroom);
        }
        else if(currentroom->movementroomvalue == 2){
        //cout<<"the current room is room2"<<endl;
            currentroom = roomfunction.Room2(currentroom);
        }
        else if(currentroom->movementroomvalue == 3){
        //cout<<"the current room is room3"<<endl;
            currentroom = roomfunction.Room3(currentroom);
        }
        else if(currentroom->movementroomvalue == 4){
        //cout<<"the current room is room4"<<endl;
            currentroom = roomfunction.Room4(currentroom);
        }
        else if(currentroom->movementroomvalue == 5){
        //cout<<"the current room is room5"<<endl;
            currentroom = roomfunction.Room5(currentroom);
        }
        else if(currentroom->movementroomvalue == 6){
        //cout<<"the current room is room6"<<endl;
            currentroom = roomfunction.Room6(currentroom);
        }
        else if(currentroom->movementroomvalue == 7){
        //cout<<"the current room is room7"<<endl;
            currentroom = roomfunction.Room7(currentroom);
        }
        else if(currentroom->movementroomvalue == 8){
        //cout<<"the current room is room8"<<endl;
            currentroom = roomfunction.Room8(currentroom);
        }
        else if(currentroom->movementroomvalue == 9){
        //cout<<"the current room is room9"<<endl;
            currentroom = roomfunction.Room9(currentroom);
        }
        else if(currentroom->movementroomvalue == 10){
        //cout<<"the current room is room10"<<endl;
            currentroom = roomfunction.Room10(currentroom);
        }
    }while(currentroom != NULL);
    cout<<"Goodbye!"<<endl;
    cout<<"Thanks for playing."<<endl;
}
