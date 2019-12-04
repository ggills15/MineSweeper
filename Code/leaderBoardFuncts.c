/** leaderBoardFuncts.c
 * ==============================================================
 * Name: Grady Gills, 12/05/2019
 * Section: M6/7 LtCol Chiaramonte
 * Project: MineSweeper - Final Project
 * ==============================================================
*/

#include "leaderBoardFuncts.h"

void printLeaderBoard() {
    FILE* fp = fopen("leaderboard.txt", "r");
    if(fp == NULL)
        printf("Failed to open file.....\n");

    char line[100];
    fgets

    fclose(fp);
}