#include "GameBuilder.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

GameBuilder::GameBuilder()
{
    //ctor
}

GameBuilder::~GameBuilder()
{
    //dtor
}

//This function builds each room as a node and connects that room to other rooms, once that other room is created
//This function also gives each room its roomnumber which is what is used to move through the rooms as shown in main
void GameBuilder::buildNetwork(){
    Movement *StartingRoom = new Movement;
    StartingRoom->roomName = "Starting Room";
    StartingRoom->movementroomvalue = 0;
    StartingRoom->north = NULL;
    StartingRoom->east = NULL;
    StartingRoom->west = NULL;

    Movement *Room1 = new Movement;
    Room1->roomName = "Room1";
    Room1->movementroomvalue = 1;
    StartingRoom->south = Room1;
    Room1->south = NULL;

    Movement *Room2 = new Movement;
    Room2->roomName = "Room2";
    Room2->movementroomvalue = 2;
    Room1->west = Room2;
    Room2->south = NULL;
    Room2->east = NULL;

    Movement *Room3 = new Movement;
    Room3->roomName = "Room3";
    Room3->movementroomvalue = 3;
    Room1->east = Room3;
    Room3->north = StartingRoom;
    Room3->south = NULL;
    Room3->west = NULL;

    Movement *Room4 = new Movement;
    Room4->roomName = "Room4";
    Room4->movementroomvalue = 4;
    Room2->north = Room4;
    Room4->north = NULL;
    Room4->east = StartingRoom;
    Room4->west = NULL;

    Movement *Room5 = new Movement;
    Room5->roomName = "Room5";
    Room5->movementroomvalue = 5;
    Room4->south = Room5;
    Room2->west = Room5;
    Room5->north = NULL;
    Room5->east = Room2;
    Room5->west = NULL;

    Movement *Room6 = new Movement;
    Room6->roomName = "Room6";
    Room6->movementroomvalue = 6;
    Room3->east = Room6;
    Room6->north = StartingRoom;
    Room6->east = NULL;
    Room6->west = NULL;

    Movement *Room7 = new Movement;
    Room7->roomName = "Room7";
    Room7->movementroomvalue = 7;
    Room6->south = Room7;
    Room7->north = NULL;
    Room7->south = NULL;
    Room7->east = NULL;

    Movement *Room8 = new Movement;
    Room8->roomName = "Room8";
    Room8->movementroomvalue = 8;
    Room5->south = Room8;
    Room8->north = Room5;
    Room8->south = NULL;
    Room8->west = NULL;

    Movement *Room9 = new Movement;
    Room9->roomName = "Room9";
    Room9->movementroomvalue = 9;
    Room8->east = Room9;
    Room7->west = Room9;
    Room9->north = NULL;
    Room9->east = NULL;
    Room9->west = NULL;

    Movement *Room10 = new Movement;
    Room10->roomName = "Room10";
    Room10->movementroomvalue = 10;
    Room9->south = Room10;
    Room10->north = NULL;
    Room10->south = NULL;
    Room10->east= NULL;
    Room10->west = NULL;

    head = StartingRoom;
    //cout<<"cpp: "<<head->roomName<<endl;
    tail = Room10;
}

//this function creates a menu for user movement which is called in the start room function.
//It displays the options that the user may choose and takes and returns a number that the user enters.
int GameBuilder::menuSR(){
    int userinput;
    cout<<"======Movement Menu======"<<endl;
    cout<<"1. Yes. Enter."<<endl;
    cout<<"2. No. I Don't Want To Play."<<endl;
    cin>>userinput;
    return userinput;
}

