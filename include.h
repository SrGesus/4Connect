
//headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//global variables
int rows, columns; //this is the board's syntax: board[rows][columns]

//function declarations

//board.c
int** createBoard();
void printBoard(int** board);
void clearBoard(int** board);
bool isFull(int** board, int column);
void placeDisk(int** board, int column, int player);

#include "board.c"
#include "interface.c"


