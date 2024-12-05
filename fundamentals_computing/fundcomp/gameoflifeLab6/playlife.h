#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
# define BOARDSIZE 40

void makeBoard(char array[][BOARDSIZE]);
void printMenu();
void nextIteration(char [][BOARDSIZE]);
void interactiveMode(char [][BOARDSIZE]);
void playContinuously(char [][BOARDSIZE]);