/*
This is one of the many room functions used in this code. The style of these rooms are the same, for every non trap room.
It creates the currentnode for this particular function and sets it equal to some value, which is the pointer given from main
It then checks if the deathcounter is 0, in case it failed a previous deathcounter check and if 0 it quits otherwise it continues.
Then couts are printed about the situation of each room and the start room prints out the number of lives the user has before he/she
enters the game. It then goes through that rooms particular menu as called. This is in a do while loop to handle if the user enters a
value outside of what the options are shown, for example only a 1 and 2 will move the user so this dowhile reenters the menu function if
the user inputs something other than shown, until an input is given that allows for movement. Then based of the users input the function
moves the current node to a connecting room and returns that value to the main so the main function can then call the roomfunction of the
appropriate room that the user wished to enter.
*/
Movement* GameBuilder::StartRoom(Movement *room){
    Movement *currentnode = head;
    int userinput;
    if(deathcounter == 0){
        cout<<"you have lost."<<endl;
        return NULL;
    }
    cout<<"Welcome!!"<<endl;
    cout<<"In this game your objective is to get through at the traps, trials and tribulations of this house and find the treasure."<<endl;
    cout<<"You have "<<deathcounter<<" lives."<<endl;
    cout<<"If you wish to enter and test your mettle, you have one door ahead"<<endl;
    do{
    userinput = menuSR();
        if(userinput == 1){
            currentnode = currentnode->south;
        }
        else if(userinput == 2){
            currentnode = NULL;
        }
        else{ //(userinput > 2 || userinput <= 0)
            cout<<"invalid input. Please enter a number between 1 & 2"<<endl;
        }
    }while( (userinput < 1) || (userinput > 2) );
    return currentnode;
}

int GameBuilder::menuR1(){
    int userinput;
    cout<<"======Movement Menu======"<<endl;
    cout<<"1. Move east"<<endl;
    cout<<"2. Move west"<<endl;
    cout<<"3. Quit"<<endl;
    cin>>userinput;
    return userinput;
}

Movement* GameBuilder::Room1(Movement *room){
    Movement *currentnode = room;
    int userinput;
    cout<<endl;
    cout<<"You enter the room and find it's perfectly normal and has no surprises."<<endl;
    cout<<"There are two doors for you to choose, one to the east and one to the west."<<endl;
    do{
    userinput = menuR1();
        if(userinput == 1){
            currentnode = currentnode->east;
        }
        else if(userinput == 2){
            currentnode = currentnode->west;
        }
        else if(userinput == 3){
            currentnode = NULL;
        }
        else{ //(userinput > 3 || userinput <= 0){
            cout<<"invalid input. Please enter a number between 1 & 3"<<endl;
        }
    }while( (userinput < 1) || (userinput > 3) );
    return currentnode;
}

int GameBuilder::menuR2(){
    int userinput;
    cout<<"======Movement Menu======"<<endl;
    cout<<"1. Move north"<<endl;
    cout<<"2. Move west"<<endl;
    cout<<"3. Quit"<<endl;
    cin>>userinput;
    return userinput;
}

Movement* GameBuilder::Room2(Movement *room){
    Movement *currentnode = room;
    int userinput;
    cout<<endl;
    cout<<"You enter the room and it appears perfectly normal with no surprises"<<endl;
    cout<<"There are two doors for you to choose, one to the north and one to the west."<<endl;
    do{
    userinput = menuR2();
        if(userinput == 1){
            currentnode = currentnode->north;
        }
        else if(userinput == 2){
            currentnode = currentnode->west;
        }
        else if(userinput == 3){
            currentnode = NULL;
        }
        else{ //(userinput > 3 || userinput <= 0){
            cout<<"invalid input. Please enter a number between 1 & 3"<<endl;
        }
    }while( (userinput < 1) || (userinput > 3) );
    return currentnode;
}

