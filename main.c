
#include "include.h"

int main() {
	rows = 6;
	columns = 7;
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
	}
}
