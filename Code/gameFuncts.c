//
// Created by C22Grady.Gills on 11/5/2019.
//

#include "gameFuncts.h"

/** ----------------------------------------------------------
 * @fn printGame()
 * @brief prints the game board onto the screen
 * @param game, matrix of each element
 * ----------------------------------------------------------
 */
void printGame(GameElement game[X_DIM][Y_DIM]) {
    printf("     0   1   2   3   4   5   6   7\n");
    printf("   ---------------------------------\n");
    for(int i = 0; i < X_DIM; ++i) {
        printf("%d | ", i);
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
    printf("   ---------------------------------\n");
}


/** ----------------------------------------------------------
 * @fn createGame()
 * @brief creates the game matrix
 * @param game, game matrix
 * ----------------------------------------------------------
 */
void createGame(GameElement game[][Y_DIM]) {    //FIXME: pointer issue, setMines() will set mines in main scope but not in createGame() scope
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
        game[x][y].isMine = 1;
    }
    for(int i = 0; i < X_DIM; ++i) {
        for(int j = 0; j < Y_DIM; ++j) {
            printf("%d ", game[i][j].isMine);
        }
        printf("\n");
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
    if(xVal == 0 && yVal == 0) {
        if(game[xVal + 1][yVal].isMine)
            ++count;
        if(game[xVal][yVal + 1].isMine)
            ++count;
        if(game[xVal + 1][yVal + 1].isMine)
            ++count;
    }
    else if(xVal == X_DIM - 1 && yVal == Y_DIM - 1) {
        if(game[xVal - 1][yVal].isMine)
            ++count;
        if(game[xVal][yVal - 1].isMine)
            ++count;
        if(game[xVal - 1][yVal - 1].isMine)
            ++count;
    }
    else if(xVal == 0 && yVal == Y_DIM - 1) {
        if(game[xVal + 1][yVal].isMine)
            ++count;
        if(game[xVal][yVal - 1].isMine)
            ++count;
        if(game[xVal + 1][yVal - 1].isMine)
            ++count;
    }
    else if(xVal == X_DIM - 1 && yVal == 0) {
        if(game[xVal - 1][yVal].isMine)
            ++count;
        if(game[xVal][yVal + 1].isMine)
            ++count;
        if(game[xVal - 1][yVal + 1].isMine)
            ++count;
    }
    else if(xVal == 0) {
        if(game[xVal + 1][yVal].isMine)
            ++count;
        if(game[xVal][yVal + 1].isMine)
            ++count;
        if(game[xVal + 1][yVal + 1].isMine)
            ++count;
        if(game[xVal][yVal - 1].isMine)
            ++count;
        if(game[xVal + 1][yVal - 1].isMine)
            ++count;
    }
    else if(xVal == X_DIM - 1) {
        if(game[xVal - 1][yVal].isMine)
            ++count;
        if(game[xVal][yVal + 1].isMine)
            ++count;
        if(game[xVal - 1][yVal + 1].isMine)
            ++count;
        if(game[xVal][yVal - 1].isMine)
            ++count;
        if(game[xVal - 1][yVal - 1].isMine)
            ++count;
    }
    else if(yVal == 0) {
        if(game[xVal + 1][yVal].isMine)
            ++count;
        if(game[xVal][yVal + 1].isMine)
            ++count;
        if(game[xVal + 1][yVal + 1].isMine)
            ++count;
        if(game[xVal - 1][yVal].isMine)
            ++count;
        if(game[xVal - 1][yVal].isMine)
            ++count;
    }
    else if(yVal == Y_DIM - 1) {
        if(game[xVal - 1][yVal].isMine)
            ++count;
        if(game[xVal + 1][yVal].isMine)
            ++count;
        if(game[xVal][yVal - 1].isMine)
            ++count;
        if(game[xVal + 1][yVal - 1].isMine)
            ++count;
        if(game[xVal - 1][yVal - 1].isMine)
            ++count;
    }
    else { //finally
        if(game[xVal][yVal + 1].isMine)
            ++count;
        if(game[xVal][yVal - 1].isMine)
            ++count;
        if(game[xVal + 1][yVal + 1].isMine)
            ++count;
        if(game[xVal + 1][yVal - 1].isMine)
            ++count;
        if(game[xVal + 1][yVal].isMine)
            ++count;
        if(game[xVal - 1][yVal + 1].isMine)
            ++count;
        if(game[xVal - 1][yVal - 1].isMine)
            ++count;
        if(game[xVal - 1][yVal].isMine)
            ++count;
    }
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
        contGame = 0;
        won = 0;
    } else gameBlock->isCleared = 1;
}


/** ----------------------------------------------------------
 * @fn flagBlock()
 * @brief flags selected block as suspected mine
 * @param gameBlock, selected game element
 * @param flagct, flag count, updated if actual mine is flagged
 * ----------------------------------------------------------
 */
void flagBlock(GameElement* gameBlock, int* flagct) {
    gameBlock->isFlagged = 1;
    if (gameBlock->isMine)
        ++flagct;
}