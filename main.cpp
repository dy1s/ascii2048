/*
* Terminal-based clone of popular app  "2048"
* Dylan Hudson, May 2017
* Originally designed as a homework assignment for
* Professor Laney Strange's Comp 11; modified for simplicity
* and stability.
* Gameplay Driver
*
* Although the board is preset to 4 x 4 for the classic
* 2048 experience, the size can be modified by changing the value
* of int 'size' below; the supporting data structures and algorithms
* will be entirely functional. 
*
*/

#include <iostream>
#include <string>

#include "grid.h"
#include "game.h"

using namespace std;

void parseInput(char input);

int main()
{
    Game game;
    string name;
    int size = 4;
    char input = '0';
    cout << "Welcome to 2048." << endl;
    game.initializeBoard(size);
    game.printBoard();

    cout << "Choose a direction to move using w, a, s, d (as arrow keys)" ;
    cout << " or q to quit" << endl;
    //player takes turns until while loop is broken, indicating the game is over
    while ( input != 'q' )
    {
        //control statements for player input
        cin >> input;
        if ( input == 'q') { break; }
        if ( input == 'a' ){game.moveLeft(); game.sumLeft(); game.moveLeft();}
        if ( input == 'w' ){game.moveUp(); game.sumUp(); game.moveUp();}
        if ( input == 's' ){game.moveDown(); game.sumDown(); game.moveDown();}
        if ( input == 'd' ){game.moveRight(); game.sumRight(); game.moveRight();}

        //after each move, generates a new tile and prints the updated board.
        game.addTile();
        game.printBoard();

        if ( game.gameOver() == true ) {break;}

        cout << "Score: " << game.getScore() << endl << "Next move? ..." ;
    }

    cout << "Game over. Score: " << game.getScore() << endl;
    return 0;
}
