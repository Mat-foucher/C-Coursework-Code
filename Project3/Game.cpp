#include <iostream>
#include <string>
#include <cmath>
#include "Game.h"

using namespace std;

int split(string splitStr, char sep, string words[], int size)
{ // split function with string separartors and size as parameters 
        int position=0; 
        int j=0;
            
        splitStr = splitStr + sep;  // string is string with separators 
            for(int i=0 ; i< splitStr.length() ; i++ )
            { // the loop calculates if the sep is equal to the spring at that length then calc the length 
                if (splitStr[i] == sep)
                {
                    string word = splitStr.substr(position, i-position);
                // if the word is empty 
                    if(word.length() > 0)
                    {
                        words[j]= word;
                        j++;
                    }
                    if(j >= size)
                    { // if the spaces are graeter than the size 
                        return -1; 
                    }
                    
                    position = i + 1; 
                }
            }
            return j; 
}

Game::Game()
{
    numTurns = 0;
    numWarriors = 0;
    numHeroes = 0;
    numCities = 0;
    ww = false;
}
Game::Game(int numTurns_ , int heroes_ , int warriors_ , int numCities_)
{
    numTurns = numTurns_;
    numHeroes = heroes_;
    numWarriors = warriors_;
    numCities = numCities_;
}

// Helpers:

void Game::printGameDisplayMap()
{
    cout << "Display Map: " << endl;
    gameMap.printDisplayMap();
}

void Game::printGameMap()
{
    cout << "Game Map: " << gameMap.getBoardHeight() << " " << gameMap.getBoardWidth() << endl;
    for(int i = 0; i < 25; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            cout << gameMap.getTile(i,j) << " ";
        }
        cout << endl;
    }
}

void Game::printAllCities()
{
    for(int i = 0; i < numCities; i++)
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "City: " << cities[i].cityGetName() << endl;
        cout << "Map Tile : " << cities[i].cityGetChar() << endl;
        cout << "Capital: " << cities[i].cityGetCapital() << endl;
        cout << "Army Size: " << cities[i].cityGetArmySize() << endl;
        cout << "City Points: " << cities[i].cityGetPoints() << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
}

void Game::printAllWarriors()
{
    for(int i = 0; i < numWarriors; i++)
    {
        cout << "=====================================" << endl;
        cout << "Warrior: " << warriors[i].getName() << endl;
        cout << "Strength: " << warriors[i].getStrength() << endl;
        cout << "Loyalty: " << warriors[i].getLoyalty() << endl;
        cout << "Morale: " << warriors[i].getMorale() << endl;
        if(warriors[i].getFreedom() == 0)
        {
            cout << "Freedom? " << "no" << endl;
        } else {
            cout << "Freedom? " << "yes" << endl;
        }
        if(warriors[i].getShip() == 0)
        {
            cout << "Ship? " << "no" << endl;
        } else {
            cout << "Ship? " << "yes" << endl;
        }
        if(warriors[i].getHasDragonglass() == 0)
        {
            cout << "Dragonglass? " << "no" << endl;
        } else {
            cout << "Dragonglass? " << "yes" << endl;
        }

    }
}

void Game::printAllHeroes()
{
    for(int i = 0; i < numHeroes; i++)
    {
        cout << "*********************************" << endl;
        cout << "Name: " << heroes[i].getName() << endl;
        cout << "Points: " << heroes[i].getPoints() << endl;
        cout << "Money: " << heroes[i].getMoney() << endl;
        cout << "Influence: " << heroes[i].getInfluence() << endl;
        cout << "Army Size: " << heroes[i].getArmySize() << endl;
        cout << "Warriors: " << endl;
        for(int j = 0; j < 4; j++)
        {
            cout << "   " << heroes[i].getWarriorAt(j) << endl;
        }
        if(heroes[i].getHasShip() == 0)
        {
            cout << "Ship? " << "False" << endl;
        } else {
            cout << "Ship? " << "True" << endl;
        }
        cout << "Current Location: " << " X = " << heroes[i].getLocationX() << ", Y = " << heroes[i].getLocationY() << endl;
        cout << "Tile: " << getTileData(heroes[i].getLocationX() , heroes[i].getLocationY());
        for(int j = 0; j < numCities; j++)
        {
            if(getTileData(heroes[i].getLocationX() , heroes[i].getLocationY()) == cities[j].cityGetChar())
            {
                cout << ", " << cities[j].cityGetName();
            }
        }
        cout << endl;
        cout << "*********************************" << endl;
    }
}

void Game::dragonglassCoordinates()
{
    gameMap.dragonGlassCoordinates();
}

void Game::showWarriorCoordinates()
{
    cout << "===== Warriors =====" << endl;
    cout << "***** Free Roaming: " << endl;
    for(int i = 0; i < numWarriors; i++)
    {
        if(warriors[i].getFreedom() == true)
        {
            cout << warriors[i].getName() << ": " << " X = " << warriors[i].getLocationX() << ", Y = " << warriors[i].getLocationY();
            cout << " Tile: " << gameMap.getTile(warriors[i].getLocationX() , warriors[i].getLocationY()) << endl; 
        }
    }

    cout << "***** Non-Free Roaming: " << endl;
    for(int i = 0; i < numWarriors; i++)
    {
        if(warriors[i].getFreedom() == false)
        {
            cout << warriors[i].getName() << ": " << " X = " << warriors[i].getLocationX() << ", Y = " << warriors[i].getLocationY(); 
            cout << " Tile: " << gameMap.getTile(warriors[i].getLocationX() , warriors[i].getLocationY()) << endl;
        }
    }
}

// Setters:

void Game::setTurns(int turns_)
{
    numTurns = turns_;
}
void Game::setNumWarriors(int numWarriors_)
{
    numWarriors = numWarriors_;
}
void Game::setNumHeroes(int numHeroes_)
{
    numHeroes = numHeroes_;
}
void Game::setPlayerHero(int playerHero_)
{
    playerHero = playerHero_;
}
void Game::setNewHero(Hero hero)
{
    heroes[6] = hero;
    numHeroes++;
}
void Game::fillGameDisplayMap()
{
    gameMap.fillDisplayMap();
}
void Game::fillDragonglassMap()
{
    gameMap.placeDragonglass();
}
void Game::initializeLandControl()
{
    for(int i = 0; i < 25; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            landControl[i][j] = -1;
        }
    }
}
void Game::setLandControl(int index)
{
    if(index < 0 || index > 6)
    {
        cout << "Enter valid HERO index for land control." << endl;
    } else {
        int x = heroes[index].getLocationX();
        int y = heroes[index].getLocationY();

        landControl[y][x] = index;
    }
}

void Game::updateAllHeroPoints()
{
    
    // Outermost for loop goes through all heroes;
    for(int i = 0; i< numHeroes; i++)
    {
        int points = heroes[i].getPoints();
        //cout << "Starting points: " << points << endl;
        for(int j = 0; j < 16; j++)
        {
            for(int k = 0; k < 25; k++)
            {
                
                if(getLandControl(j , k) == i)
                {
                    if(getTileData(j,k) == 'w' )
                    {
                        
                        points++;
                        //cout << "Water " << points << endl;
                                     
                    }
                    if(getTileData(j,k) == 'p')
                    {
                        points = points + 2;
                        //cout << "Land " << points << endl;
                    }

                    if(getTileData(j,k) != 'w' || getTileData(j,k) != 'p')
                    {
                        //cout << "Skeet " << i << endl;
                        for(int h = 0; h < numCities; h++)
                        {
                            if(getTileData(j,k) == cities[h].cityGetChar())
                            {
                                points = points + cities[h].cityGetPoints();
                            }
                        }
                    } else {
                        points = points + 0;
                    }
                    
                }
            }
        }
        //cout << "Hero: " << heroes[i].getName() << ", Points: " << points << endl;
        heroes[i].setPoints(points);
    }
}

void Game::setWW(bool ww_)
{
    ww = ww_;
}

// Getters:

int Game::getTurns()
{
    return numTurns;
}
int Game::getNumHeroes()
{
    return numHeroes;
}
int Game::getNumWarriors()
{
    return numWarriors;
}

char Game::getTileData(int x , int y)
{
    char tile = gameMap.getTile(y , x);

    return tile;
}

int Game::getNumCities()
{
    return numCities;
}

int Game::getPlayerHeroIndex()
{
    return playerHero;
}

Hero Game::getHeroAt(int index)
{
    if(index < 0 || index > 6)
    {
        cout << "Invalid index for WARRIOR." << endl;
        return Hero();
    } else {
        return heroes[index];
    }
}