/*
This is one of the many room functions used in this code. The style of these rooms are the same, for every trap room.
The trap rooms are 3,4,6 & 9. These rooms require riddles to be answered and the user movement is based on that answer.
It creates the currentnode for this particular function and sets it equal to some value, which is the pointer given from main.
It creates a string value riddleanswer that will take in the users answer to the riddle when required. Then couts are printed
and the riddle is given to the user. The user is then prompted for the answer and should type in his/her answer. If that answer matches
the string (in quotes) which is the answer then an integer variable( userinput) is set to a value which would allow the user to move
forward. If the answer does not match the string the integer variable is set to a variable that will set the user back to the beginning/die
if that would not cost the user his/her last life. If the answer is wrong the deathcounter is check and if the user would not have 0 lives
after this incorrect answer the previous sentence applies. If the user would fall to 0 lives the function sets currentnode = NULL (the quit value)
and returns currentnode right away. The function, if not quit out of, then enters the same do while loop as all the other functions and
sets currentnode to the particular room the user would move to and returns that value.
*/
Movement* GameBuilder::Room3(Movement *room){
    Movement *currentnode = room;
    int userinput;
    string riddleanswer;
    cout<<endl;
    cout<<"As you enter the room the door behind you swings shut of its own power. You are trapped. "<<endl;
    cout<<"The room grows dark and a mysterious voice ask you a question:"<<endl;
    cout<<endl;
    cout<<"Who makes it, but has no need of it."<<endl;
    cout<<"Who buys it, but has no use for it."<<endl;
    cout<<"Who uses it but can neither see or feel it."<<endl;
    cout<<"What is it? (one word, lowercase)"<<endl;
    //The answer is: a coffin
    cout<<"What is your answer? It is a[n] ____."<<endl;
    cin.ignore();
    cin>>riddleanswer;
    //getline(cin,riddleanswer);
    if(riddleanswer == "coffin"){
        userinput = 1;
        cout<<"That is correct, you may proceed."<<endl;
    }
    else{
        cout<<"That answer is wrong."<<endl;
        if( (deathcounter - 1) == 0 ){
            cout<<"you have lost."<<endl;
            return NULL;
        }
        else{
            userinput = 2;
            cout<<"The floor below you falls open and you fall into an abyss and you land in the room you started in."<<endl;
            cout<<endl;
            deathcounter = deathcounter - 1;
        }
    }
    do{
        if(userinput == 1){
            currentnode = currentnode->east;
        }
        else if(userinput == 2){
            currentnode = currentnode->north;
        }
        else{ //if(userinput > 3 || userinput <= 0){
            cout<<"invalid input. Please enter a number between 1 & 3"<<endl;
        }
    }while( (userinput < 1) || (userinput > 2) );
    return currentnode;
}

Movement* GameBuilder::Room4(Movement *room){
    Movement *currentnode = room;
    int userinput;
    string riddleanswer;
    cout<<endl;
    cout<<"As you enter the room the door shuts behind you."<<endl;
    cout<<"A mysterious voice laughs and then gives you this question:"<<endl;
    cout<<endl;
    cout<<"You take 2 apples from 3 apples. How many apples would you have?"<<endl;
    //answer is: you have 2 apples
    cout<<"You have __ apples (please enter answer as a number)"<<endl;
    cin.ignore();
    cin>>riddleanswer;
    //getline(cin,riddleanswer);
    cout<<"user answer: "<<riddleanswer<<endl;
    if(riddleanswer == "2"){
        cout<<"That is correct. You may proceed."<<endl;
        userinput = 1;
    }
    else{
        cout<<"That answer is wrong."<<endl;
        if( (deathcounter - 1) == 0 ){
            cout<<"you have lost."<<endl;
            return NULL;
        }
        else{
            userinput = 2;
            cout<<"The floor of the room, transforms itself into a slide and sends you through a door and you land in the room you started in."<<endl;
            cout<<endl;
            deathcounter = deathcounter - 1;
        }
    }
    do{
        if(userinput == 1){
            currentnode = currentnode->south;
        }
        else if(userinput == 2){
            currentnode = currentnode->east;
        }
        else{ //if(userinput > 3 || userinput <= 0){
            cout<<"invalid input. Please enter a number between 1 & 3"<<endl;
        }
    }while( (userinput < 1)  || (userinput > 2) );
    return currentnode;
};

int GameBuilder::menuR5(){
    int userinput;
    cout<<"======Movement Menu======"<<endl;
    cout<<"1. Move east"<<endl;
    cout<<"2. Move south"<<endl;
    cout<<"3. Quit"<<endl;
    cin>>userinput;
    return userinput;
}

Movement* GameBuilder::Room5(Movement *room){
    Movement *currentnode = room;
    int userinput;
    cout<<endl;
    cout<<"You enter the room and there are no traps or surprises."<<endl;
    cout<<"There are two doors in this room for you to choose. One door to the east and one to the south."<<endl;
    do{
    userinput = menuR5();
        if(userinput == 1){
            currentnode = currentnode->east;
        }
        else if(userinput == 2){
            currentnode = currentnode->south;
        }
        else if(userinput == 3){
            currentnode = NULL;
        }
        else{ // if(userinput > 3 || userinput <= 0){
            cout<<"invalid input. Please enter a number between 1 & 3"<<endl;
        }
    }while( (userinput < 1) || (userinput > 3) );
    return currentnode;
};

