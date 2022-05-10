
#include "include.h"

int main() {
	rows = 30;
	columns = 40;
	int** board = createBoard();
	clearBoard(board);
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			printf("\t%c", board[i][j]);
		}
		printf("\n");
	}
}

//returns a pointer to a newly created 2D array in the heap (i hope)
int** createBoard() {
	//creates a continuous block of memory in the heap that will store all the values of the board and returns the pointer
	int* ptr = (int *)calloc(rows*columns, sizeof(int));
	//creates an array of pointers, think of it as a separate column, "board" is a double pointer
	int** board = (int **)malloc(rows * sizeof(int *));
	//fills the column with the pointers that are correspondent to every row of the first column
	for(int i = 0; i < rows; i++) {
		board[i] = ptr + i * columns;
	}

	return board;
}


void clearBoard(int** board) {

	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++) {
			board[i][j] = 88;
		}
	}
}
