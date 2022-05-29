//"minimax" algorithm for the AI
int minvalue(int** board, int iteration, int max);
int maxvalue(int** board, int iteration, int min);

int minimax(int** board, int limit) {
    printf("\nBegin");
    //depthLimit is a global variable
    depthLimit = limit;

    int max = -100; //arbitrarily small value
    int position = 4;

    //start the timer
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    //start time in seconds (integer)
    time_t start = ts.tv_sec;
    //start time in milliseconds (integer)
    int startms = ts.tv_nsec/1000000;

    //turn position into the play with max utility
    for (int i = 0; i < columns; i++) {
        if (!isFull(board, i)) {
            int** potentialstate = copyBoard(board); //allocates the memory for the new board
            placeDisk(potentialstate, i, 1);

            int utility = minvalue(potentialstate, 1, max);
            freeBoard(potentialstate); //free memory
            count++;

            if (utility == 1) { //if branch has a utility of 1, ignore the other branches, as it is the maximum
                timespec_get(&ts, TIME_UTC);
                time_t duration = ts.tv_sec-start;
                int durationms = ts.tv_nsec/1000000-startms;
                printf("\nElapsed Time: %d %03d\nUsed Pruning B)", duration, durationms);

                return i;
            }

            //update the maximum utility
            if (max < utility) {
                max = utility;
                position = i;
            }
        }
    }


    //print the Elapsed Time
    timespec_get(&ts, TIME_UTC);
    time_t duration = ts.tv_sec-start;
    int durationms = ts.tv_nsec/1000000-startms;
    if (debug) {
       printf("\nElapsed Time: %d %03d", duration, durationms);
       printf("\nMax %d limit %d defaultLimit %d", max, limit, defaultLimit);
       printf("\nUtility max: %d", max);
    }
    return position;
}

int minvalue (int** board, int iteration, int max) {
    //if the state is terminal return utility
    int utility = isTerminal(board);
    if (utility != 2) {
        //the number of plays left until the depthLimit + 1, the symmetric of it if MIN wins (or 0 for ties
        return (depthLimit + 1 - iteration) * utility; 
    }

    //if it exceedes the imposed depth limit, return 333 - code for this situation
    if (iteration == depthLimit) {
        printf("\nDumped");
        return 333;
    }
    //an arbitrarily big value
    int min = 100;

    //turn min into the smallest utility out of the branches
    for (int i = 0; i < columns; i++) {
        if(!isFull(board, i)) {
            int** potentialstate = copyBoard(board); //allocates memory to the new board
            placeDisk(potentialstate, i, -1);

            utility = maxvalue (potentialstate, iteration+1, min);
            freeBoard(potentialstate); //free memory
            count++;
            
            //if player MIN wins next turn, ignore the other brances
            if (utility * -1 == depthLimit - iteration) {
                return utility;
            }

            //calculate the minimum utility, discard if it is 333 (means it went over the depthLimit)
            if (min > utility && utility != 333) {
                min = utility;
            }

            //if the current minimum is smaller than the maximum of the iteration above, discard the other branches since they won't influence anything
            if (min < max) {
                return min;
            }
        }
    }

    if (min == 100) {
        return 333; //if the min hasn't changed means all the options were all beyond the depthLimit
    }
    return min;
}

int maxvalue (int** board, int iteration, int min) {
    //if the state is terminal return utility
    int utility = isTerminal(board);
    if (utility != 2) { //2 is code for not a terminal state
        //the number of plays left until the depthLimit + 1, the symmetric of it if MIN wins (or 0 for ties
        return (depthLimit + 1 - iteration) * utility;
    }
    //if it exceedes the imposed depth limit, return 333 - code for this situation
    if (iteration == depthLimit) {
        return 333;
    }

    int max = -100; //an arbitrarily small value

    //turn max into the greatest utility out of the branches
    for (int i = 0; i < columns; i++) {
        if(!isFull(board, i)) {
            int** potentialstate = copyBoard(board); //allocates memory to the new board
            placeDisk(potentialstate, i, 1);
            
            utility = minvalue (potentialstate, iteration+1, max);
            freeBoard(potentialstate); //free memory
            count++;

            //if player MAX wins next turn, ignore the other branches
            if (utility == depthLimit - iteration) {
                return utility;
            }

            //calculate the maximum utility, discard if it is 333 (means it went over the depthLimit)
            if (max < utility && utility != 333) {
                max = utility;
            }
            //if the current maximum is greater than the minimum of the iteration above, discard the other branches since they won't influence anything
             if (max > min) {
                return max;
            }
        }
    }
    if (max == -100) {
        return 333; //if the max hasn't changed means all the options were discarded
    }
    return max;
}