Movement* GameBuilder::Room6(Movement *room){
   Movement *currentnode = room;
    int userinput;
    string riddleanswer;
    cout<<endl;
    cout<<"As you enter the room the door shuts behind you. You then see openings in the wall start to pour out water."<<endl;
    cout<<"The mysterious voice laughs and says:"<<endl;
    cout<<"Answer this question or you will die."<<endl;
    cout<<endl;
    cout<<"The more it dries, the wetter it gets. What is it?"<<endl;
    //answer is: towel
    cout<<"It is a[n]____. (one word, lowercase)"<<endl;
    cin.ignore();
    cin>>riddleanswer;
    //getline(cin,riddleanswer);
    cout<<"user answer: "<<riddleanswer<<endl;
    if(riddleanswer == "towel"){
        cout<<"That is correct. You may proceed."<<endl;
        userinput = 1;
    }
    else{
        cout<<"That answer is wrong."<<endl;
        if( (deathcounter - 1) == 0 ){
            cout<<"you have lost."<<endl;
            return NULL;
        }
        else{
            userinput = 2;
            cout<<"That answer is wrong."<<endl;
            cout<<"The water then fills the room and you drown."<<endl;
            cout<<endl;
            deathcounter = deathcounter - 1;
        }
    }
    do{
        if(userinput == 1){
            currentnode = currentnode->south;
        }
        else if(userinput == 2){
            currentnode = currentnode->north;
        }
        else{ // if(userinput > 3 || userinput <= 0){
            cout<<"invalid input. Please enter a number between 1 & 3"<<endl;
        }
    }while( (userinput < 1) || (userinput > 2) );
    return currentnode;
}

int GameBuilder::menuR7(){
    int userinput;
    cout<<"======Movement Menu======"<<endl;
    cout<<"1. Move west"<<endl;
    cout<<"2. Quit"<<endl;
    cin>>userinput;
    return userinput;
}

Movement* GameBuilder::Room7(Movement *room){
    Movement *currentnode = room;
    int userinput;
    cout<<endl;
    cout<<"This room is empty."<<endl;
    cout<<"There is one door for you to go through. What do you do?"<<endl;
    do{
    userinput = menuR7();
        if(userinput == 1){
            currentnode = currentnode->west;
        }
        else if(userinput == 2){
            currentnode = NULL;
        }
        else{  //if(userinput > 2 || userinput <= 0){
            cout<<"invalid input. Please enter a number between 1 & 3"<<endl;
        }
    }while( (userinput < 1) || (userinput > 2) );
    return currentnode;
}

int GameBuilder::menuR8(){
    int userinput;
    cout<<"======Movement Menu======"<<endl;
    cout<<"1. Move north"<<endl;
    cout<<"2. Move east"<<endl;
    cout<<"3. Quit"<<endl;
    cin>>userinput;
    return userinput;
}

Movement* GameBuilder::Room8(Movement *room){
    Movement *currentnode = room;
    int userinput;
    cout<<endl;
    cout<<"This room is empty and has no traps or surprises."<<endl;
    cout<<"There are two doors in this room to choose. One door to the north and one to the east. Which do you choose?"<<endl;
    do{
    userinput = menuR8();
        if(userinput == 1){
            currentnode = currentnode->north;
        }
        else if(userinput == 2){
            currentnode = currentnode->east;
        }
        else if(userinput == 3){
            currentnode = NULL;
        }
        else{ //if(userinput > 3 || userinput <= 0){
            cout<<"invalid input. Please enter a number between 1 & 3"<<endl;
        }
    }while( (userinput < 1) || (userinput > 3) );
    return currentnode;
}

