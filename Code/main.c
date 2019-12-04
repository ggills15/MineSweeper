/** main.c
 * ==============================================================
 * Name: Grady Gills, 12/05/2019
 * Section: M6/7 LtCol Chiaramonte
 * Project: MineSweeper - Final Project
 * Documentation Statement: referenced stackoverflow.com to figure out how to set a running timer in C
 *                          and how to clear the screen using system("clear")
 * ==============================================================
*/

#include "gameFuncts.h"
#include "other.h"

int main(void) {
    srand(time(0)); //seeds the rand() function so the game board is different each time
    int continue_game = 1;
    time_t startTime, endTime;
    int xco, yco;
    char action;
    int won;
    int flaggedMines = 0;

    GameElement game[X_DIM][Y_DIM];
    createGame(game);

    startTime = time(NULL);     //starts the timer by recording time that game is started
    while(continue_game) {
        printGame(game);
        getUserInput(&xco, &yco, &action);

        if(action == 'c') {         //does respective action for user input
            clearBlock(&game[xco][yco], &continue_game, &won);
            if(!game[xco][yco].amountTouching)
                clearSafeBlocks(game, xco, yco);
        }
        else if(action == 'f')
            flagBlock(&game[xco][yco], &flaggedMines);
        else
            printf("Invalid input.\n");

        if(flaggedMines == NUM_MINES) {     //ends the game and signals a win if all mines are flagged
            won = 1;
            continue_game = 0;
        }
    }
    endTime = time(NULL);       //end timer by recording time game is finished

    if(won)
        printWinningMessage(endTime-startTime);
    else
        printLosingMessage();

    return 0;
}