Warrior Game::getWarriorAt(int index)
{
    if(index < 0 || index > 13)
    {
        cout << "Invalid index for WARRIOR." << endl;
        return Warrior();
    } else {
        return warriors[index];
    }
}

void Game::pickUpDragonglass(int heroIndex_)
{
    int x = heroes[heroIndex_].getLocationX();
    int y = heroes[heroIndex_].getLocationY();

    int counter = 0;

    if(gameMap.getDragonglass(x,y) == true)
    {
        
        for(int i = 0; i < 4; i++)
        {
            string warrior = heroes[heroIndex_].getWarriorAt(i);
            for(int j = 0; j < numWarriors; j++)
            {
                if(warrior == warriors[j].getName())
                {
                    warriors[j].setHasDragonglass(true);
                    counter++;
                }
            }
            
        }
        if(counter > 0)
        {
            gameMap.setDragonglass(x,y,false);
        } else {
            //cout << heroes[heroIndex_].getName() << " cannot acquire dragonglass as they have no warriors." << endl;
        }
    }
}

void Game::warriorPickUpDG(int warrIndex)
{
    int x = warriors[warrIndex].getLocationX();
    int y = warriors[warrIndex].getLocationY();


    if(gameMap.getDragonglass(x,y) == true && warriors[warrIndex].getHasDragonglass() == false)
    {
        //cout << "The Warrior " << warriors[warrIndex].getName() << " is now equipped with dragonglass." << endl;
        warriors[warrIndex].setHasDragonglass(true);
    }
}

bool Game::heroDA()
{
    return heroes[playerHero].getDeath();
}

int Game::getLandControl(int x , int y)
{
    if((x >= 0 && y>=0) && (x < 16 && y < 25))
    {
        return landControl[y][x];
    } else {
        cout << "Not a valid MAP tile." << endl;
        return -2;
    }
}

int Game::getHeroControlledLand(int heroIndex)
{
    // Starts at 1 since the starting tiles of heroes are not recorded.
    int counter = 1;

    if(heroIndex < 0 || heroIndex > 6)
    {
        cout << "Invalid HERO index for controlled land!" << endl;
        return -1;
    } else {

        

        for(int i = 0; i < 25; i++)
        {
            for(int j = 0; j < 16; j++)
            {
                if(landControl[i][j] == heroIndex)
                {
                    counter++;
                }
            }
        }
    }

    return counter;
}

bool Game::getWW()
{
    return ww;
}




// Complex Functions:

    // reading functions:

    // readMap is working (:
void Game::readMap(string filename_)
{
    // Will read the file containing the information for the map and populate the map array.

    int count = 0;

    char sep = ',';

    string str = "";

    ifstream fileHandle;
    fileHandle.open(filename_);

    if(!fileHandle.is_open())
    {
        cout << "ERROR: Cannot open MAP file." << endl;
    } else {
        while(getline(fileHandle, str))
        {
            //cout << str << endl;
            gameMap.fillBoardRow(count , str , sep);
            count++;
        }
        gameMap.setMapSizeHorizontal(16);
        gameMap.setMapSizeVertical(count);
    }

}
    // readWarriors is working (:
void Game::readWarriors(string filename_)
{
    // This function will read the file and set up all of the warriors.
    int counter3 = 0;

    string str = "";
    string warriorSplit[7];

    ifstream fileHandle;
    fileHandle.open(filename_);

    if(!fileHandle.is_open())
    {
        cout << "ERROR: Could not open WARRIORS file." << endl;
    } else {
        while(getline(fileHandle , str))
        {
            split(str , ',' , warriorSplit , 7);
            for(int i = 0; i < 7; i++)
            {
                if(i == 0)
                {
                    warriors[counter3].setName(warriorSplit[i]);
                }
                if(i == 1)
                {
                    int strong = stoi(warriorSplit[i]);
                    warriors[counter3].setStrength(strong);
                }
                if(i == 2)
                {
                    int loyalMofo = stoi(warriorSplit[i]);
                    warriors[counter3].setLoyalty(loyalMofo);
                }
                if(i == 3)
                {
                    int morals = stoi(warriorSplit[i]);
                    warriors[counter3].setMorale(morals);
                }
                if(i == 4)
                {
                    if(warriorSplit[i] == "no")
                    {
                        warriors[counter3].setFreedom(false);
                    } else {
                        warriors[counter3].setFreedom(true);
                    }
                }
                if(i == 5)
                {
                    if(warriorSplit[i] == "no")
                    {
                        warriors[counter3].setShip(false);
                    } else {
                        warriors[counter3].setShip(true);
                    }
                }
                if(i == 6)
                {
                    string yesPlease = warriorSplit[i];
                    if(yesPlease[0] == 'y')
                    {
                        warriors[counter3].setHasDragonglass(true);
                    } else {
                        warriors[counter3].setHasDragonglass(false);
                    }
                }
            }
            counter3++;
        }
        numWarriors = counter3;
    }
    
}
    // readHeroes is working (:
void Game::readHeroes(string filename_)
{
    // This function will read the file containing the heroes and set up all of the heroes.
    int counter4 = 0;

    string heroTemp[11];
    string str = "";
    ifstream fileHandle;
    fileHandle.open(filename_);

    if(!fileHandle.is_open())
    {
        cout << "ERROR: Could not open HEROES file." << endl;
    } else {
        while(getline(fileHandle , str))
        {
            split(str , ',' , heroTemp , 11);

            for(int i = 0; i < 11; i++)
            {
                if(i == 0)
                {
                    heroes[counter4].setName(heroTemp[i]);
                    heroes[counter4].setDeath(false);
                }
                if(i == 1)
                {
                    int mony = stoi(heroTemp[i]);
                    heroes[counter4].setMoney(mony);
                }
                if(i == 2)
                {
                    int inf = stoi(heroTemp[i]);
                    heroes[counter4].setInfluence(inf);
                }
                if(i == 3)
                {
                    int army = stoi(heroTemp[i]);
                    heroes[counter4].setArmySize(army);
                }
                if(i >= 4 && i < 8)
                {
                    
                    
                    for(int j = 0; j < numWarriors; j++)
                    {
                        bool isMatch = false;
                        if(heroTemp[i] == warriors[j].getName())
                        {
                            heroes[counter4].setWarriorAt(warriors[j] , i%4);
                            isMatch = true;
                        }
                        //cout << heroes[counter4].getName() << " " << heroTemp[i] << " " << warriors[j].getName() << " " << isMatch << endl;
                    }
                }
                if(i == 8)
                {
                    int y = stoi(heroTemp[i]);
                    y--;
                    heroes[counter4].setLocationY(y);
                }
                if(i == 9)
                {
                    int x = stoi(heroTemp[i]);
                    x--;
                    heroes[counter4].setLocationX(x);
                }
                if(i == 10)
                {
                    string yes = heroTemp[i];
                    if(yes[0] == 'y')
                    {
                        heroes[counter4].setShip(true);
                    } else {
                        heroes[counter4].setShip(false);
                    }
                }
            }
            counter4++;
        }
        numHeroes = counter4;
    }

}
    // readCities is working (:
void Game::readCities(string filename_)
{
    // This function will read the file containing all of the information for the cities and set up the cities.
    int leCounter = 0;

    string str = "";
    string cityTemp[5];

    ifstream fileHandle;
    fileHandle.open(filename_);

    if(!fileHandle.is_open())
    {
        cout << "ERROR: Could not open WARRIORS file." << endl;
    } else {
        while(getline(fileHandle, str))
        {
            split(str , ',' , cityTemp , 5);
            for(int i = 0; i<5; i++)
            {
                if(i == 0)
                {
                    cities[leCounter].citySetChar(str[0]); 
                }
                if(i == 1)
                {
                    cities[leCounter].citySetName(cityTemp[1]);
                }
                if(i == 2)
                {
                    // Here the use of "capital" means money. 
                    int cityCapital = stoi(cityTemp[2]);
                    cities[leCounter].citySetCapital(cityCapital);
                }
                if(i == 3)
                {
                    int armS = stoi(cityTemp[3]);
                    cities[leCounter].citySetArmySize(armS);
                }
                if(i == 4)
                {
                    int pts = stoi(cityTemp[4]);
                    cities[leCounter].citySetPoints(pts);
                }
                
            }
            //cout << cities[leCounter].cityGetChar() << cities[leCounter].cityGetName() << cities[leCounter].cityGetCapital() << cities[leCounter].cityGetArmySize() << cities[leCounter].cityGetPoints() << endl;
            leCounter++;
        }
        numCities = leCounter;
    }
}

    // Game setup:

