//Mary Briamonte crossword.c
#include "crosswordfunc.h"

int main(int argc, char *argv[]){

  WORD words[MAXWORDS];

  char puzzle[MAXWORD][MAXWORD];
  for(int i = 0; i < MAXWORD; i++){
    for(int j = 0; j <MAXWORD; j++){
      puzzle[i][j] = '#';
    }
  }
  char solution[MAXWORD][MAXWORD];
  for(int i = 0; i < MAXWORD; i++){
    for(int j = 0; j <MAXWORD; j++){
      solution[i][j] = '.';
    }
  }

  WORD clues[MAXWORDS];
  WORD notPlaced[MAXWORDS];

  //printf("%s\n", argv[1]);
  int numWords;
  if( argc == 1){
    //interactive mode
    numWords = getWords(words);
    lengthOrder(words, numWords);
    placeFirst(words, solution);
    shuffleWords(clues, numWords, words);

    int noHome = placeWords(words, numWords, notPlaced, solution);
    noHome++;
    printf("\nCrossword Puzzle: \n");
    makePuzzle(solution);
    printf("\nSolution:\n");
    makeSolution(solution);

    printf("\nClues:\n");
    for(int i = 0; i < numWords; i++){
      if(words[i].x == -1){
        continue;
      }
      printf("%d, %d\t", words[i].x, words[i].y);
      if(words[i].direction == true){
        printf("Down\t");
      }
      else{
        printf("Across\t");
      }
      printf("%s\n", words[i].clue);
    } 
    int num = 0;
    printf("\nthese words could not be placed: \n");
    for(int i = 0; i < numWords; i++){
      if(words[i].x == -1){
        printf("%s\n", words[i].word);
	num++;
      }
    }

  }

  else if( argc == 2){
    //command line input to standard output
    numWords = readFile(argv[1], words);

    lengthOrder(words, numWords);
    placeFirst(words, solution);
    shuffleWords(clues, numWords, words);

    int noHome = placeWords(words, numWords, notPlaced, solution);
    noHome++;
    printf("\nCrossword Puzzle: \n");
    makePuzzle(solution);
    printf("\nSolution:\n");
    makeSolution(solution);

    printf("\nClues:\n");
    for(int i = 0; i < numWords; i++){
      if(words[i].x == -1){
        continue;
      }
      printf("%d, %d\t", words[i].x, words[i].y);
      if(words[i].direction == true){
        printf("Down\t");
      }
      else{
        printf("Across\t");
      }
      printf("%s\n", words[i].clue);
    } 
    printf("\nthese words could not be placed: \n");
    int num = 0;
    for(int i = 0; i < numWords; i++){
      if(words[i].x == -1){
        printf("%s\n", words[i].word);
	num++;
      }
    }


  }

  else if( argc == 3){
    //command line input to file output

    numWords = readFile(argv[1], words);
    lengthOrder(words, numWords);
    placeFirst(words, solution);
    shuffleWords(clues, numWords, words);

    FILE *fp;
    fp = fopen(argv[2], "w");

    int noHome = placeWords(words, numWords, notPlaced, solution);
    noHome++;
    fprintf(fp, "\nCrossword Puzzle: \n");
    fileMakePuzzle(solution, fp);
    fprintf(fp, "\nSolution:\n");
    fileMakeSolution(solution, fp);

    fprintf(fp, "\nClues:\n");
    for(int i = 0; i < numWords; i++){
      if(words[i].x == -1){
        continue;
      }
      fprintf(fp, "%d, %d\t", words[i].x, words[i].y);
      if(words[i].direction == true){
        fprintf(fp, "Down\t");
      }
      else{
        fprintf(fp, "Across\t");
      }
      fprintf(fp, "%s\n", words[i].clue);
    } 
    fprintf(fp, "\nthese words could not be placed: \n");
    int num = 0;
    for(int i = 0; i < numWords; i++){
      if(words[i].x == -1){
        fprintf(fp, "%s\n", words[i].word);
	num++;
      }
    }

  }

  return 0;
}

