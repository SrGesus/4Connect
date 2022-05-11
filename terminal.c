//returns the winner('X' or 'O'), or tie(0), or not a terminal state(2)
int isTerminal (int** board) {

	//check for horizontal lines
	for (int r = 0; r < rows; r++) {

		for (int i = 0; i < columns - 3; i++) {	//for every column except the last three
			if (board[r][i] != ' ') {	//if the slot is not empty
				bool isEqual = 1;
	
				for (int j = i+1; j < i+4; j++) {	//check if the next three are equal
					if (board[r][i] != board[r][j]) {
						isEqual = 0;
						break;
					}
				}
				if (isEqual) {
					return board[r][i];
				}
			}
		}
	}

	//check for vertical lines 
	for (int c = 0; c < columns; c++) {

		for (int i = 0; i < rows - 3; i++) {	//for every row except the last three
			if (board[i][c] != ' ') {	//if the slot is not empty
				bool isEqual = 1;
	
				for (int j = i+1; j < i+4; j++) {	//check if the next three are equal
					if (board[i][c] != board[j][c]) {
						isEqual = 0;
						break;
					}
				}
				if (isEqual) {
					return board[i][c];
				}
			}
		}
	}

	//check for diagonal lines (that go right-down)
	for (int r = 0; r < rows - 3; r++) {
	for (int c = 0; c < columns - 3; c++) {
		if (board[r][c] != 32) {
			bool isEqual = 1;

			for (int i = 1; i < 4; i++) {
				if (board[r][c] != board[r+i][c+i]) {
					isEqual = 0;
					break;
				}
			}
			if (isEqual) {
				return board[r][c];
			}
		}
	}
}


//check for diagonal lines (that go right-up)
for (int r = rows-1; r > 2; r--) {
	for (int c = 0; c < columns - 3; c++) {
			if (board[r][c] != 32) {
				bool isEqual = 1;

				for (int i = 1; i < 4; i++) {
					if (board[r][c] != board[r-i][c+i]) {
						isEqual = 0;
						break;
					}
				}
				if (isEqual) {
					return board[r][c];
				}
			}
		}
	}

	return 2;
}
