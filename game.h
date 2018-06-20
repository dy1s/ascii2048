/*  Dylan Hudson, May 2017
*
* 
* Header File for class GAME
*/

 #include <iostream>
 #include <string>
 #include <fstream>
 #include <time.h>

 #include "grid.h"

 using namespace std;

#ifndef GAME_H_
#define GAME_H_

class Game {
    private:
        //running total of game score
        int score;

        //4x4 playing grid object (2d dynamic int array)
        Grid board;

        //pointers for dynamic score arrays
        string* user_array;
        int* score_array;

        //high score filename
        //string SCORE_FILE;

        //number of scores in high score file
        //int filecount;

        //board size
        int boardsize;


    public:
        //default constructor
        Game();

        //destructor
        ~Game();

        //sets the score attribute.
        void setScore(int);
        //gets the current score
        int getScore();

        //clear board and add default starting tiles.
        void initializeBoard(int);
        //adds a new tile to the board.
        void addTile();

        //prints game board
        void printBoard();

        //returns true if game is over.
        bool gameOver();

        //moves the values on the game board left, updates the board
        void moveLeft();
        //moves the values on the game board right, updates the board
        void moveRight();
        //moves the values on the game board up, updates the board
        void moveUp();
        //moves the values on the game board down, updates the board
        void moveDown();

        //sums like values and moves them up
        void sumUp();
        //sums like values and moves them down
        void sumDown();
        //sums like values and moves them right
        void sumRight();
        //sums like values and moves them left
        void sumLeft();

        // NOTE File I/O disabled for basic gameplay -
        // uncomment private attributes as well as below functions if
        // desired.

        // prints the 5 most recent high scores to the screen
    //    void checkScores();
        //reads high score file in to a dynamic arrays and counts entries.
    //    void fileCount();
        //reads high score file in to a dynamic arrays
    //    void fileRead(string username, int score);
        //sorts high score data
    //    void sort(string user_array[], int score_array[]);
        //writes array of scores to high score file
    //    void fileWrite(string user_array[], int score_array[]);



};


#endif
