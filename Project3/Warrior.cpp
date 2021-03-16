#include <iostream>
#include <string>
#include "Warrior.h"

using namespace std;

Warrior::Warrior()
{
    name = "";
    strength = 0;
    loyalty = 0;
    morale = 0;
    free = false;
    ship = false;
    dragonGlass = false;
    hasRecruited = false;
}

Warrior::Warrior(string name_ , int strength_ , int loyalty_ , int morale_ , bool free_ , bool ship_ , bool dragonGlass_ , int locationX_ , int locationY_, bool hasRecruited_)
{
    name = name_;
    strength = strength_;
    loyalty = loyalty_;
    morale = morale_;
    free = free_;
    ship = ship_;
    dragonGlass = dragonGlass_;
    locationX = locationX_;
    locationY = locationY_;
    hasRecruited = hasRecruited_;
}

// implementation of all the setter functions..

void Warrior::setName(string name_)
{
    name = name_;
}
void Warrior::setStrength(int strength_)
{
    strength = strength_;
}
void Warrior::setLoyalty(int loyalty_)
{
    loyalty = loyalty_;
}
void Warrior::setMorale(int morale_)
{
    morale = morale_;
}
void Warrior::setFreedom(bool free_)
{
    free = free_;
}
void Warrior::setShip(bool ship_)
{
    ship = ship_;
}
void Warrior::setHasDragonglass(bool dragonGlass_)
{
    dragonGlass = dragonGlass_;
}
void Warrior::setX(int locationX_)
{
    locationX = locationX_;
}
void Warrior::setY(int locationY_)
{
    locationY = locationY_;
}
void Warrior::setRecruited(bool hasRecruited_)
{
    hasRecruited = hasRecruited_;
}

// Getter functions

string Warrior::getName()
{
    return name;
}
int Warrior::getStrength()
{
    return strength;
}
int Warrior::getLoyalty()
{
    return loyalty;
}
int Warrior::getMorale()
{
    return morale;
}
bool Warrior::getFreedom()
{
    return free;
}
bool Warrior::getShip()
{
    return ship;
}
bool Warrior::getHasDragonglass()
{
    return dragonGlass;
}
int Warrior::getLocationX()
{
    return locationX;
}
int Warrior::getLocationY()
{
    return locationY;
}
bool Warrior::getRecruited()
{
    return hasRecruited;
}

// Implementation of the complex functions..

/*
bool Warrior::isWarrior()
{
    if(name == "")
    {
        return false;
    }
}
*/

/*
void Warrior::printWarriorStats()
{
    cout << "Warrior: " << name << endl;
    cout << "Strength: " << strength << endl;
    cout << "Loyalty: " << loyalty << endl;
    cout << "Morale: " << morale << endl;
    if(free == false)
    {
        cout << "Freedom: " << "false" << endl;
    } else {
        cout << "Freedom: " << "true" << endl;
    }
    if(ship == false)
    {
        cout << "Ships: " << "No" << endl;
    } else {
        cout << "Freedom: " << "Yes" << endl;
    }
    if(dragonGlass == false)
    {
        cout << "Dragonglass? " << "None" << endl;
    } else {
        cout << "Dragonglass? " << "Has Dragonglass" << endl;
    }
}
*/