// Scatter Warriors is working (:
void Game::scatterWarriors()
{
    // This function will put the warriors in their appropriate positions on the map (x,y).
    for(int i = 0; i<numWarriors; i++)
    {
        int x = 0;
        int y = 0;
        bool isWater = true;

        while(isWater == true)
        {
            x = rand() % 16;
            y = rand() % 25;
            if(gameMap.getTile(x,y) != 'w')
            {
                if(warriors[i].getFreedom() == true)
                {
                    warriors[i].setX(x);
                    warriors[i].setY(y);
                }
                isWater = false;
            } else {
                isWater = true;
            }
        }
    }
}

//                                         |
// We did not end up needing this function V
/*
// We may not need this function because the hero locations are read from the file.
void Game::scatterHeroes()
{
    // This function will place the heroes in the appropriate positions on the map, and furthermore
    // this function will place their associated positions.
}
*/

void Game::bindWarriors()
{
    // bindWarriors makes sure that all warriors attached to a hero will be at the same coordinates as their hero.
    for(int i = 0; i < numWarriors; i++)
    {
        if(warriors[i].getFreedom() == false)
        {
            for(int j = 0; j < numHeroes; j++)
            {
                for(int k = 0; k < 4; k++)
                {
                    if(warriors[i].getName() == heroes[j].getWarriorAt(k))
                    {
                        // The coordinates are like this, because the map has been updated with mismatched coordinates.
                        warriors[i].setX(heroes[j].getLocationY());
                        warriors[i].setY(heroes[j].getLocationX());
                    }
                }
            }
        }
    }
}

    // Encounters
