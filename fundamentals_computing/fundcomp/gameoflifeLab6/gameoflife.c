#include "playlife.h"

int main(int argc, char *argv[]){

//create board
  char arr[40][40];
  for(int i = 0; i < BOARDSIZE; i++){
    for(int j = 0; j < BOARDSIZE; j++){
      arr[i][j] = ' ';
    }
  }
  
  makeBoard(arr);

  if( argc == 1){
    //interactive mode
    interactiveMode(arr);
  }
  else if( argc == 2){
    //batch mode
    
  FILE *fp;
  fp = fopen(argv[1], "r");
  char command;
  int row;
  int column;
  if(!fp){
    printf("file %s is not found", argv[1]);
    exit(1);
  }
  while(!feof(fp)){
  fscanf(fp, "%s", &command);
  if( command == 'a'){
    fscanf(fp, "%d %d", &row, &column);
    arr[row][column] = 'X';
  }

  else if ( command == 'p'){
    playContinuously(arr);
  }
  makeBoard(arr);
}

  }
  else{
    printf("Error. Two many arguments.");
  }


  return 0;
}

