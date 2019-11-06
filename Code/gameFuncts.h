//
// Created by C22Grady.Gills on 11/5/2019.
//

#ifndef MINESWEEPER_GAMEFUNCTS_H
#define MINESWEEPER_GAMEFUNCTS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define X_DIM 8
#define Y_DIM 8
#define NUM_MINES 10

typedef struct GameElement_struct {
    int isMine;
    int isFlagged;
    int isCleared;
    int amountTouching;
}GameElement;

/** ----------------------------------------------------------
 * @fn printGame()
 * @brief prints the game board onto the screen
 * @param game, matrix of each element
 * ----------------------------------------------------------
 */
void printGame(GameElement game[X_DIM][Y_DIM]);


/** ----------------------------------------------------------
 * @fn createGame()
 * @brief creates the game matrix
 * @param game, game matrix
 * @param numMines, number of mines in the game
 * ----------------------------------------------------------
 */
void createGame(GameElement game[X_DIM][Y_DIM], int numMines);


/** ----------------------------------------------------------
 * @fn initializeGame()
 * @brief initializes all elements to empty
 * @param game, game matrix
 * ----------------------------------------------------------
 */
void initializeGame(GameElement game[X_DIM][Y_DIM]);


/** ----------------------------------------------------------
 * @fn setMines()
 * @brief sets mines to random elements in the matrix
 * @param game, game matrix
 * @param numMines, number of mines in the game to set
 * ----------------------------------------------------------
 */
void setMines(GameElement game[X_DIM][Y_DIM], int numMines);


/** ----------------------------------------------------------
 * @fn countTouchingMines()
 * @brief counts the number of mines touching given element
 * @param game, game matrix
 * @param xVal, first index of game element to count
 * @param yVal, second index of game element to count
 * @return count, number of mines touching
 * ----------------------------------------------------------
 */
int countTouchingMines(GameElement game[X_DIM][Y_DIM], int xVal, int yVal);


/** ----------------------------------------------------------
 * @fn setMinesTouching()
 * @brief sets the amountTouching attribute in each element
 * @param game, game matrix
 * ----------------------------------------------------------
 */
void setMinesTouching(GameElement game[X_DIM][Y_DIM]);


/** ----------------------------------------------------------
 * @fn getUserInput()
 * @brief asks user to input coordinates and action
 * @param xco, vertical coordinate
 * @param yco, horixontal coordinate
 * @param act, action to do (c/f)
 * ----------------------------------------------------------
 */
void getUserInput(int* xco, int* yco, char* act);


/** ----------------------------------------------------------
 * @fn printLosingMessage()
 * @brief tells the user they lost with an appropriate Metallica quote
 * ----------------------------------------------------------
 */
void printLosingMessage();


/** ----------------------------------------------------------
 * @fn clearBlock()
 * @brief clears selected block, loses game if its a mine
 * @param gameBlock, selected game element
 * @param contGame, game status, set to 0 if mine is hit
 * @param won, updated to 0 if mine is hit
 * ----------------------------------------------------------
 */
void clearBlock(GameElement* gameBlock, int* contGame, int* won);


/** ----------------------------------------------------------
 * @fn flagBlock()
 * @brief flags selected block as suspected mine
 * @param gameBlock, selected game element
 * @param flagct, flag count, updated if actual mine is flagged
 * ----------------------------------------------------------
 */
void flagBlock(GameElement* gameBlock, int* flagct);

#endif //MINESWEEPER_GAMEFUNCTS_H
