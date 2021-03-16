
#ifndef WARRIOR_H
#define WARRIOR_H

#include <iostream>
#include <string>

using namespace std;

class Warrior{
    private:
        string name;
        int strength;
        int loyalty;
        int morale;
        bool free;
        bool ship;
        bool dragonGlass;
        int locationX;
        int locationY;
        bool hasRecruited;
    public: 
        Warrior();
        Warrior(string name_ , int strength_ , int loyalty_ , int morale_ , bool free_ , bool ship_ , bool dragonGlass_ , int locationX_ , int locationY_, bool hasRecruited_);

        // Setters:
        void setName(string name_);
        void setStrength(int strength_);
        void setLoyalty(int loyalty_);
        void setMorale(int morale);
        void setFreedom(bool free_);
        void setShip(bool ship_);
        void setHasDragonglass(bool glass_);
        void setX(int locationX_);
        void setY(int locationY_);
        void setRecruited(bool recruited);

        // Getters:
        string getName();
        int getStrength();
        int getLoyalty();
        int getMorale();
        bool getFreedom();
        bool getShip();
        bool getHasDragonglass();
        int getLocationX();
        int getLocationY();
        bool getRecruited();
        
        // Other functions..
        bool isWarrior();
        void printWarriorStats();
        
};


#endif