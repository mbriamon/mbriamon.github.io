//Mary Briamonte Fund Comp Lab 4: Part 3
//ND Football: provide the user with a menu of questions on the data and return answeres

#include <stdio.h>

//function prototypes
int getChoice();
void getRecord();
void getLosses();
void getWins();
void mostWins();


  int wins[] = { 6, 8, 6, 8, 5, 5, 6, 6, 8, 7, 4, 6,
     7, 7, 6, 7, 8, 6, 3, 9, 9, 10, 8, 9,
     10, 7, 9, 7, 5, 9, 10, 6, 6, 3, 6, 7, 
     6, 6, 8, 7, 7, 8, 7, 9, 8, 7, 8, 9,
     9, 10, 4, 7, 7, 9, 9, 8, 2, 7, 6, 5, 
     2, 5, 5, 2, 9, 7, 9, 8, 7, 8, 10, 8, 
     8, 11, 10, 8, 9, 11, 9, 7, 9, 5, 6, 7, 
     7, 5, 5, 8, 12, 12, 9, 10, 10, 11, 6, 9, 
     8, 7, 9, 5, 9, 5, 10, 5, 6, 9, 10, 3, 
     7, 6, 8, 8, 12, 9, 8, 10, 4, 10, 12, 11, 
     10, 11, 9 };

  int losses[] =  { 3, 1, 2, 0, 3, 4, 1, 0, 1, 0, 1, 0,
    0, 0, 2, 1, 1, 1, 1, 0, 0, 1, 1, 1,
    0, 2, 1, 1, 4, 0, 0, 2, 2, 5, 3, 1,
    2, 2, 1, 2, 2, 0, 2, 1, 2, 2, 0, 0,
    0, 0, 4, 2, 2, 0, 1, 2, 8, 3, 4, 5,
    8, 5, 5, 7, 1, 2, 0, 2, 2, 2, 1, 2,
    3, 0, 2, 3, 3, 1, 3, 4, 2, 6, 4, 5,
    5, 6, 6, 4, 0, 1, 3, 3, 1, 1, 5, 3,
    3, 6, 3, 7, 3, 6, 3, 7, 6, 3, 3, 9,
    6, 6, 5, 5, 1, 4, 5, 3, 8, 3, 1, 2,
    2, 2, 4 };

int main() {  
  int x = getChoice();
  while(x != 6){
    if(x == 1){
      getRecord(wins, losses);
    }
    else if(x == 2){
      getLosses(losses);
    }  
    else if(x == 3){
      getWins(wins);
    }  
    else if(x == 4){
      mostWins(wins);
    }
    else{
      printf("Good Bye!\n");
      break;
    }
    printf("\n");
    x = getChoice();
  }
  

  return 0;

}
//gives menu and returns choice
int getChoice(){
  int choice;
  printf("\n");
  printf("1: display the record for a given year.\n");
  printf("2: display years with at least n looses.\n");
  printf("3: display years with at least n wins.\n");
  printf("4: exit\n");

  printf("Enter your choice: ");
  scanf("%d", &choice);

  return choice;

}
//gets record 
void getRecord(){
  int year;
  printf("Enter the year: ");
  scanf("%d", &year);

  int index = year - 1900;

  int win = wins[index];
  int loss = losses[index];

  printf("Wins: %d, Losses: %d\n", win, loss);

}

//gets number of losses from minimum
void getLosses(){
  int min;
  printf("Enter minimum number of losses: ");
  scanf("%d", &min);
 
  int numLoss = 0;

  int length = sizeof(losses) / sizeof(int);

  printf("Years with at least %d losses: ", min);
  for(int i = 0; i < length; i++){
    if(losses[i] >= min){
      numLoss = i + 1900;
      printf("%d ", numLoss);
    }
  }
}
//gets number of wins from minimum
void getWins(){
  int min;
  printf("Enter minimum number of wins: ");
  scanf("%d", &min);

  int length = sizeof(wins) / sizeof(int);
 
    int numWin = 0;
  
  printf("Years with at least %d wins: ", min);
  for(int i = 0; i < length; i++){
    if(wins[i] >= min){
      numWin = i + 1900;
      printf("%d ", numWin);
    }
  }
}
//get the years with the most wins
void mostWins(){
  int length = sizeof(wins) / sizeof(wins[0]);
  int year = 0;
  int most = 0;

  for(int i = 0; i < length; i++){
    if(wins[i] > most){
      most = wins[i];
    }
  }
  for(int i = 0; i < length; i++){
    if(wins[i] == most){
      year = i + 1900;
      printf("%d ", year);
    }
  }
  printf("\nThese years have the most wins: %d ", most);
}