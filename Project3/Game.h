#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream>

#include "Warrior.h"
#include "Map.h"
#include "Hero.h"
#include "City.h"

using namespace std;

// We have 7 heroes since the player can choose to create their own.
// ***** Note: DG means Dragonglass.

class Game{
    private:

        Warrior warriors[14];
        Hero heroes[7];
        Map gameMap;
        City cities[26];
        Warrior dragons[4];
        
        int landControl[25][16];

        int numHeroes;
        int numWarriors;
        int numCities;
        int numTurns;
        
        int playerHero;

        int heroPoints[7];

        bool ww;
        int imALittleB = 5;

        string deadNames;
        int deadPoints;

    public:

        Game();
        Game(int numTurns_, int numHeroes_, int numWarriors_ , int numCities_);

        // Helpers:
        void printGameMap();
        void printAllCities();
        void printAllWarriors();
        void printAllHeroes();
        void printGameDisplayMap();
        void dragonglassCoordinates();
        void showWarriorCoordinates();
        void showHeroesControlledLand();

        // Setters: (Completed!)
        void setTurns(int turns_);
        void setNumWarriors(int numWarriors_);
        void setNumHeroes(int numHeroes_);
        void setPlayerHero(int playerHero_);
        void setNewHero(Hero hero);
        void fillGameDisplayMap();
        void fillDragonglassMap();
        void initializeLandControl();
        void setLandControl(int index);
        void updateAllHeroPoints();
        void setWW(bool ww_);
        
        // Getters: (Completed!)
        int getTurns();
        int getNumHeroes();
        int getNumWarriors();
        int getNumCities();
        int getPlayerHeroIndex();
        int getPlayerTotalPoints();
        Hero getHeroAt(int index);
        Warrior getWarriorAt(int index);
        int getWarriorHero(int warriorIndex);
        bool heroDA();
        int getLandControl(int x, int y);
        int getHeroControlledLand(int heroIndex);
        bool getWW();

            // If a hero finds DG:
        void pickUpDragonglass(int heroIndex_);
            // If a FREE Warrior finds DG:
        void warriorPickUpDG(int warriorIndex_);
        
        // Complicated: Reading functions. (Completed!)
        void readMap(string filename_);
        void readWarriors(string filename_);
        void readHeroes(string filename_);
        void readCities(string filename_);
        
        // Game setup:
        void scatterWarriors();
        void scatterHeroes();
        void bindWarriors();
        

    // Gameplay

        // probbably the most important function of this part of the game.
        char getTileData(int x ,int y);
        void showPlayerMap();
        // Hero functions. and encounters
        
        
        int heroDistance();
        int heroHitbox(int heroIndex);
        void heroEncounter(int index1 , int index2);
            // These three functions are part of the encounter option:
            double giveASpeech(int index);
            double buyThem(int index);
            int battle(int index);
            void captureTiles(int index1 , int index2);
        void moveHeroes(int input , int index);

            // moving the other heroes and their warriors:
        void moveNPCs();
            // moving only the free roaming warriors:
        void moveWarriors(); 
        
        void cityEncounter(int heroIndex);
            int hearRumors(char city);
        
        void turnBasedEncounters();
            bool whiteWalkers();
            void drought();
            void deserters();
            void jackpot();
            void kindness();
            void dragonsFunction();
            void stannis();
            void arya();
            void jaime();
        
        // Turns
        int turn();
        void retireHeroAt(int index);
        
        // end of game
        
        void writeScores(string playerName, string fileName);
};







#endif