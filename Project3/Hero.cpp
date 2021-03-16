#include <iostream>
#include "Hero.h"

using namespace std;

Hero::Hero()
{
    name = "";
    money = 0;
    influence = 0;
    armySize = 0;
    locationX = 0;
    locationY = 0;
    ship = false;
    points = 0;
}
Hero::Hero(string name_ , int money_ , int influence_ , int armySize_ , Warrior warriors[4], int locationX_ , int locationY_ , bool ship_, int points_, bool inBattle_, bool death_)
{
    name = name_;
    money = money_;
    influence = influence_;
    armySize = armySize_;
    for(int i = 0; i < 4; i++)
    {
        warriors[i] = Warrior();
    }
    locationX = locationX_;
    locationY = locationY_;
    ship = ship_;
    points = points_;
    death = death_;
}

// Setter Functions:

void Hero::setName(string name_)
{
    name = name_;
}
void Hero::setMoney(int money_)
{
    money = money_;
}
void Hero::setInfluence(int influence_)
{
    influence = influence_;
}
void Hero::setArmySize(int armySize_)
{
    armySize = armySize_;
}
void Hero::setWarriorAt(Warrior warrior , int index)
{
    if(index < 0 || index > 3)
    {
        cout << "Please enter valid index for warrior" << endl;
    } else {
        warriors[index] = warrior;
    }
}
void Hero::setLocationX(int locationX_)
{
    //cout << "Updating location" << endl;
    locationX = locationX_;
}
void Hero::setLocationY(int locationY_)
{
    locationY = locationY_;
}
void Hero::setShip(bool ship_)
{
    ship = ship_;
}
void Hero::setPoints(int points_)
{
    points = points_;
}
void Hero::setInBattle(bool inBattle_)
{
    inBattle = inBattle_;
}
void Hero::setDeath(bool death_)
{
    death = death_;
}

// Getters:

string Hero::getName()
{
    return name;
}
int Hero::getMoney()
{
    return money;
}
int Hero::getInfluence()
{
    return influence;
}
int Hero::getArmySize()
{
    return armySize;
}
string Hero::getWarriorAt(int index)
{
    if(index < 0 || index > 3)
    {
        cout << "Invalid warrior index! Please enter valid index" << endl;
        return "";
    } else {
        return warriors[index].getName();
    }

}
int Hero::getLocationX()
{
    return locationX;
}
int Hero::getLocationY()
{
    return locationY;
}
bool Hero::getHasShip()
{
    bool warriorShip = false;

    for(int i = 0; i < 4; i++)
    {
        if(warriors[i].getShip() == true)
        {
            warriorShip = true;
            break;
        }
    }

    if(warriorShip == true || ship == true)
    {
        return true;
    } else {
        return false;
    }
}
int Hero::getPoints()
{
    return points;
}
bool Hero::getInBattle()
{
    return inBattle;
}
bool Hero::getDeath()
{
    return death;
}


// More Complicated Functions:

/*
void Hero::printHeroStats()
{
    cout << "Name: " << name << endl;
    cout << "Money: " << money << endl;
    cout << "Influence: " << influence << endl;
    cout << "Army Size: " << armySize << endl;
    cout << "======= Warriors =======" << endl;

    // Print the warriors associated with the hero.
}
*/

void Hero::freeWarriors()
{
    for(int i = 0; i < 4; i++)
    {
        warriors[i].setFreedom(true);
    }
}