#include "playlife.h"
//function to create board
void makeBoard(char array[][BOARDSIZE]){
  printf("+");
  for(int i = 0; i < BOARDSIZE; i++){
    printf("-");
  }
  printf("+");
  printf("\n");
  for(int i = 0; i < BOARDSIZE; i++){
    printf("|");
    for(int j = 0; j < BOARDSIZE; j++){
      printf("%c", array[i][j]);
    }
    printf("|");
    printf("\n");
  }
  printf("+");
  for(int i = 0; i < BOARDSIZE; i++){
    printf("-");
  }
  printf("+\n");

}

//print Menu
void printMenu(){
  printf("a: add new live cell\n");
  printf("r: remove cell\n");
  printf("n: advance to next iteration\n");
  printf("q: quit\n");
  printf("p: play the game continuously\n");
}

//interactive mode
void interactiveMode(char array[][BOARDSIZE]){
  char command = ' ';
  int row = 0;
  int column = 0;
while(1){
  printf("\n");
  printMenu();
  printf("enter input: ");
  scanf("%c", &command);

  if( command == 'a'){
    scanf("%d %d", &row, &column);
    array[row][column] = 'X';
  }
  else if ( command == 'r'){
    scanf("%d %d", &row, &column);
    array[row][column] = ' ';
  }
  else if ( command == 'n'){
    nextIteration(array);
  }
  else if ( command == 'q'){
    return;
  }
  else if ( command == 'p'){
    playContinuously(array);
  }
  else{
    printf("enter new command.\n");
  }
  makeBoard(array);
  getchar();
  }
}

//next iteration
void nextIteration(char array[][BOARDSIZE]){
  int count = 0;
  char temp[BOARDSIZE][BOARDSIZE]; 
  for(int i = 0; i < BOARDSIZE; i++){
    for(int j = 0; j < BOARDSIZE; j++){
      if(array[i-1][j] == 'X'){
        count++;
      }
      if( array[i+1][j] == 'X'){
        count++;
      }
      if ( array[i][j-1] == 'X'){
        count++;
      }
      if ( array[i][j+1] == 'X'){
        count++;
      }
      if(array[i-1][j-1] == 'X'){
        count++;
      }
      if(array[i+1][j+1] == 'X'){
        count++;
      }
      if(array[i-1][j+1] == 'X'){
        count++;
      }
      if(array[i+1][j-1] == 'X'){
        count++;
      }

      if(array[i][j] == ' '){
        if( count == 3){
          temp[i][j] = 'X';
        }
	else{
	  temp[i][j] = ' ';
	}
      }
      else{
        if( count == 0 || count == 1 || count >= 4){
          temp[i][j] = ' ';
        }
	else{
	  temp[i][j] = 'X';
	}
      }
      count = 0;
    }
  }
  for(int i = 0; i < BOARDSIZE; i++){
    for(int j = 0; j < BOARDSIZE; j++){
      array[i][j] = temp[i][j];
    }
  }
}


//add cell
void addCell(char arr[][BOARDSIZE], int row, int column) {
  if( row < 0 || row > 40){
    printf("Row out of bounds.");
  }
  else if( column < 0 || row > 40){
    printf("column out of bounds.");
  }
  else{
    arr[row][column] = 'X';
  }
}

//continuous play
void playContinuously(char array[][BOARDSIZE]){
  while(1){
    system("clear");
    nextIteration(array);
    makeBoard(array);
    usleep(100000);
  }
}

