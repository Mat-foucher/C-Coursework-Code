// Project 3 - Main Driver
// This Project: Mathieu Foucher, Group Partner: Sabrina Kurevija.
// CSCI 1300 Spring 2020
// Recitation 301 - Telly Umada


#include <iostream>
#include "Game.h"

// NOTE 1: Do not use dot functions on dot functions! (Example of what not to do: gameOfThrones.getHeroAt(0).getWarriorAt(0);).

using namespace std;

// MAP is read first.
// CITIES are read second.
// WARRIORS are read third.
// HEROES (mfkz) are read fourth.

int main()
{
    Game gameOfThrones;

    bool gameIndex = true;
    int p = 0;
    
    string yesNoStart = "";
    string playerName = "";


    while(gameIndex == true)
    {
        // These nine commands should always be initialized first, and IN THIS ORDER!
            

            gameOfThrones.readMap("mapGOT.txt");

            gameOfThrones.readCities("citiesGOT.txt");

            gameOfThrones.readWarriors("warriorsGOT.txt");

            gameOfThrones.readHeroes("heroesGOT.txt");

            gameOfThrones.fillGameDisplayMap();

            // Dragonglass setup:
                gameOfThrones.fillDragonglassMap();


            // Warrior Placement:
                gameOfThrones.bindWarriors();

                gameOfThrones.scatterWarriors();

            // Land Control Initialization:
                gameOfThrones.initializeLandControl();


        // Helpers: (DO NOT UN-COMMENT)
            //gameOfThrones.printAllHeroes();

            //gameOfThrones.showWarriorCoordinates();

            //gameOfThrones.printAllWarriors();

            //gameOfThrones.printAllCities();

            //gameOfThrones.dragonglassCoordinates();

        
        // Debugging Hero and debugging Warrior:
            
            /*
            Hero mat;
            Warrior sam;

            mat.setName("Mat");
            mat.setLocationX(2);
            mat.setLocationY(1);
            mat.setInfluence(600);
            mat.setArmySize(1000);
            mat.setDeath(false);
            mat.setWarriorAt(sam, 0);
            mat.setWarriorAt(gameOfThrones.getWarriorAt(1) , 0);
            mat.setShip(true);
            
            gameOfThrones.setNewHero(mat);
            */
        
        

        cout << "+=-=-=-=-=-=--=-=-=-=-=-=+" << endl;
        cout << "WELCOME TO GAME OF THRONES" << endl;
        cout << "+=-=-=-=-=-=--=-=-=-=-=-=+" << endl;
        cout << "State your name, your grace: " << endl;

        cin >> playerName;

        

        bool startIndex = true;
        gameOfThrones.setTurns(0);

        cout << "Would you like to choose a hero, " << playerName << "? Y/N" << endl;

        cin >> yesNoStart;

        while(startIndex == true)
        {
            if(yesNoStart[0] == 'y' || yesNoStart[0] == 'Y')
            {

                cout << "Select Hero:" << endl;
                for(int i = 0; i < gameOfThrones.getNumHeroes(); i++)
                {
                    cout << i+1 << ": " << gameOfThrones.getHeroAt(i).getName() << endl; 
                }

                cin.ignore();
                cin >> p;
                p--;

                if(p < 0 || p > 6)
                {
                    cout << "Please select a valid option!" << endl;
                } else if(0<=p && p<7){
                    gameOfThrones.setPlayerHero(p);
                    startIndex = false;
                }

            } else if(yesNoStart[0] == 'n' || yesNoStart[0] == 'N')
            {
                cout << "Create a Hero, " << playerName << "." << endl;

                string yesNoShip = "";

                string heroName = "";
                int startingMoney = 250;
                int startingInfluence = 250;
                int startingArmySize = 150;
                bool ship_ = false;
                int x = 3;
                int y = 21;

                cout << "Enter Hero Name: " << endl;

                cin.ignore();
                cin >> heroName;

                bool shipIndex = true;

                while(shipIndex == true)
                {
                    cout << "Would you like to have a ship in your adventure? Y/N" << endl;
                    
                    cin.ignore();
                    cin >> yesNoShip;
                    // Deciding if the player wants a ship.
                        if(yesNoShip[0] == 'y' || yesNoShip[0] == 'Y')
                        {

                            ship_ = true;
                            x = 10;
                            y = 3;
                            shipIndex = false;
                        } else if(yesNoShip[0] == 'n' || yesNoShip[0] == 'N')
                        {
                            ship_ = false;
                            x = 4;
                            y = 21;
                            shipIndex = false;
                        } else {
                            cout << "Invalid input, enter 'y' or 'Y' for yes and 'n' or 'N' for no." << endl;
                        }
                }
                    
                // Setting up the hero, with NO WARRIORS:
                Hero newHero;
                newHero.setName(heroName);
                newHero.setMoney(startingMoney);
                newHero.setInfluence(startingInfluence);
                newHero.setArmySize(startingArmySize);
                newHero.setShip(ship_);
                newHero.setLocationX(x);
                newHero.setLocationY(y);
                newHero.setDeath(false);
                // Putting new hero in the game:
                gameOfThrones.setNewHero(newHero);
                gameOfThrones.setPlayerHero(6);

                startIndex = false;
            } else {
                cout << "Invalid input, enter 'y' or 'Y' for yes and 'n' or 'N' for no." << endl;
            }
        }


        bool game = true;
        //cout << "Hell yeah brother" << endl;
        while(game == true)
        {
            if(gameOfThrones.getWW() == false)
            {
                if(gameOfThrones.heroDA() == false)
                {
                    gameOfThrones.updateAllHeroPoints();

                        cout << "+=== Map ===+" << endl;
                        gameOfThrones.showPlayerMap();
                        cout << "+===========+" << endl;
                        cout << "+=== Info ===+ " << endl;
                        cout << "- Controlled Tiles: " << gameOfThrones.getHeroControlledLand(p) << endl;
                        cout << "- Current # of Turns: " << gameOfThrones.getTurns() << endl;

                    if(gameOfThrones.turn() == 1)
                    {
                        int dir = 0;

                        

                        //gameOfThrones.showWarriorCoordinates();
                        cout << "+=== Map ===+" << endl;
                        gameOfThrones.showPlayerMap();
                        cout << "+===========+" << endl;
                        cout << "+=== Info ===+ " << endl;
                        cout << "- Controlled Tiles: " << gameOfThrones.getHeroControlledLand(p) << endl;
                        cout << "- Current # of Turns: " << gameOfThrones.getTurns() << endl;
                        gameOfThrones.cityEncounter(gameOfThrones.getPlayerHeroIndex());
                        //gameOfThrones.printAllHeroes();

                        
                        for(int i = 0; i < gameOfThrones.getNumHeroes(); i++)
                        {
                            gameOfThrones.pickUpDragonglass(i);
                        }
                        for(int i = 0; i < gameOfThrones.getNumWarriors(); i++)
                        {
                            gameOfThrones.warriorPickUpDG(i);
                        }
                        cout << "+==========================================================+" << endl;
                        cout << "Choose a direction: 1 (up) , 2 (down) , 3 (left) , 4 (right)" << endl;
                        cout << "Enter 5 to quit." << endl;
                        cout << "+==========================================================+" << endl;
                        cin >> dir;
                        
                        if(dir != 5)
                        {
                            gameOfThrones.moveHeroes(dir , gameOfThrones.getPlayerHeroIndex());
                            cout << "New Location:" << endl;
                            cout << "+=== Map ===+" << endl;
                            gameOfThrones.showPlayerMap();
                            cout << "+===========+" << endl;
                            
                            gameOfThrones.turnBasedEncounters();
                            
                            gameOfThrones.moveNPCs();
                            gameOfThrones.moveWarriors();

                            // Encounter(s):
                            for(int i = 0; i < gameOfThrones.getNumHeroes(); i++)
                            {
                                int a = gameOfThrones.heroHitbox(i);
                                gameOfThrones.heroEncounter(i,a);
                            }
                        } else {
                            game = false;
                            gameIndex = false;
                            gameOfThrones.printAllHeroes();
                            
                        }
                        
                    } 
                    
                    
                        

                        
                            
                            

                            
                    // Player Death    
                } else {

                    bool deathMenu = true;

                    string yesNoDeath = "";
                    game = false;
                        //cout << "You Died" << endl;
                    while(deathMenu == true)
                    {
                        cin.ignore();
                        cin >> yesNoDeath;

                        if(yesNoDeath[0] == 'y' || yesNoDeath[0] == 'Y')
                        {
                            deathMenu = false;
                            game = false;
                            gameIndex = true;

                        } else if(yesNoDeath[0] == 'n' || yesNoDeath[0] == 'N')
                        {
                            deathMenu = false;
                            game = false;
                            gameIndex = false;
                        } else {
                            cout << "Invalid input, enter 'y' or 'Y' for yes and 'n' or 'N' for no." << endl;
                        }
                    }   
                }
            } else {
                cout << "+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+" << endl;
                cout << "With the white walkers defeated, WESTEROS is yours!" << endl;
                cout << "+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+" << endl;
                cout << "+=                   THE END                     =+" << endl;
                cout << "+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+" << endl;
                game = false;
                gameIndex = false;
            }

        }
    }

    gameOfThrones.writeScores(playerName , "userScoresGOT.txt");
    /*
    // How to MOVE HEROES:
    
    int in = 0;
    
    cout << "Choose direction: 1 (up) , 2 (down) , 3 (left) , 4 (right)" << endl;

    cin >> in;

    gameOfThrones.moveHeroes(in , 2);

    Hero jon1 = gameOfThrones.getHeroAt(2);

    cout << "New Position: X = " << jon1.getLocationX() << " Y = " << jon1.getLocationY() << endl;
    */
    
    return 0;
}