int Game::heroHitbox(int heroIndex)
{
    // This function is simply a bool, where if another hero or warrior is within distance 2 (see writeup or formula)
    // if such a phenomena occurs, this function will return true and an encounter will occurr.

    // ! WARNING ! Ugly code ahead:
    
    if(heroes[heroIndex].getDeath() == false)
    {
        if(heroIndex < 0 || heroIndex > numHeroes)
        {
            cout << "Invalid HERO index." << endl;
        } else {

            int x = heroes[heroIndex].getLocationX();
            int y = heroes[heroIndex].getLocationY();
            
                for(int i = y-2; i < y+3; i++)
                {
                    for(int j = x-2; j < x+3; j++)
                    {
                        // How to pick up free warriors in hero's hitbox.
                        for(int m = 0; m < numWarriors; m++)
                        {
                            
                            if((warriors[m].getRecruited() == false && warriors[m].getFreedom() == true) && (warriors[m].getLocationX() == j && warriors[m].getLocationY() == i))
                            {
                                int counterHeroWarrs = 0;
                                
                                for(int e = 0; e < 4; e++)
                                {
                                    for(int f = 0; f < numWarriors; f++)
                                    {
                                        if(heroes[heroIndex].getWarriorAt(e) == warriors[f].getName())
                                        {
                                            counterHeroWarrs++;
                                        }
                                    }
                                }
                                if(counterHeroWarrs < 4)
                                {
                                    if(heroIndex == playerHero)
                                    {
                                        char yesNoAcquire = ' ';
                                        cout << "My liege, we have encountered warrior " << warriors[m].getName() << endl;
                                        cout << "Do you wish to recruit them? Y/N" << endl;

                                        cin >> yesNoAcquire;
                                        if(yesNoAcquire == 'y' || yesNoAcquire == 'Y')
                                        {
                                            heroes[heroIndex].setWarriorAt(warriors[m], counterHeroWarrs);
                                            cout << "Acquired Warrior: " << warriors[m].getName() << endl;
                                            warriors[m].setFreedom(false);
                                        } else if(yesNoAcquire == 'n' || yesNoAcquire == 'N')
                                        {
                                            cout << "Very well, let us be on our way." << endl;
                                            warriors[m].setRecruited(true);
                                            
                                        } else {
                                            cout << "Invalid input, enter 'y' or 'Y' for yes and 'n' or 'N' for no." << endl;
                                        }
                                    } else {
                                        heroes[heroIndex].setWarriorAt(warriors[m], counterHeroWarrs);
                                        warriors[m].setFreedom(false);
                                        //cout << "Acquired Warrior: " << warriors[m].getName() << endl;
                                    }
                                }
                                
                            }
                        }

                        // How to detect other heroes.
                        for(int k = 0; k < numHeroes; k++)
                        {
                            
                            if((heroes[k].getLocationX() == j && heroes[k].getLocationY() == i) && (k != heroIndex && heroes[k].getInBattle() == false))
                            {
                                
                                //cout << heroes[heroIndex].getName() << " v.s " << heroes[k].getName() << endl;
                                heroes[k].setInBattle(true);
                                return k;
                                break;
                            }
                        }
                        
                    }
                }
            return -1;
        }
            
    } else {
        return -1;
    }
    return -1;
}
void Game::heroEncounter(int index1 , int index2)
{
    // This function initiates the encounter between heroes, the functions below will be used depending on the choices of the hero.
    if((heroes[index1].getDeath() == false && heroes[index2].getDeath() == false) && (index1 >= 0 && index2 >= 0) && (index1 < numHeroes && index2 < numHeroes))
    {
        int opponent = 0;

        if(index1 == playerHero)
        {
            opponent = index2;
        } else if(index2 == playerHero){
            opponent = index1;
        }

        // If player versus non-player:
        if(index1 == playerHero || index2 == playerHero)
        {
            heroes[playerHero].setInBattle(true);
            int choice = 0;
            cout << "My liege, our opponent " << heroes[opponent].getName() << " approaches, what shall we do?" << endl;
            cout << "----------------------- OPTIONS --------------------" << endl;
            cout << "1: Give Speech " << endl;
            cout << "2: Buy Them Outright " << endl;
            cout << "3: Battle! " << endl;

            cin.ignore();
            cin >> choice;

            if(choice < 1 || choice > 3)
            {
                cout << "Choose a valid MENU option." << endl;
            } else {
                if(choice == 1)
                {
                    double speech = giveASpeech(opponent);
                    if(giveASpeech(opponent) < 0.60)
                    {
                        // Player Loss
                        cout << "Your Chance: " << speech << endl;
                        cout << "Winner: " << heroes[opponent].getName() << endl;
                        
                        int inf = heroes[playerHero].getInfluence();
                        inf = inf / 2;
                        heroes[playerHero].setInfluence(inf);
                        
                        if(heroes[playerHero].getInfluence() <= 0)
                        {
                            //cout << "You lost because you had zero influence remaining." << endl;
                            retireHeroAt(playerHero);
                        }

                        heroes[opponent].setInBattle(false);
                        heroes[playerHero].setInBattle(false);
                        
                    } else if(giveASpeech(index2) >= 0.60){
                        //cout << heroes[opponent].getName() << " has been defeated." << endl;

                        // Get their warriors:
                        int heroWarriors = 0;
                        int opponentWarriors = 0;

                        for(int i = 0; i < 4; i++)
                        {
                            for(int j = 0; j < numWarriors; j++)
                            {
                                if(heroes[playerHero].getWarriorAt(i) == warriors[j].getName())
                                {
                                    heroWarriors++;                                    
                                }
                            }
                        }

                        for(int i = 0; i < 4; i++)
                        {
                            for(int j = 0; j < numWarriors; j++)
                            {
                                if(heroes[index2].getWarriorAt(i) == warriors[j].getName())
                                {
                                    opponentWarriors++;
                                }
                            }
                        }

                        if(opponentWarriors > 0 && heroWarriors < 4)
                        {
                            // This counter is to count for the index of new warriors to be added to the hero's warrior bank.
                            int counter = 0;
                            cout << "Acquired Warriors: " << endl;
                            for(int i = 0; i < 4; i++)
                            {
                                for(int j = 0; j < numWarriors; j++)
                                {
                                    if(heroes[opponent].getWarriorAt(i) == warriors[j].getName())
                                    {
                                        cout << heroWarriors+counter << " " << warriors[j].getName() << endl;
                                        heroes[playerHero].setWarriorAt(warriors[j] , heroWarriors + counter);
                                        counter++;
                                    }
                                }
                            }
                        } else {
                            cout << "No Warriors added." << endl;
                        }

                        // Player Win
                        

                            // Get their Money:
                        int money = heroes[opponent].getMoney();
                        int money2 = heroes[playerHero].getMoney();
                        money = money + money2;
                        heroes[playerHero].setMoney(money);

                            // Get their Influence:
                        int inf = heroes[opponent].getInfluence();
                        int inf2 = heroes[playerHero].getInfluence();
                        inf = inf + inf2;
                        heroes[playerHero].setInfluence(inf);

                            // Get their Army Size:
                        int arrS = heroes[opponent].getArmySize();
                        int arrS1 = heroes[playerHero].getArmySize();
                        arrS = arrS + arrS1;
                        heroes[playerHero].setArmySize(arrS);

                            // Get their tiles:
                        captureTiles(playerHero , opponent);

                            // setBattle:
                        heroes[playerHero].setInBattle(false);
                        retireHeroAt(opponent);
                    }
                }
                if(choice == 2)
                {
                    double buy = buyThem(opponent);
                    if(buyThem(opponent) < 0.60)
                    {
                        cout << "Your Chance: " << buy << endl;
                        cout << "Winner: " << heroes[opponent].getName() << endl;

                        int money = heroes[playerHero].getMoney();
                        money = money/2;
                        heroes[playerHero].setMoney(money);

                        if(heroes[playerHero].getMoney() <= 0 || buy ==0)
                        {
                            retireHeroAt(playerHero);
                        }

                        heroes[opponent].setInBattle(false);
                        heroes[playerHero].setInBattle(false);
                    } else if(buyThem(opponent) >= 0.60)
                    {
                        // Get their warriors:
                        int heroWarriors = 0;
                        int opponentWarriors = 0;

                        for(int i = 0; i < 4; i++)
                        {
                            for(int j = 0; j < numWarriors; j++)
                            {
                                if(heroes[playerHero].getWarriorAt(i) == warriors[j].getName())
                                {
                                    heroWarriors++;                                    
                                }
                            }
                        }

                        for(int i = 0; i < 4; i++)
                        {
                            for(int j = 0; j < numWarriors; j++)
                            {
                                if(heroes[index2].getWarriorAt(i) == warriors[j].getName())
                                {
                                    opponentWarriors++;
                                }
                            }
                        }

                        if(opponentWarriors > 0 && heroWarriors < 4)
                        {
                            // This counter is to count for the index of new warriors to be added to the hero's warrior bank.
                            int counter = 0;
                            cout << "Acquired Warriors: " << endl;
                            for(int i = 0; i < 4; i++)
                            {
                                for(int j = 0; j < numWarriors; j++)
                                {
                                    if(heroes[opponent].getWarriorAt(i) == warriors[j].getName())
                                    {
                                        cout << heroWarriors+counter << " " << warriors[j].getName() << endl;
                                        heroes[playerHero].setWarriorAt(warriors[j] , heroWarriors + counter);
                                        counter++;
                                    }
                                }
                            }
                        } else {
                            cout << "No Warriors added." << endl;
                        }

                        // Player Win
                        

                            // Get their Money:
                        int money = heroes[opponent].getMoney();
                        int money2 = heroes[playerHero].getMoney();
                        money = money + money2;
                        heroes[playerHero].setMoney(money);

                            // Get their Influence:
                        int inf = heroes[opponent].getInfluence();
                        int inf2 = heroes[playerHero].getInfluence();
                        inf = inf + inf2;
                        heroes[playerHero].setInfluence(inf);

                            // Get their Army Size:
                        int arrS = heroes[opponent].getArmySize();
                        int arrS1 = heroes[playerHero].getArmySize();
                        arrS = arrS + arrS1;
                        heroes[playerHero].setArmySize(arrS);

                            // Get their tiles:
                        captureTiles(playerHero , opponent);

                            // setBattle:
                        retireHeroAt(opponent);
                        heroes[playerHero].setInBattle(false);
                    }
                }
                if(choice == 3)
                {
                    // Battle:
                    int b = battle(opponent);
                    if(b == 1)
                    {
                         // Get their warriors:
                        int heroWarriors = 0;
                        int opponentWarriors = 0;
                        //cout << "Acquired Warriors: " << endl;
                        for(int i = 0; i < 4; i++)
                        {
                            for(int j = 0; j < numWarriors; j++)
                            {
                                if(heroes[playerHero].getWarriorAt(i) == warriors[j].getName())
                                {
                                    heroWarriors++;                                    
                                }
                            }
                        }

                        for(int i = 0; i < 4; i++)
                        {
                            for(int j = 0; j < numWarriors; j++)
                            {
                                if(heroes[index2].getWarriorAt(i) == warriors[j].getName())
                                {
                                    opponentWarriors++;
                                }
                            }
                        }

                        if(opponentWarriors > 0 && heroWarriors < 4)
                        {
                            // This counter is to count for the index of new warriors to be added to the hero's warrior bank.
                            int counter = 0;
                            cout << "Acquired Warriors: " << endl;
                            for(int i = 0; i < 4; i++)
                            {
                                for(int j = 0; j < numWarriors; j++)
                                {
                                    if(heroes[opponent].getWarriorAt(i) == warriors[j].getName())
                                    {
                                        cout << heroWarriors+counter << " " << warriors[j].getName() << endl;
                                        heroes[playerHero].setWarriorAt(warriors[j] , heroWarriors + counter);
                                        counter++;
                                    }
                                }
                            }
                        } else {
                            cout << "No Warriors added." << endl;
                        }

                        // Player Win
                        

                            // Get their Money:
                        int money = heroes[opponent].getMoney();
                        int money2 = heroes[playerHero].getMoney();
                        money = money + money2;
                        heroes[playerHero].setMoney(money);

                            // Get their Influence:
                        int inf = heroes[opponent].getInfluence();
                        int inf2 = heroes[playerHero].getInfluence();
                        inf = inf + inf2;
                        heroes[playerHero].setInfluence(inf);

                            // Get their Army Size:
                        int arrS = heroes[opponent].getArmySize();
                        int arrS1 = heroes[playerHero].getArmySize();
                        arrS = arrS + arrS1;
                        heroes[playerHero].setArmySize(arrS);

                            // Get their tiles:
                        captureTiles(playerHero , opponent);

                            // setBattle:
                        retireHeroAt(opponent);
                        heroes[playerHero].setInBattle(false);
                    } else {
                        cout << heroes[opponent].getName() << " has bested you." << endl;
                        retireHeroAt(playerHero);
                        heroes[opponent].setInBattle(false);
                    }


                }
            }

        } else {
            int randomChance = rand() %10;
            if(randomChance == 1)
            {
                cout << heroes[index1].getName() << " has been bested by " << heroes[index2].getName() << endl;
                captureTiles(index1 , index2);
                retireHeroAt(index2);
            }
            if(randomChance == 2)
            {
                cout << heroes[index1].getName() << " has been bested by " << heroes[index2].getName() << endl;
                captureTiles(index2 , index1);
                retireHeroAt(index1);
            }
        }

    } else {
        //cout << "ERROR: No Encounter between" << heroes[index1].getName() << " and " << heroes[index2].getName() << " took place!" << endl;
    }
        
    
}
    // These three functions are part of the encounter option:
    double Game::giveASpeech(int index)
    {
        double probability; 

        string warr = heroes[index].getWarriorAt(0);
        //cout << heroes[index].getName() << " " << index << endl;
        int warriorIndex = 0;

        for(int i = 0; i < numWarriors; i++)
        {
            if(warr == warriors[i].getName())
            {
                //cout << i << endl;
                warriorIndex = i;
                break;
            }
        }

        probability= (1-(warriors[warriorIndex].getMorale()/ 100.0))*(heroes[playerHero].getInfluence()/1600.0); 

        return probability;
    }

    double Game::buyThem(int index)
    {
        double probabilitywin; 
        string warr = heroes[index].getWarriorAt(0);
        int warriorIndex = 0;

        for(int i = 0; i < numWarriors; i++)
        {
            if(warr == warriors[i].getName())
            {
                warriorIndex = i;
                break;
            }
        }

        probabilitywin= (1-(warriors[warriorIndex].getLoyalty() / 100.0))* (heroes[playerHero].getMoney()/17800.0);
        

        // we can copy and paste the winning and losing condition from speech as long as its right and change influence to money 
        return probabilitywin;
    }
    int Game::battle(int index)
    {
        int numWarriorsHero = 0;
        int numWarriorsOpponent = 0;

        // number of warriors for opponent:
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < numWarriors; j++)
            {
                if(heroes[index].getWarriorAt(i) == warriors[j].getName())
                {
                    numWarriorsOpponent++;
                }
            }
        }

        // number of warriors for player:
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < numWarriors; j++)
            {
                if(heroes[playerHero].getWarriorAt(i) == warriors[j].getName())
                {
                    numWarriorsHero++;
                }
            }
        }
        
        if(numWarriorsHero == 0 && numWarriorsOpponent == 0)
        {
            if(heroes[index].getArmySize() > heroes[playerHero].getArmySize())
            {
                return 0;
            } else {
                return 1;
            }
        } else if(numWarriorsOpponent > 0 && numWarriorsHero == 0){
            cout << "Hero can't win." << endl;
        }
        if(numWarriorsOpponent == 0 && numWarriorsHero > 0)
        {
            return 1;
        } else if(numWarriorsOpponent > 0 && numWarriorsHero > 0)
        {
            int chosenWarrior = 0;
            cout << "Which warrior shall you send to battle, my liege?" << endl;
            cout << "******** YOUR WARRIORS:" << endl;
            for(int i = 0; i < numWarriorsHero; i++)
            {       
                cout << i+1 << ": " << heroes[playerHero].getWarriorAt(i) << endl;
            }

            cin.ignore();
            cin >> chosenWarrior;

            chosenWarrior--;

            // Get the Chosen Warrior
            int chosenWarriorIndex = 0;
            for(int i = 0; i < numWarriors; i++)
            {
                if(heroes[playerHero].getWarriorAt(chosenWarrior) == warriors[i].getName())
                {
                    chosenWarriorIndex = i;
                }
            }

            int chosenOpponentWarrior = rand() % numWarriorsOpponent;
            string enemyWarrior = heroes[index].getWarriorAt(chosenOpponentWarrior);
            int enemyWarriorIndex = 0;

            for(int i = 0; i < numWarriors; i++)
            {
                if(heroes[playerHero].getWarriorAt(chosenWarrior) == warriors[i].getName())
                {
                    enemyWarriorIndex = i;
                }
            }

            int playerStrength = heroes[playerHero].getArmySize() * warriors[chosenWarriorIndex].getStrength();
            int opponentStrength = heroes[index].getArmySize() * warriors[enemyWarriorIndex].getStrength();
            cout << "Their Strength: " << opponentStrength << ", " << "Your Strength: " << playerStrength << endl;
            if(playerStrength > opponentStrength)
            {
                return 1;
            } else if(playerStrength < opponentStrength)
            {
                return 0;
            } else {
                return 1;
            }

        }
    
        return 0;
    }

        // Losing heroes capture the tiles of their enemies.
    void Game::captureTiles(int hero , int captured)
    {
        for(int i = 0; i < 25; i++)
        {
            for(int j = 0; j < 16; j++)
            {
                if(landControl[i][j] == captured)
                {
                    landControl[i][j] = hero;
                    if((getTileData(i,j) != 'p' || getTileData(i,j) != 'w') || getTileData(i,j) != '-')
                    {
                        for(int k = 0; k < numCities; k++)
                        {
                            if(getTileData(i,j) == cities[k].cityGetChar())
                            {
                                int moneyH = heroes[hero].getMoney();
                                int armyH = heroes[hero].getArmySize();
                                int pointsH = heroes[hero].getPoints();

                                int armyC = cities[k].cityGetArmySize();
                                int moneyC = cities[k].cityGetCapital();
                                int pointsC = cities[k].cityGetPoints();

                                moneyH = moneyH + moneyC;
                                armyH = armyH + armyC;
                                pointsH = pointsH + pointsC;

                                heroes[hero].setArmySize(armyH);
                                heroes[hero].setMoney(moneyH);
                                heroes[hero].setPoints(pointsH);
                            }
                        }
                    }
                }
            }
        }
    }

