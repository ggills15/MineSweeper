/** gameFuncts.c
 * ==============================================================
 * Name: Grady Gills, 12/05/2019
 * Section: M6/7 LtCol Chiaramonte
 * Project: MineSweeper - Final Project
 * ==============================================================
*/

#include "gameFuncts.h"

/** ----------------------------------------------------------
 * @fn printGame()
 * @brief prints the game board onto the screen
 * @param game, matrix of each element
 * ----------------------------------------------------------
 */
void printGame(GameElement game[X_DIM][Y_DIM]) {
    printf("     ");
    for(int i = 0; i < X_DIM; ++i)
        printf("%2d  ", i);
    printf("\n    --");
    for(int i= 0; i < X_DIM; ++i)
        printf("----");
    printf("\n");

    for(int i = 0; i < X_DIM; ++i) {
        printf("%2d | ", i);
        for(int j = 0; j < Y_DIM; ++j) {
            if(game[i][j].isCleared)
                printf("|%d| ", game[i][j].amountTouching);
            else if(game[i][j].isFlagged)
                printf("|!| ");
            else
                printf("|_| ");
        }
        printf("|\n");
    }

    printf("    --");
    for(int i= 0; i < X_DIM; ++i)
        printf("----");
    printf("\n");
}


/** ----------------------------------------------------------
 * @fn createGame()
 * @brief creates the game matrix
 * @param game, game matrix
 * ----------------------------------------------------------
 */
void createGame(GameElement game[][Y_DIM]) {
    initializeGame(game);
    setMines(game, NUM_MINES);
    setMinesTouching(game);
}


/** ----------------------------------------------------------
 * @fn initializeGame()
 * @brief initializes all elements to empty
 * @param game, game matrix
 * ----------------------------------------------------------
 */
void initializeGame(GameElement game[][Y_DIM]) {
    for(int i = 0; i < X_DIM; ++i) {
        for(int j = 0; j < Y_DIM; ++j) {
            game[i][j].isMine = 0;
            game[i][j].isFlagged = 0;
            game[i][j].isCleared = 0;
            game[i][j].amountTouching = 0;
        }
    }
}


/** ----------------------------------------------------------
 * @fn setMines()
 * @brief sets mines to random elements in the matrix
 * @param game, game matrix
 * @param numMines, number of mines in the game to set
 * ----------------------------------------------------------
 */
void setMines(GameElement game[][Y_DIM], int numMines) {
    int x,y;

    for(int i = 0; i < numMines; ++i) {
        x = rand() % X_DIM;
        y = rand() % Y_DIM;
        if(game[x][y].isMine)
            --i;
        else
            game[x][y].isMine = 1;
    }
}


/** ----------------------------------------------------------
 * @fn countTouchingMines()
 * @brief counts the number of mines touching given element
 * @param game, game matrix
 * @param xVal, first index of game element to count
 * @param yVal, second index of game element to count
 * @return count, number of mines touching
 * ----------------------------------------------------------
 */
int countTouchingMines(GameElement game[X_DIM][Y_DIM], int xVal, int yVal) {
    int count = 0;

    if(game[xVal - 1][yVal - 1].isMine && (xVal - 1) >= 0 && (yVal - 1) >= 0)
        ++count;
    if(game[xVal - 1][yVal].isMine && (xVal - 1) >= 0)
        ++count;
    if(game[xVal - 1][yVal + 1].isMine && (xVal - 1) >= 0 && (yVal + 1) < Y_DIM)
        ++count;
    if(game[xVal][yVal - 1].isMine && (yVal - 1) >= 0)
        ++count;
    if(game[xVal][yVal + 1].isMine && (yVal + 1) < Y_DIM)
        ++count;
    if(game[xVal + 1][yVal - 1].isMine && (xVal + 1) < X_DIM && (yVal - 1) >= 0)
        ++count;
    if(game[xVal + 1][yVal].isMine && (xVal + 1) < X_DIM)
        ++count;
    if(game[xVal + 1][yVal + 1].isMine && (xVal + 1) < X_DIM && (yVal + 1) < Y_DIM)
        ++count;

    return count;
}


