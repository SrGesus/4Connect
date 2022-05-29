//"minimax" algorithm for the AI
int minvalue(int** board, int iteration);
int maxvalue(int** board, int iteration);

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

            int utility = minvalue(potentialstate, 1);
            freeBoard(potentialstate); //free memory
            count++;

/*            if (utility == 1) { //if branch has a utility of 1, ignore the other branches, as it is the maximum
                //print the Elapsed Time
                timespec_get(&ts, TIME_UTC);
                time_t duration = ts.tv_sec-start;
                int durationms = ts.tv_nsec/1000000-startms;
                printf("\nElapsed Time: %d %03d\nUsed Pruning B)", duration, durationms);

                //finish
                return i;
            }*/

            //calculate the maximum utility
            if (max < utility) {
                max = utility;
                position = i;
            }
        }
    }

    //if no path to victory can be found look deeper
    printf("Max %d limit %d defaultLimit %d", max, limit, defaultLimit);
//    if (max < 0 && limit == defaultLimit) {
//        printf("Welp");
//        return minimax(board, limit+5);
//    }

    //print the Elapsed Time
    timespec_get(&ts, TIME_UTC);
    time_t duration = ts.tv_sec-start;
    int durationms = ts.tv_nsec/1000000-startms;
    if (debug) {
       printf("\nElapsed Time: %d %03d", duration, durationms);
       printf("Utility max: %d", max);
    }
    return position;
}

int minvalue (int** board, int iteration) {
    //if the state is terminal return utility
    int utility = isTerminal(board);
    if (utility != 2) {
        return (depthLimit + 2 - iteration) * utility;
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

            utility = maxvalue (potentialstate, iteration+1);
            freeBoard(potentialstate); //free memory
            count++;

/*            if (utility == -1) {  //if branch has a utility of -1, ignore the other branches as it is the minimum
                printf("\nMin Prunin");
                return utility;
            }*/
            
            //calculate the minimum utility, discard if it is 333 (means it went over the depthLimit)
            if (min > utility && utility != 333) {
                min = utility;
            }
        }
    }

    if (min == 100) {
        return 333; //if the min hasn't changed means all the options were discarded
    }
    return min;
}

int maxvalue (int** board, int iteration) {
    //if the state is terminal return utility
    int utility = isTerminal(board);
    if (utility != 2) { //2 is code for not a terminal state
        return (depthLimit + 2 - iteration) * utility;
    }
    //if it exceedes the imposed depth limit, return 333 - code for this situation
    if (iteration == depthLimit) {
        printf("\nIteration %d", iteration);
        return 333;
    }

    int max = -100; //an arbitrarily small value

    //turn max into the greatest utility out of the branches
    for (int i = 0; i < columns; i++) {
        if(!isFull(board, i)) {
            int** potentialstate = copyBoard(board); //allocates memory to the new board
            placeDisk(potentialstate, i, 1);
            
            utility = minvalue (potentialstate, iteration+1);
            freeBoard(potentialstate); //free memory
            count++;

/*            if (utility == 1) {  //if branch has a utility of 1, ignore the other branches as it is the maximum
                return utility;
            }*/
            
            //calculate the maximum utility, discard if it is 333 (means it went over the depthLimit)
            if (max < utility && utility != 333) {
                max = utility;
            }
        }
    }
    if (max == -100) {
        return 333; //if the max hasn't changed means all the options were discarded
    }
    return max;
}