void Game::cityEncounter(int heroIndex)
{
    if(heroIndex == playerHero)
    {
        int x = heroes[playerHero].getLocationX();
        int y = heroes[playerHero].getLocationY();
        int presentCity = 0;
        bool isCity = false;
        for(int i = 0; i < numCities; i++)
        {
            if(getTileData(x,y) == cities[i].cityGetChar())
            {
                presentCity = i;
                isCity = true;
                break;
            }
        }

        char city = cities[presentCity].cityGetChar();

        if(isCity == true)
        {
            if(getLandControl(x,y) != playerHero)
            {
                
                bool choiceMenu1 = true;
                bool choiceMenu2 = true;

                while(choiceMenu1 == true)
                {
                    string yesNo = "";
                    cout << "You have arrived in " << cities[presentCity].cityGetName() << "." << endl;
                    cout << "Would you like to hear rumors? Y/N " << endl;

                    cin.ignore();
                    cin >> yesNo;

                    if(yesNo[0] == 'y' || yesNo[0] == 'Y')
                    {
                        int close = hearRumors(city);
                        int distance = abs(heroes[close].getLocationX() - heroes[playerHero].getLocationX()) + abs(heroes[close].getLocationY() - heroes[playerHero].getLocationY());
                        cout << heroes[close].getName() << " is only " << distance << " moves away from this city." << endl;
                        choiceMenu1 = false;
                    } else if(yesNo[0] == 'n' || yesNo[0] == 'N')
                    {
                        choiceMenu1 = false;
                    } else {
                        cout << "Invalid input, enter 'y' or 'Y' for yes and 'n' or 'N' for no." << endl;
                    }
                }

                while(choiceMenu2 == true)
                {
                    string yesNo2 = "";
                    cout << "Would you like to buy more knights? Y/N" << endl; 
                    cout << "(Cost: 20 Gold)" << endl;
                    cout << "(Current balance: " << heroes[playerHero].getMoney() << ")"<< endl;
                    cin >> yesNo2;

                    if(yesNo2[0] == 'y' || yesNo2[0] == 'Y')
                    {
                        if(heroes[playerHero].getMoney() <= 20)
                        {
                            cout << "Cannot purchase more KNIGHTS, insufficient GOLD." << endl;
                            cout << "Your current GOLD balance: " << heroes[playerHero].getMoney() << endl;
                            choiceMenu2 = false;
                        } else {
                            int troops = heroes[playerHero].getArmySize();
                            int newTroops = cities[presentCity].cityGetArmySize();

                            int money = heroes[playerHero].getMoney();
                            money = money - 20;

                            troops = troops + newTroops;

                            heroes[playerHero].setArmySize(troops);
                            heroes[playerHero].setMoney(money);
                            cout << "A wise purchase, your highness! May our forces serve you well." << endl;
                            cout << "Your ARMY SIZE is now " << heroes[playerHero].getArmySize() << endl;
                            choiceMenu2 = false;
                        }
                    } else if(yesNo2[0] == 'n' || yesNo2[0] == 'N')
                    {
                        choiceMenu2 = false;
                    } else {
                        cout << "Invalid input, enter 'y' or 'Y' for yes and 'n' or 'N' for no." << endl;
                    }
                }
                

            } else {
                if(cities[presentCity].cityGetChar() == 'A')
                {
                    cout << "We are back in " << cities[presentCity].cityGetName() << ", my liege." << endl;
                    cout << "One may even say that...... we are back in black." << endl; 
                } else {
                cout << "We are back in " << cities[presentCity].cityGetName() << ", my liege." << endl;
                }
            }
        } else {
            //cout << "We are not at a city yet." << endl;
        }
    } 
}

int Game::hearRumors(char city)
{
    int cityX = 0;
    int cityY = 0;

    for(int i = 0; i < 25; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            if(getTileData(j,i) == city)
            {
                cityX = i;
                cityY = j;
                break;
            }
        }
    }

    int minimum = 1000;
    int dist = 0;
    int closestHero = 0;

    // Find MINIMUM DISTANCE of all heroes from city throught the entire map.
    for(int i = 0; i < numHeroes; i++)
    {
        dist = abs(heroes[i].getLocationX() - cityX) + abs(heroes[i].getLocationY() - cityY);

        if(heroes[i].getDeath() == false)
        {
            if(dist < minimum && i != playerHero)
            {
                minimum = dist;
                closestHero = i;
            }
        }
    }

    return closestHero;

}
    
