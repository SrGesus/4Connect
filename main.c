
#include "include.h"

int main() {
	rows = 10;
	columns = 10;
	int** board = createBoard();
	clearBoard(board);
	printBoard(board);
	int player = 'X';
	int c;
	while (1) {
		if (player == 'X') {
			player = 'O';
		} else {
			player = 'X';
		}
		scanf("%d", &c);
		clearScreen();
		placeDisk(board, c, player);
		printBoard(board);
		printf("\nTerminal state values: %d\n", isTerminal(board));
	}
}
