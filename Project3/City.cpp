#include <iostream>
#include "City.h"

using namespace std;

City::City()
{
    letter = ' ';
    name = "";
    capital = 0;
    sizeOfArmy = 0;
    points = 0;
    
}
City::City(char letter_, string name_ , int capital_ , int sizeOfArmy_, int points_)
{
    letter = letter_;
    name = name_;
    capital = capital_;
    sizeOfArmy = sizeOfArmy_;
    points = points_;
}

// setters
void City::citySetChar(char letter_)
{
    letter = letter_; 
}
void City::citySetName(string name_)
{
    name = name_;
}
void City::citySetCapital(int money_)
{
    capital = money_;
}
void City::citySetArmySize(int armySize_)
{
    sizeOfArmy = armySize_;
}
void City::citySetPoints(int points_)
{
    points = points_;
}

// getters:
char City::cityGetChar()
{
    return letter;
}
string City::cityGetName()
{
    return name;
}
int City::cityGetCapital()
{
    return capital;
}
int City::cityGetArmySize()
{
    return sizeOfArmy;
}
int City::cityGetPoints()
{
    return points;
}

// we good