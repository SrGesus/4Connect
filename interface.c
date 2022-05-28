//interfacing with the board (printing etc)

void clearScreen() {
    printf("\33[2J\33[0;0H");
}

void printBoard(int** board){
    printf("\n");
    printf("\t 0 1 2 3 4 5 6\n");
    for (int i = 0; i < rows; i++) {
        printf("%d\t|", i);

        for(int j = 0; j < columns; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n");
    }
}
