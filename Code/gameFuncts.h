/** gameFuncts.h
 * ==============================================================
 * Name: Grady Gills, 12/05/2019
 * Section: M6/7 LtCol Chiaramonte
 * Project: MineSweeper - Final Project
 * ==============================================================
*/

#ifndef MINESWEEPER_GAMEFUNCTS_H
#define MINESWEEPER_GAMEFUNCTS_H

#include "other.h"

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
 * ----------------------------------------------------------
 */
void createGame(GameElement game[][Y_DIM]);


/** ----------------------------------------------------------
 * @fn initializeGame()
 * @brief initializes all elements to empty
 * @param game, game matrix
 * ----------------------------------------------------------
 */
void initializeGame(GameElement game[][Y_DIM]);


/** ----------------------------------------------------------
 * @fn setMines()
 * @brief sets mines to random elements in the matrix
 * @param game, game matrix
 * @param numMines, number of mines in the game to set
 * ----------------------------------------------------------
 */
void setMines(GameElement game[][Y_DIM], int numMines);


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


/** ----------------------------------------------------------
 * @fn printMinSec
 * @brief prints a time in minutes and seconds
 * @param t, time in seconds
 * ----------------------------------------------------------
 */
void printMinSec(long t);


/** ----------------------------------------------------------
 * @fn clearSafeBlocks()
 * @brief clears blocks that arent touching blocks that are touching mines
 * @param game, game matrix
 * @param xVal, x coordinate of block in question
 * @param yVal, y coordinate of block in question
 * ----------------------------------------------------------
 */
void clearSafeBlocks(GameElement game[X_DIM][Y_DIM], int xVal, int yVal);


/** ----------------------------------------------------------
 * @fn printWinningMessage()
 * @brief prints a message telling the player they won the game
 * @param timePlayed, the time it took to win the game, in seconds
 * ----------------------------------------------------------
 */
void printWinningMessage(int timePlayed);

#endif //MINESWEEPER_GAMEFUNCTS_H