void Game::turnBasedEncounters()
{
    // this function will execute the functions below based on the number of turns that have occurred.
    int random = rand() % 24;
    if(random <= 3)
    {
        if(random == 0)
        {
            drought();
        }
        if(random == 1)
        {
            deserters();
        }
        if(random == 2)
        {
            jackpot();
        }
        if(random == 3)
        {
            kindness();
        }
    }

    if(numTurns % 10 == 0 && numTurns != 0)
    {
        jaime();
        arya();
        cout << "+************ Turn 10 **************+" << endl;
        dragonsFunction();
        cout << "+************************************" << endl;
        stannis();

    }

    if(heroes[playerHero].getDeath() == false && ((numTurns % 50 == 0 || heroes[playerHero].getArmySize() >= 2000) || (getHeroControlledLand(playerHero) > 200 || heroes[playerHero].getPoints() > 400)))
    {
        whiteWalkers();
    }
}
            bool Game::whiteWalkers()
            {
                // variable 'ww' is to verify if the walkers have been defeated.
                ww = false;
                bool walkerMenu = true;

                while(walkerMenu == true)
                {
                    string yesNoWalkers = "";
                    cout << "My liege, we have recieved word that the White Walkers are approaching the kingdom." << endl;
                    cout << "Shall we face the walkers? Y/N" << endl;

                    cin.ignore();
                    cin >> yesNoWalkers;

                    if(yesNoWalkers[0] == 'y' || yesNoWalkers[0] == 'Y')
                    {
                        
                        // White walkers battle:
                        int walkerBattle = 3;
                        int counter = 1;

                        while(walkerBattle > 0)
                        {

                            cout << "Round " << counter << endl;
                            int powerScore = heroes[playerHero].getArmySize();
                            int influenceScore = 0;
                            int warriorScore = 0;

                                int previous = 0;
                            //Calculate warrior score:
                                for(int i = 0; i < 4; i++)
                                {
                                    for(int j = 0; j < numWarriors; j++)
                                    {
                                        if(heroes[playerHero].getWarriorAt(i) == warriors[j].getName())
                                        {
                                            int warrStrength = warriors[j].getStrength();
                                            int warrMorale = warriors[j].getMorale();

                                            warriorScore = previous + warrStrength * (warrMorale / 50);
                                            previous = warriorScore;
                                            
                                        }
                                    }
                                }

                                cout << "Combined Warrior Strength: " << warriorScore << endl;
                                powerScore = powerScore + warriorScore;
                                
                            // Calculate influenceScore:
                                int cityNumber = 0;
                                for(int i = 0; i < 25; i++)
                                {
                                    for(int j = 0; j < 16; j++)
                                    {
                                        for(int k = 0; k < numCities; k++)
                                        {
                                            if(getTileData(i,j) == cities[k].cityGetChar() && landControl[i][j] == playerHero)
                                            {
                                                cityNumber++;
                                            }
                                        }
                                    }
                                }

                                influenceScore = (cityNumber + 1)*(heroes[playerHero].getInfluence() / 4);
                                powerScore = powerScore + influenceScore;

                            // See if hero has dragonglass:
                                bool dragonGlass = false;
                                for(int i = 0; i < 4; i++)
                                {
                                    for(int j = 0; j < numWarriors; j++)
                                    {
                                        if(heroes[playerHero].getWarriorAt(i) == warriors[j].getName())
                                        {
                                            if(warriors[j].getHasDragonglass() == true)
                                            {
                                                dragonGlass = true;
                                                break;
                                            }
                                            
                                        }
                                    }
                                }

                                if(dragonGlass == true)
                                {
                                    powerScore = powerScore + 10000;
                                }

                            // Le Final Calcul:
                                double probability = 1.0 - (1.0 / exp(powerScore / 30000.0));

                                cout << "Score: " << probability << endl;
                                if(probability >= 0.50)
                                {
                                    cout << "We have defeated the white walkers!" << endl;
                                    ww = true;
                                    walkerMenu = false;
                                    return true;
                                } else if(probability < 0.50)
                                {
                                    ww = false;
                                    walkerBattle--;
                                    if(walkerBattle <= 0)
                                    {
                                        cout << "WE LOST!" << endl;
                                        retireHeroAt(playerHero);
                                    }
                                    walkerMenu = false;
                                }
                                counter++;
                        }
                    } else if(yesNoWalkers[0] == 'n' || yesNoWalkers[0] == 'N')
                    {

                        if(imALittleB > 0)
                        {
                            imALittleB--;
                            cout << "We must face them eventually, my liege, before they take the kingdom!" << endl;
                            cout << "Note: You can avoid the walkers " << imALittleB << " more times." << endl;
                            walkerMenu = false;
                        } else if(imALittleB == 0)
                        {
                            cout << "---------------------------------------------------------------------------" << endl;
                            cout << "+                    The White Walkers Took Over Westeros                 +" << endl;

                            walkerMenu = false;
                        }

                    } else {
                        cout << "Invalid input, enter 'y' or 'Y' for yes and 'n' or 'N' for no." << endl;
                    }
                }
                    return false;
            }

            void Game::drought()
            {
                // see writeup.
                cout << "Calamity! A drought has swept across these lands!" << endl;
                cout << "Your warriors' morale and strength have decreased." << endl;
                for ( int j=0; j< 4; j++) // 4 warriors part of hero
                {
                    for (int i=0; i< numWarriors; i++) // all warriors in game
                    {
                        if (heroes[playerHero].getWarriorAt(j)== warriors[i].getName())
                        {
                            int morale = warriors[i].getMorale();
                            int strength = warriors[i].getStrength();

                            strength = strength -10;
                            morale= morale-10; 
                            warriors[i].setMorale(morale); 
                            warriors[i].setStrength(strength);
                        }
                    }
                }
            }
            void Game::deserters()
            {
                // see writeup
                cout << "Miserable! Some of our troops deserted us in the night!" << endl;
                cout << "Your ARMY SIZE and warriors' LOYALTY have decreased." << endl;
                int armySize= heroes[playerHero].getArmySize();
                armySize= armySize-10;
                heroes[playerHero].setArmySize(armySize);

                for ( int j=0; j< 4; j++) // 4 heroes part of hero
                {
                    for (int i=0; i< numWarriors; i++) // all warriors in game
                    {
                        if (heroes[playerHero].getWarriorAt(j)== warriors[i].getName())
                        {
                            int loyalty = warriors[i].getLoyalty();

                            loyalty = loyalty -10;
                            warriors[i].setLoyalty(loyalty);
                        }
                    }
    
                }
            }
            void Game::jackpot()
            {
                // see writeup.
                cout << "Great news! Our righteous campaign has gained the interest of nobility!" << endl;
                cout << "Your GOLD value has doubled." << endl;
                int money= heroes[playerHero].getMoney();
                money= money*2;
                heroes[playerHero].setMoney(money);
            }
            void Game::kindness()
            {
                // see writeup.
                cout << "Your Highness! From our hospitality to these refugees, they offer us their swords!" << endl;
                cout << "Your ARMY SIZE and warriors' LOYALTY have increased." << endl;
                int armySize= heroes[playerHero].getArmySize();
                armySize= armySize+10;
                heroes[playerHero].setArmySize(armySize);  

                for ( int j=0; j< 4; j++) // 4 heroes part of hero
                {
                    for (int i=0; i< numWarriors; i++) // all warriors in game
                    {
                        if (heroes[playerHero].getWarriorAt(j)== warriors[i].getName())
                        {
                            int loyalty = warriors[i].getLoyalty();

                            loyalty = loyalty +10;
                            warriors[i].setLoyalty(loyalty);
                        }
                    }
                }
            }
            void Game::dragonsFunction()
            {
                // see writeup.
                cout << "!!!!!!!!!!!!!!!!!!!!!! Terrifying news, my liege !!!!!!!!!!!!!!!!!!!!!!!" << endl;
                cout << "Word has swept around the world that Danaerys Targaryen now has DRAGONS." << endl;
                int armySize= heroes[5].getArmySize();
                int counter=0; 
                armySize= armySize+5000;
                heroes[5].setArmySize(armySize); 

                for(int s=0; s< 4; s++)
                {
                    int strength =180;
                    int loyalty=100;
                    int morale=80; 
                    dragons[s].setName("Dragon");
                    dragons[s].setStrength(strength);
                    dragons[s].setLoyalty(loyalty);
                    dragons[s].setMorale(morale);
                    dragons[s].setShip(true); 


                }
                

                for ( int j=0; j< 4; j++) // 4 heroes part of hero
                {
                    for (int i=0; i< numWarriors; i++) // all warriors in game
                    {
                        if (heroes[5].getWarriorAt(j)== warriors[i].getName())
                        {
                            counter++; 
                        }
                    }
                }
                    if(counter==4)
                    {
                        for ( int i=0; i<4 ; i++)
                        {
                            heroes[5].setWarriorAt(dragons[i], i);

                            int strength = dragons[i].getStrength(); 
                            int loyalty = dragons[i].getLoyalty(); 
                            int morale = dragons[i].getMorale(); 

                            strength = strength*.10 + strength;
                            loyalty = loyalty*.10 + loyalty; 
                            morale = morale*.10 + morale; 

                            dragons[i].setStrength(strength);
                            dragons[i].setLoyalty(loyalty);
                            dragons[i].setMorale(morale);

                            

                        }
                    }
                    else
                    {
                        for ( int i=0; i<4 ; i++)
                        {
                            heroes[5].setWarriorAt(dragons[i], i);
                        }
                    }
            }

            void Game::stannis()
            {
                // Check if stannis is already dead. If stannis is already dead nothing will happen.
                if(heroes[1].getDeath() == false)
                {    
                    // see writeup.
                    heroes[1].freeWarriors(); 
                    retireHeroAt(1); 
                    string stannis = ""; 

                    bool stannisMenu = true;

                    while(stannisMenu == true)
                    {

                        cout << "Press F to pay respects. (HINT: Do NOT enter 'f' or 'F')." << endl;
                        cin >> stannis;

                        if(stannis[0] == 'F' || stannis[0] == 'f')
                        {
                            cout << "You derserved to die, because you respected a dead meme." << endl;
                            retireHeroAt(playerHero); 
                            stannisMenu = false;
                        }
                        else
                        {
                            cout << "Dead memes are dumb, lol." << endl; 
                            stannisMenu = false;
                        }
                    }
                }
            }

            void Game::arya()
            {
                for(int i = 0; i<4; i++)
                {
                    if(warriors[9].getName() == heroes[playerHero].getWarriorAt(i))
                    {
                        cout << "The warrior Arya Stark has fled, my liege." << endl;
                        break;
                    }
                }

                heroes[3].setWarriorAt(warriors[9] , 3);
                
            }
            void Game::jaime()
            {
                // see writeup.
                for(int i = 0; i<4; i++)
                {
                    if(warriors[7].getName() == heroes[playerHero].getWarriorAt(i))
                    {
                        cout << "The warrior Jaime Lannister has fled, my liege." << endl;
                        break;
                    }
                }
                warriors[7].setFreedom(true);
            }
    
    // Travel
