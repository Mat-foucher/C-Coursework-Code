#include <iostream>
#include "Map.h"

Map::Map()
{
    boardHeight = 0;
    boardWidth = 0;
    
}

Map::Map(int boardHeight_ , int boardWidth_)
{
    boardHeight = boardHeight_;
    boardWidth = boardWidth_;
}

// Setters:

void Map::setMapSizeVertical(int vert_)
{
    boardHeight = vert_;
}
void Map::setMapSizeHorizontal(int horiz_)
{
    boardWidth = horiz_;
}
void Map::setDragonglass(int x , int y , bool tf)
{
    dragonGlass[x][y] = tf;
}

// Getters:

char Map::getTile(int x, int y)
{
    return board[x][y];
}

int Map::getBoardHeight()
{
    return boardHeight;
}

int Map::getBoardWidth()
{
    return boardWidth;
}

bool Map::getDragonglass(int x , int y)
{
    return dragonGlass[y][x];
}


// complicated:
    // All DRAGONGLASS Placement is working (:
void Map::placeDragonglass()
{
    // This function will scatter dragonglass randomly five times on the game map, there will be approriate validation to ensure that
    // the dragonglass is not placed where there already is dragonglass.
    int dgNumber = 5;
    
    while(dgNumber > 0)
    {
        int x = rand() % 16;
        int y = rand() % 25;

        if(dragonGlass[y][x] == false)
        {
            dragonGlass[y][x] = true;
            dgNumber--;
        }
    }  
}

// shows all of the dragonglass coordinates.
void Map::dragonGlassCoordinates()
{
    cout << "Dragonglass Locations: " << endl;
    for(int i = 0; i< 25; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            if(dragonGlass[i][j] == true)
            {
                cout << " -: " << "X = " << j << ", Y = " << i << endl;
            }
        }
    }
}

// DisplayMAP is working (:
void Map::fillDisplayMap()
{
    // fillDisplayMap will fill the map that will be used to show the player where they are each turn, this will have thet contents of the
    // "board" which is a 2d array that will store characters from the file for the map, but th edisplay map will have a border of
    // empty charcters to stop the possibility of the players breaking the game by forcing the showPlayerMap function to print things that do not exist.

    for(int i = 0; i < 33; i++)
    {
        for(int j = 0; j< 24; j++)
        {
            if((j<4 || j>=20) || (i < 4 || i>=29))
            {
                displayMap[i][j] = '-';
            } else {
                displayMap[i][j] = board[i-4][j-4];
            }
        }
    }
}

void Map::printDisplayMap()
{
    
    for(int i = 0; i < 33; i++)
    {
        for(int j = 0; j < 24; j++)
        {
            cout << displayMap[i][j] << " ";
        }
        cout << endl;
    }
}


void Map::showDisplayMapAt(int x , int y)
{

    if((x<4 && x>20) && (y< 4 && y>29))
    {
        cout << "Invalid coordinates entered. Please enter 0 < x < 16 and 0 < y < 24." << endl;
    } else {
        int y_ = y-3;
        int x_ = x-3;
        for(int i = y_; i < y+4; i++)
        {
            for(int j = x_; j < x+4; j++)
            {
                cout << displayMap[i][j] << " ";
            }
            cout << endl;
        }
        //cout << "Center: " << displayMap[y][x] << " Coordinates: " << "X = " << x-4 << ", Y = " << y-4 << endl;
    }
}

// Fillboard row has a problem where it was using the private variable boardWidth from the MAP class,
// this problem is fixed by setting the board width to 16, however it should bbe made to work with the private variables.
void Map::fillBoardRow(int rowNumber, string rowContents, char separator)
{

    int counter = 0;
    for(int i =0; i < rowContents.length() ; i++)
    {
        if(rowContents[i] != separator)
        {
            board[rowNumber][counter] = rowContents[i];
            counter++;
        }
        
    }
    
    
}