/* * Dylan Hudson, May 2017
* Originally designed as a homework assignment for
* Professor Laney Strange's Comp 11; modified for simplicity
* and stability.
* Header File for class Grid - a dynamic 2D array data
* structure. Getters/setters and functions specialized for 2048
* game play.

 */

 #include <iostream>

 using namespace std;

 #ifndef GRID_H_
 #define GRID_H_


 class Grid {
     private:
         int size;
         int** grid;

     public:
         //constructor
         Grid();

         //destructor
         ~Grid();

         //returns the size of the board
         int getSize();

         //sets an int as the value at the given indeces
         void writeElement(int element, int row, int col);

         //prints the board
         void print();

         //initialize with 0s - "empty" tiles
         void initialize();

         //allocate
         void allocate(int);

         //returns the value at the locus provided
         int read(int, int);

         //generates a new tile for the board
         int makeTile();
         //places tile on empty edge sqaures
         void placeTile(int tile);

         //places tile on a row edge
         bool placeRow(int tile);
         //places tile on a col edge
         bool placeCol(int tile);

 };

 #endif
