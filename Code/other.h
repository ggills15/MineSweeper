/** other.h
 * ==============================================================
 * Name: Grady Gills, 12/05/2019
 * Section: M6/7 LtCol Chiaramonte
 * Project: MineSweeper - Final Project
 * ==============================================================
*/

#ifndef MINESWEEPER_OTHER_H
#define MINESWEEPER_OTHER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define X_DIM 8     //can be adjusted based on desired level of play
#define Y_DIM 8
#define NUM_MINES 10

typedef struct GameElement_struct {
    int isMine;
    int isFlagged;
    int isCleared;
    int amountTouching;
}GameElement;

#endif //MINESWEEPER_OTHER_H
