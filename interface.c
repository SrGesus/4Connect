
void clearScreen() {
	printf("\33[2J\33[0;0H");
}

void printBoard(int** board) {
	for(int i = 0; i < rows; i++) {
		printf("%d", i);
		for(int j = 0; j < columns; j++) {
			printf("\t%c", board[i][j]);
		}
		printf("\n");
	}

}

