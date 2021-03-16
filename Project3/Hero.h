

#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <string>
#include "Warrior.h"

using namespace std;

class Hero{
    private:
        string name;
        int money;
        int influence;
        int armySize;
        Warrior warriors[4];
        int locationX;
        int locationY;
        bool ship;
        int points;
        bool inBattle;
        bool death;

    public:
        Hero();
        Hero(string name_ , int money_ , int influence_ , int armySize_ , Warrior warriors[4], int locationX_ , int locationY_ , bool ship_, int points_ , bool inBattle_, bool death_);

        // Setters:
        void setName(string name_);
        void setMoney(int money_);
        void setInfluence(int influence_);
        void setArmySize(int armySize_);
        void setWarriorAt(Warrior warrior, int index);
        void setLocationX(int locationX_);
        void setLocationY(int locationY_);
        void setShip(bool ship_);
        void setPoints(int points_);
        void setInBattle(bool inBattle_);
        void setDeath(bool death_);
        
        // Getters:
        string getName();
        int getMoney();
        int getInfluence();
        int getArmySize();
        string getWarriorAt(int index);
        int getLocationX();
        int getLocationY();
        bool getHasShip();
        int getPoints();
        bool getInBattle();
        bool getDeath();
        
        // More Functions:
        void printHeroStats();
        void freeWarriors();

};

#endif