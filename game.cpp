/* 2048  - class Game Implementation
 * Dylan Hudson, May 2017
 *
 * class Game provides methods for interacting with the player and modifying the 
 * the game data during play. 
 *
 */

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>

#include "grid.h"
#include "game.h"

using namespace std;

//constructor
Game::Game()
{
    score = 0;
    boardsize = 0;
    // SCORE_FILE = "highscores.txt";
}

//destructor
Game::~Game()
{

}

 /* Name: initializeBoard
 * Parameters: one integer representing the size of the square game board
 * Returns: nothing
 * Function: call the necessary member functions from class Grid and set member
 */
void Game::initializeBoard(int size)
{
    board.allocate(size);
    board.initialize();
    boardsize = size;
}

/* Name: addTile
* Parameters: none
* Returns: nothing
* Function: calls functions to add a new tile to the game board
*/
void Game::addTile()
{
    board.placeTile(board.makeTile());
}

/* Name: printBoard
* Parameters: none
* Returns: nothing
* Function: displays the board on the screen
*/
void Game::printBoard()
{
    board.print();
}

/* Name: getScore
* Parameters: none
* Returns: the current game's score as an integer
* Function: provide access to the score.
*/
int Game::getScore()
{
    return score;
}

/* Name: fileCount NOTE - not needed for basic gameplay, uncomment if desired.
* Parameters: none
* Returns: nothing
* Function: sets the data member fileCount to represent the number of scores
* in the high score file.
*
void Game::fileCount()
{
    string tempname;
    int tempscore;
    filecount = 0;
    ifstream infile;
    infile.open(SCORE_FILE.c_str());
        if ( !infile.is_open()) {
            cerr << " no scores yet" << endl;
        }
        else {
             //count number of entries in file line by line.
             while (!infile.eof())
                {
                    infile >> tempname;
                    if (tempname != "-1")
                        {
                            infile >> tempscore;
                            filecount++;
                        }
                }
            //final increment to take current user into account.
            filecount++;
            }
    infile.close();
}
*/

/* Name: fileRead NOTE - not needed for basic gameplay, uncomment if desired.
* Parameters: one string, the current player name,  one int, the current score
* Returns: nothing
* Function: opens the highscore file, reads each string and int into separate
* arrays, then passes the arrays to sort(), then to fileWrite which writes the
* the sorted arrays back to the file, then deletes the arrays.
*
void Game::fileRead(string username, int score)
{
    string tempname;
    int tempscore;
    //allocate dynamic arrays as data buffers for sorting and access.
    string * user_array = new string[filecount];
    int * score_array = new int[filecount];
    //add current user to arrays for score and username
    user_array[0] = username;
    score_array[0] = score;
    //
    ifstream infile;
    infile.open(SCORE_FILE.c_str());
    if ( !infile.is_open()) {
        cerr << " no scores yet" << endl;
    }
    else {
        //index value to increment for filling the arrays from the file
         int i = 1;
         //read each value from the file and save in respective arrays
         while (!infile.eof()) {
                infile >> tempname;
                    if (tempname != "-1") {
                        user_array[i] = tempname;
                        infile >> tempscore;
                        score_array[i] = tempscore;
                        i++;
                    }
                    else { break;}
            }
    }
    infile.close();
    //sort the scores and write the updated list to the file.
    sort(user_array, score_array);
    fileWrite(user_array, score_array);
    //free heap memory
    delete [] user_array;
    delete [] score_array;
}
*/
/* Name: sort NOTE - not needed for basic gameplay, uncomment if desired.
* Parameters: 2 arrays, one strings, one ints.
* Returns: nothing
* Function: Uses bubblesort to sort an array of ints from largest to smallest,
* while maintaining the corresponding order in the string array.
*
void Game::sort(string user_array[], int score_array[])
{
int tempInt;
string tempString;
for (int i = 0; i < (filecount - 1); i++)
    {
    for (int j = 0; j < (filecount - i - 1); j++)
        {
        //as the scores are sorted, their associated username is moved to
        //maintain the correct order across both arrays.
        if (score_array[j] < score_array[j+1])
            {

                tempInt = score_array[j];
                tempString = user_array[j];
                score_array[j] = score_array[j+1];
                user_array[j] = user_array[j+1];
                score_array[j+1] = tempInt;
                user_array[j+1] = tempString;
            }
        }
    }
}
*/

/* Name: fileWrite NOTE - not needed for basic gameplay, uncomment if desired.
* Parameters: 2 arrays, one strings, one ints.
* Returns: nothing
* Function: format and write the contents of 2 arrays to a file.
*
void Game::fileWrite(string user_array[], int score_array[])
{
    ofstream outfile;
    outfile.open(SCORE_FILE.c_str());

    if (!outfile.is_open())
        {
            cerr << "file did not open" << endl;
        }
    else
    {
        for (int i = 0; i < filecount ; i++)
            {
                outfile << user_array[i] << " " <<score_array[i] << "\n";
            }
        outfile << "-1" << "\n";
    }
    outfile.close();
}
*/

/* Name: moveLeft
* Parameters: none
* Returns: nothing
* Function: moves all numbers in the game as far to the left as possible
*/
void Game::moveLeft()
{
    //iterates once for each square to ensure all value are moved
    int count = 0;
    while ( count < boardsize )
    {

        for (int i = 0; i < boardsize; i++)
        {
            for (int j = 0; j < (boardsize-1); j++)
            {
                //if the square is empty, move the tile on the right over.
                if (board.read(i,j) == 0)
                {
                    int num = board.read(i, (j+1));
                    board.writeElement(num, i, j);
                    board.writeElement(0, i, (j+1));
                }
            }
        }
    count++;
    }
}