// ShowpLayerMap is working (:
void Game::showPlayerMap()
{
    if(heroes[playerHero].getDeath() == false)
    {
        int x = heroes[playerHero].getLocationX() + 4;
        int y = heroes[playerHero].getLocationY() + 4;

        //cout << "Player on DISPLAY MAP: " << "X: " << heroes[playerHero].getLocationX() + 4 << " Y: " << heroes[playerHero].getLocationY() + 4 << endl;
        //cout << "MAP Coordinates: " << "x = " << x << " y = " << x << endl;

        //gameMap.fillDisplayMap();

        gameMap.showDisplayMapAt(heroes[playerHero].getLocationX() + 4, heroes[playerHero].getLocationY() + 4);
    }
}

// Move heroes is working! (:
void Game::moveHeroes(int input, int index)
{ 
    // This function will serve to update the position x,y of the heroes every turn depending on their choices.
    // if the hero chooses to move to a tile that is water, and they do not have a ship, they will not be able to access the tile and awarning will pop up
    // saying "you do not have a ship." this occurrs if the hero and all warriors do not have ships.

    int X = heroes[index].getLocationX();
    int Y = heroes[index].getLocationY();

    if(heroes[index].getDeath() == false)
    {
        if(index == playerHero)
        {
            setLandControl(playerHero);
            if((X<0 || X>15) || (Y<0 || Y>24))
            {
                // This part is so that the player cannot leave the map lol >:)
                cout << "Where are you going? Our conquest is in WESTEROS! Not out there!" << endl; 
                if(X<0)
                {
                    heroes[index].setLocationX(X+1);
                }
                if(Y<0)
                {
                    heroes[index].setLocationY(Y+1);
                }
                if(Y>24)
                {
                    heroes[index].setLocationY(Y-1);
                }
                if(X>15)
                {
                    heroes[index].setLocationX(X-1);
                }
            } else {
                if((input < 1 || input > 4))
                {
                    cout << "invalid direction," << endl;
                }
                else
                {
                    if(input == 1)
                    {
                        Y = Y-1;
                        char move1 = getTileData(X,Y);
                        
                        if(move1 != 'w')
                        {
                            heroes[index].setLocationY(Y);
                        } else {

                            if(move1 == 'w' && heroes[index].getHasShip() == true)
                            {
                                heroes[index].setLocationY(Y);
                                cout << "We are now over water." << endl;
                            } else {
                                                
                                Y++;
                                cout << "You cannot tread water without a ship, my liege." << endl;
                                    
                            }
                        }
                    //cout << "Move: " << move1 << ", Coordinates: " << X << " " << Y << endl;
                        
                    }

                    if(input == 2)
                    {
                        Y = Y+1;
                        char move2 = getTileData(X,Y);

                        if(move2 != 'w')
                        {
                            heroes[index].setLocationY(Y);
                        } else {

                            if(move2 == 'w' && heroes[index].getHasShip() == true)
                            {
                                heroes[index].setLocationY(Y);
                                cout << "We are now over water." << endl;
                            } else {
                                                
                                Y--;
                                cout << "You cannot tread water without a ship, my liege." << endl;
                                    
                            }
                        }
                    //cout << "Move: " << move2 << ", Coordinates: " << X << " " << Y << endl;
                    
                    }

                    if(input == 3)
                    {
                        X = X-1;
                        char move3 = getTileData(X,Y);
                        cout << move3 << endl;
                        if(move3 != 'w')
                        {
                            heroes[index].setLocationX(X);
                        } else {

                            if(move3 == 'w' && heroes[index].getHasShip() == true)
                            {
                                heroes[index].setLocationX(X);
                                cout << "We are now over water." << endl;
                            } else {
                                                
                                X++;
                                cout << "You cannot tread water without a ship, my liege." << endl;
                                    
                            }
                        }
                    //cout << "Move: " << move3 << ", Coordinates: " << X << " " << Y << endl;
                    
                    }

                    if(input == 4)
                    {
                        X = X+1;
                        char move4 = getTileData(X,Y);
                        if(move4 != 'w')
                        {
                            heroes[index].setLocationX(X);
                        } else {

                            if(move4 == 'w' && heroes[index].getHasShip() == true)
                            {
                                heroes[index].setLocationX(X);

                                cout << "We are now over water." << endl;
                            } else {
                                                
                                X--;
                                cout << "You cannot tread water without a ship, my liege." << endl;
                                    
                            }
                        }
                    //cout << "Move: " << move4 << ", Coordinates: " << X << " " << Y << endl;
                    
                    }

                }
            }
        } else if(index != playerHero)
        {
            setLandControl(index);
            if((X<0 || X>15) || (Y<0 || Y>24))
            {
                // This part is so that the player cannot leave the map lol >:)
                //cout << "Where are you going? Our mission is in WESTEROS! Not out there!" << endl; 
                if(X<0)
                {
                    heroes[index].setLocationX(X+1);
                }
                if(Y<0)
                {
                    heroes[index].setLocationY(Y+1);
                }
                if(Y>24)
                {
                    heroes[index].setLocationY(Y-1);
                }
                if(X>15)
                {
                    heroes[index].setLocationX(X-1);
                }
            } else {
                if(input < 1 || input > 4)
                {
                    //cout << "invalid direction.." << endl;
                }
                else
                {
                    if(input == 1)
                    {
                        Y = Y-1;
                        char move1 = getTileData(X,Y);
                        
                        if(move1 != 'w')
                        {
                            heroes[index].setLocationY(Y);
                            
                        } else {

                            if(move1 == 'w' && heroes[index].getHasShip() == true)
                            {
                                heroes[index].setLocationY(Y);
                                //cout << "We are now over water." << endl;
                            } else {
                                                
                                Y++;
                                //cout << "You cannot tread water without a ship, my liege." << endl;
                                    
                            }
                        }
                    //cout << "Move: " << move1 << ", Coordinates: " << X << " " << Y << endl;
                        
                    }

                    if(input == 2)
                    {
                        Y = Y+1;
                        char move2 = getTileData(X,Y);

                        if(move2 != 'w')
                        {
                            heroes[index].setLocationY(Y);
                        } else {

                            if(move2 == 'w' && heroes[index].getHasShip() == true)
                            {
                                heroes[index].setLocationY(Y);
                                //cout << "We are now over water." << endl;
                            } else {
                                                
                                Y--;
                                //cout << "You cannot tread water without a ship, my liege." << endl;
                                    
                            }
                        }
                    //cout << "Move: " << move2 << ", Coordinates: " << X << " " << Y << endl;
                    
                    }

                    if(input == 3)
                    {
                        X = X-1;
                        char move3 = getTileData(X,Y);
                        //cout << move3 << endl;
                        if(move3 != 'w')
                        {
                            heroes[index].setLocationX(X);
                        } else {

                            if(move3 == 'w' && heroes[index].getHasShip() == true)
                            {
                                heroes[index].setLocationX(X);
                                //cout << "We are now over water." << endl;
                            } else {
                                                
                                X++;
                                //cout << "You cannot tread water without a ship, my liege." << endl;
                                    
                            }
                        }
                    //cout << "Move: " << move3 << ", Coordinates: " << X << " " << Y << endl;
                    
                    }

                    if(input == 4)
                    {
                        X = X+1;
                        char move4 = getTileData(X,Y);
                        if(move4 != 'w')
                        {
                            heroes[index].setLocationX(X);
                        } else {

                            if(move4 == 'w' && heroes[index].getHasShip() == true)
                            {
                                heroes[index].setLocationX(X);

                                //cout << "We are now over water." << endl;
                            } else {
                                                
                                X--;
                                //cout << "You cannot tread water without a ship, my liege." << endl;       
                            }
                        }
                    //cout << "Move: " << move4 << ", Coordinates: " << X << " " << Y << endl;
                    }
                }
            }
        }
    }
}

