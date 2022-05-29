#include "include.h"

int main(void) {
    rows = 6;
    columns = 7;
    int** board = createBoard();
    int player = 'O';
    int c; //user input

    while (1) {
        count = 0;
        depthLimit = defaultLimit;
        placeDisk(board, minimax(convertBoard(board, player), depthLimit), 'X');
      
        printBoard(board);
        printf("\nState: %d\nCount: %d\nEnter the column: ", isTerminal(board), count);
        scanf("%d", &c);

        placeDisk(board, c, player);


   }
}
