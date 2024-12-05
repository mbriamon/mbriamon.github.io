//Mary Briamonte statesfunc.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNAME 50

typedef struct{
  char abbreviation[5];
  char name[MAXNAME];
  char capital[MAXNAME];
  int year;
} State;

int readValues(char[], State[]);
void displayMenu(int, State[]);
void getData(int, State[]);
void getStateInfo(int, State[]);
void getState(int, State[]);
void getStatesByYear(int, State[]);
