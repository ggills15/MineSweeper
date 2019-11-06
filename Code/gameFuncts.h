//
// Created by C22Grady.Gills on 11/5/2019.
//

#ifndef MINESWEEPER_GAMEFUNCTS_H
#define MINESWEEPER_GAMEFUNCTS_H

#include <stdio.h>
#include <stdlib.h>

const int X_DIM = 8;
const int Y_DIM = 8;
const int NUM_MINES = 10;

typedef struct GameElement_struct {
   // int x;
    //int y;
    int isMine;
    int isFlagged;
    int isCleared;
    int amountTouching;
}GameElement;


#endif //MINESWEEPER_GAMEFUNCTS_H
