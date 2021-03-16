
#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>

using namespace std;

// The map is comprised of 400 tiles. 25 rows && 16 columns.
// 238 water tiles.
// 136 land tiles - 5 random tiles hold dragonglass.
// 26 city tiles - marked with capital letters A thru Z and each has unique properties.

// The map will be its own object, since we will be required to have the map respond to heroes,
// the map will also have to at times show a small part of itself for the players.

class Map{
    private:
        // We make the game board by finding a file with the data for the board,
        // and then we populate the board string array with the contents of the text file.
        char board[25][16];
        // The dragon glass array will be exactly like the map, but will only store the positions of dragonglass.
        bool dragonGlass[25][16];
        
        // the display map will simply be 4-larger than the main map in every direction, the display map will have
        // the main map in the middle of a ""frame"" of empty characters so that if the player goes to the edge
        // of the map they will only see blank spaces they can't even move to.
        char displayMap[33][24];
        int boardHeight;
        int boardWidth;
        
    public:
        Map();
        Map(int boardHeight_ , int boardWidth_);

        // Setters:
        void setMapSizeVertical(int vert_);
        void setMapSizeHorizontal(int horiz_);
        void setDragonglass(int x , int y , bool tf);

        // getters:
        char getTile(int x , int y);
        int getBoardWidth();
        int getBoardHeight();
        bool getDragonglass(int x , int y);

        // some complex functions
        void showDisplayMapAt(int x , int y);
        void fillDisplayMap();
        void printDisplayMap();
        void fillBoardRow(int rowNumber , string rowContents, char separator);



        // To help make the game
        
        


        // Additional functions to be added.
        void placeDragonglass();
        void dragonGlassCoordinates();
        
        

};

#endif