/** ----------------------------------------------------------
 * @fn setMinesTouching()
 * @brief sets the amountTouching attribute in each element
 * @param game, game matrix
 * ----------------------------------------------------------
 */
void setMinesTouching(GameElement game[X_DIM][Y_DIM]) {
    for(int i = 0; i < X_DIM; ++i) {
        for(int j = 0; j < Y_DIM; ++j) {
            game[i][j].amountTouching = countTouchingMines(game, i, j);
        }
    }
}


/** ----------------------------------------------------------
 * @fn getUserInput()
 * @brief asks user to input coordinates and action
 * @param xco, vertical coordinate
 * @param yco, horixontal coordinate
 * @param act, action to do (c/f)
 * ----------------------------------------------------------
 */
void getUserInput(int* xco, int* yco, char* act) {
    printf("Actions: clear (c), or flag (f)\n");
    printf("Enter a vertical coordinate, horizontal coordinate, and action seperated by spaces:\n");
    scanf("%d %d  %c", yco, xco, act);
}


/** ----------------------------------------------------------
 * @fn printLosingMessage()
 * @brief tells the user they lost with an appropriate Metallica quote
 * ----------------------------------------------------------
 */
void printLosingMessage() {
    printf("BOOM!\nYou hit a mine and died!\n");
    printf("\"Landmines have taken my sight, taken my speech, taken my hearing,\ntaken my arms, taken my legs, taken my soul...\"\n- James Hetfield\n");
    printf("\nYou lose\n");
}


/** ----------------------------------------------------------
 * @fn clearBlock()
 * @brief clears selected block, loses game if its a mine
 * @param gameBlock, selected game element
 * @param contGame, game status, set to 0 if mine is hit
 * @param won, updated to 0 if mine is hit
 * ----------------------------------------------------------
 */
void clearBlock(GameElement* gameBlock, int* contGame, int* won) {
    if(gameBlock->isMine) {
        *contGame = 0;
        *won = 0;
    } else gameBlock->isCleared |= 1;       //THIS IS THE ONLY INSTANCE I COULD THINK OF USING BIT OPS OR ANY ADVANCED PROGRAMMING TOPIC, PLEASE GIVE ME POINTS
}


/** ----------------------------------------------------------
 * @fn flagBlock()
 * @brief flags selected block as suspected mine
 * @param gameBlock, selected game element
 * @param flagct, flag count, updated if actual mine is flagged
 * ----------------------------------------------------------
 */
void flagBlock(GameElement* gameBlock, int* flagct) {
    gameBlock->isFlagged = !(gameBlock->isFlagged);
    if (gameBlock->isMine)
        ++(*flagct);
}


/** ----------------------------------------------------------
 * @fn printMinSec
 * @brief prints a time in minutes and seconds
 * @param t, time in seconds
 * ----------------------------------------------------------
 */
void printMinSec(long t) {
    int min = t / 60;
    int sec = t % 60;
    printf("%d min %d sec\n", min, sec);
}


/** ----------------------------------------------------------
 * @fn clearSafeBlocks()
 * @brief clears blocks that arent touching blocks that are touching mines
 * @param game, game matrix
 * @param xVal, x coordinate of block in question
 * @param yVal, y coordinate of block in question
 * ----------------------------------------------------------
 */
