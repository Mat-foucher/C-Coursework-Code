#ifndef CITY_H
#define CITY_H

#include <iostream>

using namespace std;

class City{
    private:
        char letter;
        string name;
        // Here the use of "capital" means money.
        int capital;
        int sizeOfArmy;
        int points;
    public:
        City();
        City(char letter_ , string name_ , int capital_ , int sizeOfArmy_ , int points_);

        // Setters:
        void citySetChar(char letter_);
        void citySetName(string name_);
        void citySetCapital(int money_);
        void citySetArmySize(int armySize_);
        void citySetPoints(int points_);
        
        // Getters:
        char cityGetChar();
        string cityGetName();
        int cityGetCapital();
        int cityGetArmySize();
        int cityGetPoints();
        

};


#endif