//for manipulating the board

//returns a board full of spaces
int** createBoard() {

    int* values = calloc (rows*columns, sizeof(int));
    
    for (int i = 0; i < rows*columns; i++) {
        values[i] = ' '; //fill values with spaces
    }
    
    //this will create an array of pointers that point to the address of the first columns of each row
    int** board = malloc (rows * sizeof(int*));
    
    for (int i = 0; i < rows; i++) {
        board[i] = values + i * columns;    
    }

    return board;
}

int** copyBoard(int** board) {
    
    int* oldvalues = board[0];
    int* values = calloc (rows*columns, sizeof(int));
    
    for (int i = 0; i < rows*columns; i++) {
        values[i] = oldvalues[i];
    }
    
    //this will create an array of pointers that point to the address of the first columns of each row
    int** newBoard = malloc (rows * sizeof(int*));
    
    for (int i = 0; i < rows; i++) {
        newBoard[i] = values + i * columns;    
    }
    
    return newBoard;
}

void freeBoard (int** board) {
    //free(board[0]);
    
    free ((void *)board[0]);
    free ((void *)board);
}

int** convertBoard(int** oldBoard, int player) {    //converts board full of X and O's into 1's and -1's, 1 being the AI
    int** board = copyBoard (oldBoard);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if(board[i][j] == player && board[i][j] != 32) {
                board[i][j] = -1;
            } else if (board[i][j] != 32) {
                board[i][j] = 1;
            }
        }
    }
    return board;
}


bool isFull(int** board, int c) {
    if (board[0][c] != ' ') {
        return 1;
    }
    return 0;
}

//this function assumes column isn't full
int placeDisk (int** board, int c, int player) {
    //find the first space starting from the bottom
    for (int i = rows-1; i >= 0; i--) {
        if (board[i][c] == 32) {
            board[i][c] = player;
            return 1;
        }
    }
}