/* 
    cout "Welcome to the G A M E of T H R O N E S!"
    cout "State your name, Your Grace: " 
    cin << username 
    cout Would you like to choose a hero username, Your Grace?
    if (Y)
        {
        cout 
            Please choose from the following heroes:
            1. Cersei Lannister
            2. Stannis Baratheon
            3. Jon Snow
            4. Sansa Stark
            5. Euron Greyjoy
            6. Daenerys Targaryen
            cin >> 1,2,3,4,5,6
            
        }
        
        else if (N)
        {
            make your own character
            cout Your Grace username, you have chosen to go on this journey alone.
            Please provide starting values for your adventure.
            
            cout "choose starting values for money, influence, army, starting location" 
            if ( between 0 and 10000)
            {
                starting values for money, influence and army size can be between 0 and 10000
            }
                if ( location  row value (1-25) and a valid column value (1-16))
                {
                    cout location 
                }
                    if ( water location) 
                    {
                        ability to move on water 
                    }
                        if (warrior location is same)
                        {   The location cannot be the same as one of the other 6 heroes or as one of the
                            already-initialized warriors.
                        }
        }
        
    // call getplayercoordinates function to get selected players coordinates
    //call map function / cout map to show 7x7 area location
 
    * use void function for turning we can use switch or if else but the user has 3 choices when turning 
    if ( travel) If a hero chooses to travel, then they may not stay in the same location
    // the points earned here are for the warriors in warrior class 
    {
        cout <<  pick a travel direction: North, South, East or West 
        
        if (water tile)  
        { // read hero file 
            if ( hero file says hero can choose water)
            {
                travel 
            }
            else if (hero cannot choose water)
            {
                cout choose again
            }
        } 
        
            if (position of travel is not on map boundary)
            {
                 ask the user to choose again.
            }
        
        if (rest)
        {
            location is unchanged 
            points for strength +1 // call warrior points function 
        }
        
        if ( consult with gods)
        {
            location unchanged
            morale points +1 // call warrior points function 
        }
        
    }
    
    call get playercoordinates function/  mapcoordinates function  to randomly move other hero/ warriors one tile 
    
    “A Lannister Always Pays His Debts.” -this is the part in the write up 
    
    call get playercoordinates function 
    if (distansce less than 2 between heroes)
    {
       cout three options 
        1. speech
        2. buy them 
        3. battle 
        
        switch (1)
        {
            call playerpoints function / player class  to get values for players influence 
            compute influence to determine if win or loss 
            (1 − 100 opposing hero′s 1st warrior morale) * 1600 main hero′s influence
            if (main hero wins)
            {
                cout loser has retired 
                call map function to update that the winner has control of loser territory on map 
            }
                if (main hero looses)
                {
                    call player points function , hero looses 1/2 influence 
                    encounter ends 
                    hero escapes 
                }
        }
        
        switch (2)
        {
            call player class function to read to see values for loyality and money 
            use function to determine if can be bought 
            (1 − 100 opposing hero′s 1st warrior loyalty) * 17800 main hero′s money
            if (main hero wins)
            {
                cout loser has retired 
                call map function to update that the winner has control of loser territory on map 
            }
                if (main hero looses)
                {
                    call player points function , hero looses 1/2 money 
                    encounter ends 
                    hero escapes 
                }
        }
        
        switch(3)
        {
            call player class to read file and see values for strength and army size 
            highest value for (army size) * (strength of chosen warrior) wins the encounter
            if (main hero wins)
            {
                cout loser has retired 
                call map function to update that the winner has control of loser territory on map 
            }
                if (main hero looses)
                {
                    game ends  
                }
        }
    }
    
    “Valar Morghulis.” - this is part of the write up 
    if (hero distance is less than 2 from warrior)
    {
        if (hero already has 4 warriors)
        {
            roam free to find hero 
        }
        
            if (two heros have same proximity to warrior )
            {
                no one aquires warrior 
            }
            
                if(warrior aquired)
                {
                    call player points to increase morale by 10 
                }
                    
    } 
    
        if (hero disance is less than 2 from hero) // we can maybe change this to a for loop for distance less than 2 
        {
            if( both heroes have no warriors)
            {
                read file for player points function to determine largest army
                the hero with the largest army wins
            }
                if ( same size army)
                {
                    call player points function to lose half of army 
                    both heroes remain on the board at their respective
                    locations
                    lose half their army (rounding final army size down if the
                    original army size was odd)
                }
                    if ( both heroes have no warriors and no army)
                    {
                        call map functiom to update map 
                        both heroes retire 
                    }
                    
                        if (one hero has warrior other doesnt)
                        {
                            call player class to see which player doesnt have a warrior 
                            one with no warrior looses 
                        }
                            if (either of the heroes has more than one warrior)
                            {
                                call warrior function to choose warrior for battle
                                compute (army size) * (strength of chosen warrior)
                                hero with greatest wins encounter 
                            }
                            if (chosen hero wins )
                            {
                                cout other hero has retired 
                                gets other heros warriors up to a max of 4, thus filling warrior array for that hero 
                                calls warrior file to aquire points for fallen heros warriors and adds them in the playerpoints function 
                            }
                            
        }
 A Mind Needs Books As A Sword Needs A Whetstone, If It Is To Keep Its
Edge.” - this part of the write up 
*/
    
    