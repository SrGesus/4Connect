//native headers
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <curses.h>

//global variables
int rows, columns;
int count = 0;
int depthLimit = 2;
int defaultLimit = 8;
int debug = 1;

//4Connect files
#include "board.c"
#include "interface.c"
#include "terminal.c"
#include "minimax.c"