// This function moves ALL other heroes and their warriors randomly after the player has moved.
// moveNPCs is working! (:
void Game::moveNPCs()
{
    for(int i = 0; i < numHeroes; i++ )
    {
        int dir_ = rand() % 5;
        if( i != playerHero)
        {
            moveHeroes(dir_ , i);
            bindWarriors();
        }  
    }
}
// moveWarriors is working! (:
void Game::moveWarriors()
{
    // This function will only move warriors randomly if they are free, else the updated position
    // of the warrior will equal the hero's position.
    // The warriors that are free roaming will simply not be able to access water tiles if they do not have a ship by the use of a conditional.

    // ! WARNING ! Ugly code ahead.

    if(numWarriors > 0)
    {
        for(int i = 0; i < numWarriors; i++)
        {
            int X = warriors[i].getLocationX();
            int Y = warriors[i].getLocationY();

            if(warriors[i].getFreedom() == true)
            {
                int direction = rand() % 5;
                if((X<0 || X>15) || (Y<0 || Y>24))
            {   
            // This part is so that the player cannot leave the map lol >:)
            //cout << "Where are you going? Our mission is in WESTEROS! Not out there!" << endl; 
            if(X<0)
            {
                warriors[i].setX(X+1);
            }
            if(Y<0)
            {
                warriors[i].setY(Y+1);
            }
            if(Y>24)
            {
                warriors[i].setY(Y-1);
            }
            if(X>15)
            {
                warriors[i].setX(X-1);
            }
            } else {
            
                if(direction == 1)
                {
                    Y = Y-1;
                    char move1 = getTileData(Y,X);
                    
                    if(move1 != 'w')
                    {
                        warriors[i].setY(Y);
                    } else {

                        if(move1 == 'w' && warriors[i].getShip() == true)
                        {
                            warriors[i].setY(Y);
                            //cout << "We are now over water." << endl;
                        } else {
                                            
                            Y++;
                            //cout << "You cannot tread water without a ship, my liege." << endl;
                                
                        }
                    }
                //cout << "Move: " << move1 << ", Coordinates: " << X << " " << Y << endl;
                    
                }

                if(direction == 2)
                {
                    Y = Y+1;
                    char move2 = getTileData(Y,X);

                    if(move2 != 'w')
                    {
                        warriors[i].setY(Y);
                    } else {

                        if(move2 == 'w' && warriors[i].getShip() == true)
                        {
                            warriors[i].setY(Y);
                            //cout << "We are now over water." << endl;
                        } else {
                                            
                            Y--;
                            //cout << "You cannot tread water without a ship, my liege." << endl;
                                
                        }
                    }
                //cout << "Move: " << move2 << ", Coordinates: " << X << " " << Y << endl;
                
                }

                if(direction == 3)
                {
                    X = X-1;
                    char move3 = getTileData(Y,X);
                    //cout << move3 << endl;
                    if(move3 != 'w')
                    {
                        warriors[i].setX(X);
                    } else {

                        if(move3 == 'w' && warriors[i].getShip() == true)
                        {
                            warriors[i].setX(X);
                            //cout << "We are now over water." << endl;
                        } else {
                                            
                            X++;
                            //cout << "You cannot tread water without a ship, my liege." << endl;
                                
                        }
                    }
                //cout << "Move: " << move3 << ", Coordinates: " << X << " " << Y << endl;
                
                }

                if(direction == 4)
                {
                    X = X+1;
                    char move4 = getTileData(Y,X);
                    if(move4 != 'w')
                    {
                        warriors[i].setX(X);
                    } else {

                        if(move4 == 'w' && warriors[i].getShip() == true)
                        {
                            warriors[i].setX(X);

                            //cout << "We are now over water." << endl;
                        } else {
                                            
                            X--;
                            //cout << "You cannot tread water without a ship, my liege." << endl;
                                
                        }
                    }
                //cout << "Move: " << move4 << ", Coordinates: " << X << " " << Y << endl;
                
                }

            }
            }

        }
    }
}

    // Turn based system and KILLING HEROES:
int Game::turn()
{
    // this function will be every turn that the hero of the player, and the other heroes will use to make descisions,
    // this will have a counter within it in order to trigger in game events.

    int choice = 0;
    cout << "+-------------------------------------------+" << endl;
    cout << "My liege, what will you have your company do?" << endl;
    cout << "1: Travel" << endl;
    cout << "2: Rest  " << endl;
    cout << "3: Consult With The Gods " << endl;
    cout << "+-------------------------------------------+" << endl;

    cin >> choice;

    numTurns++;

    if(choice == 1)
    {
        return 1;
    }
    if(choice == 2)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < numWarriors; j++)
            {
                if(heroes[playerHero].getWarriorAt(i) == warriors[j].getName())
                {
                    int strong = warriors[j].getStrength();
                    strong++;
                    warriors[j].setStrength(strong);
                }
            }
        }
        cout << "Your warriors' stengths have increase from good rest." << endl;
        return 2;
    }
    if(choice == 3)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < numWarriors; j++)
            {
                if(heroes[playerHero].getWarriorAt(i) == warriors[j].getName())
                {
                    int morals = warriors[j].getMorale();
                    morals++;
                    warriors[j].setMorale(morals);
                }
            }
        }
        cout << "Your warriors' morale has increased from your faithful consultation." << endl;   
        return 3;
    }
    if(choice != 1 || (choice != 2 || choice != 3))
    {
        cout << "Invalid input, enter 1, 2, or 3." << endl;
        return -1;
    }

}

// This function kills the Heroes that are to die.
void Game::retireHeroAt(int index)
{
    if(index < 0 || index > numHeroes)
    {
        cout << "Invalid HERO index." << endl;
    } else {
        // When the player hero dies, the game also ends.
        if(index == playerHero)
        {
            cout << "---------------------------------------------------------------------------" << endl;
            cout << "'When you play the game of thrones, you win, or you die' - Cersei Lannister" << endl;
            cout << "---------------------------------------------------------------------------" << endl;
            cout << "                            Play again? Enter Y/N                          " << endl;
            cout << "---------------------------------------------------------------------------" << endl;
            deadNames = heroes[playerHero].getName();
            deadPoints = heroes[playerHero].getPoints();
            heroes[playerHero].setDeath(true);
        } else {
            cout << heroes[index].getName() << " has retired." << endl;
            numHeroes--;
        }
        //heroes[index].freeWarriors();
        heroes[index] = Hero();
        heroes[index].setDeath(true);
    }
}

    // end of game

void Game::writeScores(string playerName , string fileName)
{
    // this will write the high score and name of the user that defeats the white walkers to a text file with the stupid formatting that they want.

    ofstream fileHandle;
    fileHandle.open("userScoresGOT.txt");

    if(fileHandle.is_open())
    {

        string str = "";
        string strings[3];
        int length = 0;
        int lengthsArr[3];

        string hero;
        string points;
        
        if(heroes[playerHero].getDeath() == true)
        {
            hero = deadNames;
            points = to_string(deadPoints);
        } else {
            hero = heroes[playerHero].getName();
            points = to_string(heroes[playerHero].getPoints());
        }

        strings[0] = playerName;
        strings[1] = hero;
        strings[2] = points;

        // Find largest string length:
        int heroLength = hero.length();
        int pointsLength = points.length();
        int nameLength = playerName.length();

        lengthsArr[0] = heroLength;
        lengthsArr[1] = pointsLength;
        lengthsArr[2] = nameLength;
        
        int max = 1000;

        for(int i = 0; i < 3; i++)
        {
            if(lengthsArr[i] < max)
            {
                max = lengthsArr[i];
            }
        }

        // The longest string will decide what the margin is:
        length = max;
        length = length + 2;

        for(int j = 0; j < 3; j++)
        {
            for(int i = 0; i < length; i++)
            {
                if(strings[j].length() <= length)
                {
                    strings[j] = strings[j] + " ";
                }
            }
        }

        fileHandle << strings[0] + strings[1] + " " + strings[2];
        
        
        // make sure the player name has sufficient spaces:


        fileHandle.close();    
    } else {
        cout << "ERROR: Could not open file 'userScoresGOT.txt'" << endl;
    }

}