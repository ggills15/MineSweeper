//
// Created by C22Grady.Gills on 11/5/2019.
//

#include "gameFuncts.h"

int main(void) {
    srand(time(0));
    int continue_game = 1;
    time_t startTime, endTime;
    int xco, yco;
    char action;
    int won;
    int flaggedMines = 0;

    GameElement game[X_DIM][Y_DIM];
    createGame(game);
    printGame(game);


    startTime = time(NULL);
    while(continue_game) {
        printGame(game);
        getUserInput(&xco, &yco, &action);
        if(action == 'c')
            clearBlock(&game[xco][yco], &continue_game, &won);
        else //if(action == 'f')
            flagBlock(&game[xco][yco], &flaggedMines);
        if(flaggedMines == NUM_MINES) {
            won = 1;
            continue_game = 0;
        }
    }
    endTime = time(NULL);

    if(won) {
        printf("Time completed: %ld s", endTime - startTime);

    } else printLosingMessage();

    return 0;
}