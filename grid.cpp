/*
* Dylan Hudson, May 2017
* Originally designed as a homework assignment for
* Professor Laney Strange's Comp 11; modified for simplicity
* and stability.
* Implementation for class Grid - a dynamic 2D array data
* structure. Getters/setters, and functions specialized for 2048
* game play.
*/

 #include <iostream>
 #include <time.h>
 #include <stdlib.h>

 #include "grid.h"

 using namespace std;



//default constructor
Grid::Grid()
{
    size = 0;
    grid = NULL;
}

//destructor
Grid::~Grid()
{
    for (int i = 0; i < size; ++i)
    {
        delete [] grid[i];
    }
    delete [] grid;
}

/* Name: allocate
* Parameters: one int, the size of the board
* Returns: nothing
* Function: requests memory on the heap for the playing board.
*/
void Grid::allocate(int input)
{
    size = input;
    grid = new int*[size];
    for (int i = 0; i < size; i++)
    {
        grid[i] = new int[size];
    }
}


/* Name: makeTile
* Parameters: none
* Returns: an int, the value of the new tile.
* Function: generate a new tile (90% chance 2, otherwise 4)
*/
int Grid::makeTile()
{
    srand(time(NULL));
    int prob = rand() % 10;

        if (prob < 8 )
        {
            return 2;
        }
        else
        {
            return 4;
        }
}


/* Name: placeTile
* Parameters: int, the tile value
* Returns: nothing
* Function: finds an empty square on the edge of the board and places the tile.
*/
void Grid::placeTile(int tile)
{
    int coin;
    bool placed = false;
    //tries to locate a random empty edge location until one of the placement
    // functions returns true.
    while (!placed)
    {
        coin = rand() % 2;
        if (coin == 1)
            {
              placed = placeRow(tile);
            }
        else
            {
              placed = placeCol(tile);
            }
    }
}


/* Name: placeRow
* Parameters: one int,  tile value
* Returns: boolean
* Function: find a random edge square and place a tile.
*/
bool Grid::placeRow(int tile)
{
    int row = rand() % (size - 1);
    int coin = rand() % 2;
    if (coin == 1)
        {
            if (grid[row][0] == 0)
                {
                    grid[row][0] = tile;
                    return true;
                }
        }
    else
        {
            if (grid[row][(size-1)] == 0)
                {
                    grid[row][(size-1)] = tile;
                    return true;
                }
        }
        return false;
}

/* Name: placeCol
* Parameters: one int, tile value
* Returns: boolean, true if successful
* Function: finds a random empty edge square to place a tile using col index.
*/
bool Grid::placeCol(int tile)
{
    int col = rand() % (size - 1);
    int coin = rand() % 2;
    if (coin == 1)
        {
            if (grid[0][col] == 0)
                {
                    grid[0][col] = tile;
                    return true;
                }
        }
    else
        {
            if (grid[(size - 1)][col] == 0)
                {
                    grid[(size-1)][col] = tile;
                    return true;
                }
        }
        return false;
}


/* Name: initialize
* Parameters: none
* Returns: nothing
* Function: sets all values in the game grid to 0 (empty squares).
*/
void Grid::initialize()
{
    //initialize all values to empty (0) - clears the board
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            grid[i][j] = 0;
        }
    }
    grid[size-1][0] = 2;
    grid[0][0] = 2;
}


/* Name: print
* Parameters: none
* Returns: nothing
* Function: prints the grid to the screen, formatting for integer sizes and
* printing "X" when a square is empty (0).
*/
void Grid::print()
{
    // nested 'for' loops iterate through the 2d array
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            // if the square is empty, outputs an X as placeholder
            if (grid[i][j] == 0 )
                {cout << 'X'; }
            else
                {cout << grid[i][j];}

            //formats the blank space according to the number of digits
            //to preserve alignment.
            if ( grid[i][j] < 10 )
                { cout << "     " ;}
            else if ( grid[i][j] < 100 && grid[i][j] > 9 )
                { cout << "    "; }
            else if ( grid[i][j] < 1000 && grid[i][j] > 99)
                { cout << "   "; }
            else if ( grid[i][j] < 10000 && grid[i][j] > 999)
                { cout << "  "; }
            else
                { cout << " "; }
        }
    // creates a blank line after each row.
    cout << "\n" "\n";
    }
}

/* Name: read
* Parameters: 2 ints, grid coordinates
* Returns: int, the value of the array at the parameter coordinates
* Function: returns the array value requested.
*/
int Grid::read(int row, int col)
{
    return grid[row][col];
}

/* Name: writeElement
* Parameters: 3 ints, grid coordinates and the number to write at the loc.
* Returns: nothing
* Function: writes the desired number at the given array location.
*/
void Grid::writeElement(int num, int row, int col)
{
    grid[row][col] = num;
}

/* Name: getSize
* Parameters: none
* Returns: int, the value of data member 'size'
* Function: returns the value 'size'
*/
int Grid::getSize()
{
    return size;
}
