#ifndef GAMEBUILDER_H
#define GAMEBUILDER_H
#include <iostream>


/*
This is the struct created that will be used for the creation of rooms, movement between rooms and the name of each room/how each room is
defined.
*/
struct Movement{
    std::string roomName;
    Movement *north;
    Movement *south;
    Movement *east;
    Movement *west;
    int movementroomvalue;
};

/*
This class consists of many public functions that are needed. It has a buildNetwork that builds the rooms as nodes, a deathcounter for
keeping track of lives (it counts down) and functions for every room designed and any menus needed. Menus with a SR or R# specify which
room that menu applies to, for example menuSR - applies to the startingroom and menu R2 applies to room2.
*/
class GameBuilder
{
    public:
        GameBuilder();
        virtual ~GameBuilder();

        int deathcounter = 3;

        void buildNetwork();

        int menuSR();
        int menuR1();
        int menuR2();
        int menuR5();
        int menuR7();
        int menuR8();
       // int menuR9();

        Movement* StartRoom(Movement *room);
        Movement* Room1(Movement *room);
        Movement* Room2(Movement *room);
        Movement* Room3(Movement *room);
        Movement* Room4(Movement *room);
        Movement* Room5(Movement *room);
        Movement* Room6(Movement *room);
        Movement* Room7(Movement *room);
        Movement* Room8(Movement *room);
        Movement* Room9(Movement *room);
        Movement* Room10(Movement *room);

        Movement *head;
        Movement *tail;
    protected:
    private:
};

#endif // GAMEBUILDER_H