/* Name:moveUp
* Parameters:none
* Returns:nothing
* Function: moves all numbers on the board as far up as possible.
*/
void Game::moveUp()
{
    int count = 0;
    while ( count < boardsize )
    {
    for (int j = 0; j < boardsize; j++)
        {
            for (int i = 0; i < (boardsize-1); i++)
            {
                if (board.read(i,j) == 0)
                {
                    int num = board.read((i+1), j);
                    board.writeElement(num, i, j);
                    board.writeElement(0, (i+1),j) ;
                }
            }
        }
    count++;
    }
}

/* Name: moveDown
* Parameters: none
* Returns: nothing
* Function: moces all numbers on the board as far down as possible
*/
void Game::moveDown()
{
    int count = 0;
    while ( count < boardsize )
    {
    for (int j = 0; j < boardsize; j++)
        {
            for (int i = (boardsize -1); i > 0; i--)
            {
                if (board.read(i,j) == 0)
                {
                    int num = board.read((i-1), j);
                    board.writeElement(num, i, j);
                    board.writeElement(0, (i-1),j) ;
                }
            }
        }
    count++;
    }
}

/* Name: moveRight
* Parameters: none
* Returns: nothing
* Function: moves all numbers on the board as far right as possible
*/
void Game::moveRight()
{
    int count = 0;
    while ( count < boardsize )
    {
    for (int i = 0; i < boardsize; i++)
        {
            for (int j = (boardsize-1); j > 0 ; j--)
            {
                if (board.read(i,j) == 0)
                {
                    int num = board.read(i, (j-1));
                    board.writeElement(num, i, j);
                    board.writeElement(0, i, (j-1));
                }
            }
        }
    count++;
    }
}


/* Name: sumUP
* Parameters: none
* Returns: nothing
* Function: sum like numbers on the board, iterating once upward.
*/
void Game::sumUp()
{
    for (int j = 0; j < boardsize; j++)
    {
        for (int i = 0; i < (boardsize-1); i++)
        {
            if (board.read(i,j) == board.read((i+1), j) )
            {
                int num = (board.read((i+1), j) + (board.read(i,j)));
                score = (score + num);
                board.writeElement(num, i, j);
                board.writeElement(0, (i+1),j) ;
            }
        }
    }
}

/* Name: sumDown
* Parameters: none
* Returns: nothing
* Function: sums like numbers on the board, iterating once downward.
*/
void Game::sumDown()
{
    for (int j = 0; j < boardsize; j++)
    {
        for (int i = (boardsize -1); i > 0; i--)
        {
            if (board.read(i,j) == board.read((i-1), j) )
            {
                int num = board.read((i-1), j) + (board.read(i,j));                    score = (score + num);
                board.writeElement(num, i, j);
                board.writeElement(0, (i-1),j);
            }
        }
    }
}

/* Name: sumRight
* Parameters: none
* Returns: nothing
* Function: sums like numbers on the board, iterating once to the right.
*/
void Game::sumRight()
{
    for (int i = 0; i < boardsize; i++)
    {
        for (int j = (boardsize-1); j > 0 ; j--)
        {
            if (board.read(i,j) == board.read(i, (j-1)))
            {
                int num = (board.read(i, (j-1)) +(board.read(i,j)));
                score = (score + num);
                board.writeElement(num, i, j);
                board.writeElement(0, i, (j-1));
            }
        }
    }
}

/* Name: sumLeft
* Parameters: none
* Returns: nothing
* Function: sums like numbers on the board, iterating once to the left.
*/
void Game::sumLeft()
{
    for (int i = 0; i < boardsize; i++)
    {
        for (int j = 0; j < (boardsize-1); j++)
        {
            if (board.read(i,j) == board.read(i, (j+1)))
            {
                int num = (board.read(i, (j+1)) + (board.read(i,j)));
                score = (score + num);
                board.writeElement(num, i, j);
                board.writeElement(0, i, (j+1));
            }
        }
    }
}

/* Name: checkScores NOTE - not needed for basic gameplay, uncomment if desired.
* Parameters: none
* Returns: nothing
* Function: opens the high scores file and prints the top 5 to the screen.
*
void Game::checkScores()
{
    ifstream infile;
    string buffname;
    int buffscore;
    infile.open(SCORE_FILE.c_str());
    if (!infile.is_open())
        {
            cerr << "file did not open" << endl;
        }
    else
        {
        for (int i = 0; i < 5; i++)
            {
                infile >> buffname;
                infile >> buffscore;
                cout << (i+1) << ". Player: " << buffname;
                cout << " - Score: " << buffscore << endl;
            }
        }
    infile.close();
}
*/

/* Name: gameOver
* Parameters: none
* Returns: boolean
* Function: determine that the game is over by returning true when no empty
* squares are left.
*/
bool Game::gameOver()
{
    //if there are still open squares, the game is not over.
    for (int i = 0; i < boardsize; i++)
    {
        for (int j = 0; j < (boardsize); j++)
        {
            if (board.read(i, j) == 0)
                {
                    return false;
                }
        }
    }
    return true;

}
