//
// Created by C22Grady.Gills on 11/5/2019.
//

#include "gameFuncts.h"


void printGame(GameElement game[][]) {
    for(int i = 0; i < X_DIM; ++i) {
        for(int j = 0; j < Y_DIM; ++j) {
            printf("| ");
            if(!game[i][j].isCleared)
                printf("|_| ");
            else if(game[i][j].isFlagged)
                printf("|!| ");
            else
                printf("|%d| ", game[i][j].amountTouching);
            printf("|\n");
        }
    }
}