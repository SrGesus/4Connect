//native headers
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

//global variables
int rows, columns;
int count = 0;
int depthLimit = 2;
int defaultLimit = 7;
int debug = 1;

//4Connect files
#include "board.c"
#include "interface.c"
#include "terminal.c"
#include "minimax.c"
