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

    GameElement game[X_DIM][Y_DIM];
    createGame(game, NUM_MINES);
    //printGame(game);

    startTime = time(NULL);
    while(continue_game) {
        printGame(game);
        getUserInput(&xco, &yco, &action);
        /*if(action == 'c')
            clearBlock();
        else if(action == 'f')
            flagBlock();*/
        continue_game = 0;
        won = 0;
    }
    endTime = time(NULL);

    if(won) {

    } else printLosingMessage();

    return 0;
}