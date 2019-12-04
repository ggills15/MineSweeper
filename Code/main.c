/** main.c
 * ==============================================================
 * Name: Grady Gills, 12/05/2019
 * Section: M6/7 LtCol Chiaramonte
 * Project: MineSweeper - Final Project
 * Documentation Statement: referenced stackoverflow.com to figure out how to set a running timer in C
 * ==============================================================
*/

#include "gameFuncts.h"
#include "other.h"

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

    startTime = time(NULL);
    while(continue_game) {
        printGame(game);
        getUserInput(&xco, &yco, &action);
        if(action == 'c') {
            clearBlock(&game[xco][yco], &continue_game, &won);
            clearSafeBlocks(game, xco, yco);
        }
        else if(action == 'f')
            flagBlock(&game[xco][yco], &flaggedMines);
        else
            printf("Invalid input.\n");
        if(flaggedMines == NUM_MINES) {
            won = 1;
            continue_game = 0;
        }
    }
    endTime = time(NULL);

    if(won)
        printWinningMessage(endTime-startTime);
    else
        printLosingMessage();

    return 0;
}