/*
This room is a different type of trap room in that it requires all three answers to be correct. If any of the answers are wrong then
the room returns NULL. This is the case because this is the last room before the treasure room, and is designed to be "harder." Lives
do not matter in this room.
*/
Movement* GameBuilder::Room9(Movement *room){
    Movement *currentnode = room;
    string riddleanswer;
    int userinput;
    cout<<endl;
    cout<<"As you enter the room the door shuts behind you and fire engulfs the walls."<<endl;
    cout<<"The mysterious voice laughs and says:"<<endl;
    cout<<"You must be clever if you got this far but you wont escape this room alive."<<endl;
    cout<<"You only have one chance to answer 3 questions if you hope to live."<<endl;
    cout<<"Here is the first: "<<endl;
    cout<<endl;
    cout<<"Voiceless it cries,"<<endl;
    cout<<"wingless it flutters,"<<endl;
    cout<<"toothless it bites,"<<endl;
    cout<<"mouthless it mutters"<<endl;
    cout<<"what is it? (one word answer in lowercase letters please)"<<endl;
    //answer is wind
    cin.ignore();
    cin>>riddleanswer;
    //getline(cin,riddleanswer);
    cout<<"user answer: "<<riddleanswer<<endl;
    if(riddleanswer != "wind"){
        cout<<"That answer is wrong."<<endl;
        cout<<"Fire engulfs the room and you die."<<endl;
        return NULL;
    }
    cout<<endl;
    cout<<"Very well. I dont think you can beat my second riddle:"<<endl;
    cout<<endl;
    cout<<"A box without hinges, key, or lid,"<<endl;
    cout<<"yet golden treasure inside is hid."<<endl;
    cout<<"What is it? (one word answer, lowercase. it is A(n) ___."<<endl;
    //answer egg
    cin.ignore();
    cin>>riddleanswer;
    //getline(cin,riddleanswer);
    cout<<"user answer: "<<riddleanswer<<endl;
    if(riddleanswer != "egg"){
        cout<<"That answer is wrong."<<endl;
        cout<<"Fire engulfs the room and you die."<<endl;
        return NULL;
    }
    cout<<endl;
    cout<<"The voice, angry now says:"<<endl;
    cout<<"That doesnt matter, it is inconceivable that you would beat this last riddle."<<endl;
    cout<<endl;
    cout<<"This thing all things devours:"<<endl;
    cout<<"Birds, beasts, trees, flowers;"<<endl;
    cout<<"Gnaws iron, bites steel;"<<endl;
    cout<<"Grinds hard stones to meal;"<<endl;
    cout<<"Slays king, ruins town,"<<endl;
    cout<<"And beats high mountain down."<<endl;
    //the answer is: time
    cout<<"What is it? (one word, lowercase)"<<endl;
    cin.ignore();
    cin>>riddleanswer;
    cout<<"user answer: "<<riddleanswer<<endl;
    if(riddleanswer != "time"){
        cout<<"That answer is wrong."<<endl;
        cout<<"Fire engulfs the room and you die."<<endl;
        return NULL;
    }
    userinput = 1;
    do{
        if(userinput == 1){
            cout<<"You beat my riddles...very well. You may pass and consider yourself worthy."<<endl;
            cout<<"The fire disappears and you head through the door in front of you."<<endl;
            currentnode = currentnode->south;
        }
        else if(userinput > 2 || userinput <= 0){
            cout<<"invalid input. Please enter a number between 1 & 2"<<endl;
        }
    }while(userinput != 1);
    return currentnode;
}

/*
This room is the final room and simple says that that you have survived and won. It then sets the currentnode value to null and quits the
game. The other if/else if statement were used during the building process in case something went wrong in the setting of currentnode and
should not ever end up being displayed unless something goes wrong.
*/
Movement* GameBuilder::Room10(Movement *room){
    Movement *currentnode = room;
    int userinput;
    cout<<endl;
    cout<<"You have successfully made it through the building."<<endl;
    cout<<"You enter the room and find the treasure, congratulations"<<endl;
    userinput = 2;
    do{
        if(userinput == 1){
            cout<<"something went wrong"<<endl;
        }
        else if(userinput == 2){
            currentnode = NULL;
        }
        else if(userinput < 1 || userinput > 2){
            cout<<"invalid input. Please enter a number between 1 & 3"<<endl;
        }
    }while(userinput != 2);
    return currentnode;
}
