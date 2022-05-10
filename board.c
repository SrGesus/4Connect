//in this file are stored the functions relating to the manipulation of the Connect 4 board

//returns a pointer to a newly created 2D array in the heap
int** createBoard() {
	//creates a continuous block of memory in the heap that will store all the values of the board and returns the pointer
	int* ptr = (int *)calloc(rows*columns, sizeof(int));
	//creates an array of pointers, think of it as a separate column, "board" is a double pointer
	int** board = (int **)malloc(rows * sizeof(int *));
	
	if(ptr == NULL || board == NULL) {
		printf("Couldn't allocate memory");
		exit(1);
	}

	//fills the column with the pointers that are correspondent to every row of the first column
	for(int i = 0; i < rows; i++) {
		board[i] = ptr + i * columns;
	}
	
	return board;
}

void freeBoard(int** board) {
	//free the allocated memory for the block of memory where the values are stored, and the pointer array
	free(*board);
	free(board);
}

void clearBoard(int** board) {

	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++) {
			board[i][j] = 32;
		}
	}
}

bool isFull(int** board, int column) {
	if (board[0][column] == 'X' || board[0][column] == 'O') {
		return 1;
	}
	return 0;
}

void placeDisk(int** board, int column, int player) {
	for (int i = rows-1; i >= 0; i--) {
		if (board[i][column] == 32) {
			board[i][column] = player;
			return;
		}
	}
}
