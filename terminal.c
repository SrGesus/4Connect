//returns the winner, or tie(0), or not a terminal state(2)
int isTerminal (int** board) {

	//check for horizontal lines
	for (int r = 0; r < rows; r++) {

		for (int i = 0; i < columns - 3; i++) {	//for every column except the last three
			if (board[r][i] != ' ') {	//if the slot is not empty
				bool hasPotential = 1;
	
				for (int j = i+1; j < i+4; j++) {	//check if the next three are equal
					if (board[r][i] != board[r][j]) {
						hasPotential = 0;
						break;
					}
				}
				if (hasPotential) {
					return board[r][i];
				}
			}
		}
	}

	//check for vertical lines 
	for (int c = 0; c < columns; c++) {

		for (int i = 0; i < rows - 3; i++) {	//for every row except the last three
			if (board[i][c] != ' ') {	//if the slot is not empty
				bool hasPotential = 1;
	
				for (int j = i+1; j < i+4; j++) {	//check if the next three are equal
					if (board[i][c] != board[j][c]) {
						hasPotential = 0;
						break;
					}
				}
				if (hasPotential) {
					return board[i][c];
				}
			}
		}
	}

	//check for diagonal lines (that go right-down)
	for (int r = 0; r < rows - 3; r++) {
	    for (int c = 0; c < columns - 3; c++) {
		    if (board[r][c] != 32) {
			    bool hasPotential = 1;

    			for (int i = 1; i < 4; i++) {
	    			if (board[r][c] != board[r+i][c+i]) {
			    		hasPotential = 0;
		    			break;
				    }
			    }
			    if (hasPotential) {
				    return board[r][c];
			    }
		    }
	    }
    }


    //check for diagonal lines (that go right-up)
    for (int r = rows-1; r > 2; r--) {
	    for (int c = 0; c < columns - 3; c++) {
		    if (board[r][c] != 32) {
			   	bool hasPotential = 1;
   				for (int i = 1; i < 4; i++) {
    				if (board[r][c] != board[r-i][c+i]) {
	    				hasPotential = 0;
		    			break;
				    }
			    }
			    if (hasPotential) {
				    return board[r][c];
			    }
		    }
	    }
    }
    
    //check for tie
    bool hasSpace = 0;

    for (int i = 0; i < columns; i++) {
        if (!isFull(board, i)) {
            hasSpace = 1;
        }
    } 
    if (!hasSpace) {
        return 0;
    }
	return 2;
}

//returns a value that will be used for utility
int heuristics (int** board) {
    int utility = 0;
    int potential = 0;

	//check in the horizontal lines
	for (int r = 0; r < rows; r++) {

		for (int i = 0; i < columns - 3; i++) {	//for every column except the last three
			if (board[r][i] != ' ') {	//if the slot is not empty
				bool hasPotential = 1;
	            
				for (int j = i+1; j < i+4; j++) {	//check if the next 3 have potential to be turned into a terminal state
					if (board[r][i] == board[r][j] * -1) {  //if the slot we checking is the other player
						hasPotential = 0;
						break;
					}
                    if (board[r][i] == board[r][j]) {
                        potential += board[r][i];
                    }
				}
				if (hasPotential) {
                    utility += potential;   
				}
                potential = 0;
			}
		}
	}

	//check for vertical lines 
	for (int c = 0; c < columns; c++) {

		for (int i = rows - 1; i > 2; i--) {	//for every row except the first three
			if (board[i][c] != ' ') {	//if the slot is not empty
				bool hasPotential = 1;
	
				for (int j = i-1; j > i-4; j--) {	//check if the last three are equal
					if (board[i][c] == board[j][c] * -1) {
						hasPotential = 0;
						break;
					}
                    if (board[i][c] == board[j][c]) {
                        potential += board[i][c];
                    }
				}
				if (hasPotential) {
					utility += potential;
				}
                potential = 0;
			}
		}
	}

	//check for diagonal lines (that go right-down)
	for (int r = 0; r < rows - 3; r++) {
	    for (int c = 0; c < columns - 3; c++) {
		    if (board[r][c] != 32) {
			    bool hasPotential = 1;

    			for (int i = 1; i < 4; i++) {
	    			if (board[r][c] == board[r+i][c+i] * -1) {
			    		hasPotential = 0;
		    			break;
				    }
                    if (board[r][c] == board [r+i][c+i]) {
                        potential += board[r][c];
                    }
			    }
			    if (hasPotential) {
				    utility += potential;
			    }
                potential = 0;
		    }
	    }
    }


    //check for diagonal lines (that go right-up)
    for (int r = rows-1; r > 2; r--) {
	    for (int c = 0; c < columns - 3; c++) {
		    if (board[r][c] != 32) {
			   	bool hasPotential = 1;

   				for (int i = 1; i < 4; i++) {
    				if (board[r][c] == board[r-i][c+i] * -1) {
	    				hasPotential = 0;
		    			break;
				    }
                    if (board[r][c] == board[r-i][c+i]) {
                        potential += board[r][c];
                    }
			    }
			    if (hasPotential) {
				    utility += potential;
			    }
		    }
	    }
    }
    
	return utility;
}