void clearSafeBlocks(GameElement game[X_DIM][Y_DIM], int xVal, int yVal) {      //NEVERMIND I KIND OF USED RECURSION HERE

    if(!game[xVal - 1][yVal - 1].isMine && (xVal - 1) >= 0 && (yVal - 1) >= 0) {            //Please excuse this absolute sh**show of a function. I understand I could have broken it up
        game[xVal][yVal].isCleared = 1;                                                     //into smaller functions but once I got it working I did not want to mess it up
        if(!game[xVal - 1][yVal - 1].isCleared) {
            if(game[xVal - 1][yVal - 1].amountTouching == 0)
                clearSafeBlocks(game, xVal - 1, yVal - 1);
            else
                game[xVal - 1][yVal - 1].isCleared = 1;
        }
    }
    if(!game[xVal - 1][yVal].isMine && (xVal - 1) >= 0) {
        game[xVal][yVal].isCleared = 1;
        if(!game[xVal - 1][yVal].isCleared) {
            if(game[xVal - 1][yVal].amountTouching == 0)
                clearSafeBlocks(game, xVal - 1, yVal);
            else
                game[xVal - 1][yVal].isCleared = 1;
        }
    }
    if(!game[xVal - 1][yVal + 1].isMine && (xVal - 1) >= 0 && (yVal + 1) < Y_DIM) {
        game[xVal][yVal].isCleared = 1;
        if(!game[xVal - 1][yVal + 1].isCleared) {
            if(game[xVal - 1][yVal + 1].amountTouching == 0)
                clearSafeBlocks(game, xVal - 1, yVal + 1);
            else
                game[xVal - 1][yVal + 1].isCleared = 1;
        }
    }
    if(!game[xVal][yVal - 1].isMine && (yVal - 1) >= 0) {
        game[xVal][yVal].isCleared = 1;
        if(!game[xVal][yVal - 1].isCleared) {
            if(game[xVal][yVal - 1].amountTouching == 0)
                clearSafeBlocks(game, xVal, yVal - 1);
            else
                game[xVal][yVal - 1].isCleared = 1;
        }
    }
    if(!game[xVal][yVal + 1].isMine && (yVal + 1) < Y_DIM) {
        game[xVal][yVal].isCleared = 1;
        if(!game[xVal][yVal + 1].isCleared) {
            if(game[xVal][yVal + 1].amountTouching == 0)
                clearSafeBlocks(game, xVal, yVal + 1);
            else
                game[xVal][yVal + 1].isCleared = 1;
        }
    }
    if(!game[xVal + 1][yVal - 1].isMine && (xVal + 1) < X_DIM && (yVal - 1) >= 0) {
        game[xVal][yVal].isCleared = 1;
        if(!game[xVal + 1][yVal - 1].isCleared) {
            if(game[xVal + 1][yVal - 1].amountTouching == 0)
                clearSafeBlocks(game, xVal + 1, yVal - 1);
            else
                game[xVal + 1][yVal - 1].isCleared = 1;
        }
    }
    if(!game[xVal + 1][yVal].isMine && (xVal + 1) < X_DIM) {
        game[xVal][yVal].isCleared = 1;
        if(!game[xVal + 1][yVal].isCleared) {
            if(game[xVal + 1][yVal].amountTouching == 0)
                clearSafeBlocks(game, xVal + 1, yVal);
            else
                game[xVal + 1][yVal].isCleared = 1;
        }
    }
    if(!game[xVal + 1][yVal + 1].isMine && (xVal + 1) < X_DIM && (yVal + 1) < Y_DIM) {
        game[xVal][yVal].isCleared = 1;
        if(!game[xVal + 1][yVal + 1].isCleared) {
            if(game[xVal + 1][yVal + 1].amountTouching == 0)
                clearSafeBlocks(game, xVal + 1, yVal + 1);
            else
                game[xVal + 1][yVal + 1].isCleared = 1;
        }
    }
}


/** ----------------------------------------------------------
 * @fn printWinningMessage()
 * @brief prints a message telling the player they won the game
 * @param timePlayed, the time it took to win the game, in seconds
 * ----------------------------------------------------------
 */
void printWinningMessage(int timePlayed) {
    printf("Congrats! You won!\nTime completed: ");
    printMinSec(timePlayed);
}