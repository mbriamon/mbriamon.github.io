#define _GNU_SOURCE
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXWORD 15
#define MAXWORDS 20 

typedef struct{
  char word[MAXWORD];
  int x;
  int y;
  bool direction; //true = down, false = across
  bool used; // true = used, false default
  char clue[MAXWORD];
} WORD;

void readfile();
void makePuzzle(char [][MAXWORD]);
void makeSolution(char [][MAXWORD]);
void to_upper(char *word);
int getWords(WORD []);
int readFile(char [MAXWORD], WORD []);
void lengthOrder(WORD [MAXWORDS], int);
void placeFirst(WORD [MAXWORDS], char [MAXWORDS][MAXWORD]);
void shuffleWords(WORD [MAXWORDS], int, WORD [MAXWORDS]);
int placeWords(WORD [MAXWORDS], int, WORD [MAXWORDS], char [][MAXWORD]);
int checkAround(int, int, char [][MAXWORD]);
void fileMakePuzzle(char [][MAXWORD], FILE *fp);
void fileMakeSolution(char [][MAXWORD], FILE *fp);
void toFile(WORD [MAXWORDS],  WORD [MAXWORDS],WORD [MAXWORDS], char [MAXWORDS][MAXWORD], char [MAXWORD], char [MAXWORD]);
void placeWordsFile(WORD [MAXWORDS], int, WORD [MAXWORDS], char [MAXWORDS][MAXWORD], FILE *fp);
void shuffleWordsFile(WORD [MAXWORDS], int, WORD [MAXWORDS], FILE *fp);
void placeFirstFile(WORD [MAXWORDS], char [MAXWORDS][MAXWORD], FILE *fp);
void runThru(WORD [MAXWORDS], char [MAXWORDS][MAXWORD]);
void goBack(char [MAXWORD], char [MAXWORDS][MAXWORD]);
