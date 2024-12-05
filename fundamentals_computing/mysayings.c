#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 256

void displayMenu(char[][MAX], int);
void displayAll(char[][MAX], int);
int addSaying(char[][MAX], int);
void getString(char[][MAX], int);
void newFile(char[][MAX], int);


int main(){
  FILE *fp;
  char infile[30];
  printf("enter a file name: ");
  scanf("%s", infile);

  fp = fopen(infile, "r");
  if(!fp){
    printf("file %s is not found", fp);
    return 1;
  }
  
  char sayings[50][MAX];
  int index = 0;
  char saying[MAX];
  int newLine_count = 0;
  while(1){
    fgets(saying, MAX, fp);
    if(feof(fp)) break;
    strcpy(sayings[index], saying);
    index++;
    newLine_count++;
  }

  displayMenu(sayings, newLine_count);

  return 0;
}

//displays menu
void displayMenu(char arr[][MAX], int size){
  
  int choice = 0;
  
  while(1){
    printf("1 : display all sayings currently in the database\n");
    printf("2 : enter a new saying into the database\n");
    printf("3 : list sayings that contain a given string entered by the user\n");
    printf("4 : save all sayings in a new text file\n");
    printf("5 : quit the program\n");
    
    printf("enter your choice: ");
    scanf("%d", &choice);
    if( choice < 1 || choice > 5){
      printf("Invalid input. Please enter a new number.\n");
    }
    else if( choice == 1){
      displayAll(arr, size);
    }
    else if( choice == 2){
      size = addSaying(arr, size);
    }
    else if( choice == 3){
      getString(arr, size);
    }
    else if( choice == 4){
      newFile(arr, size);
    }
    else{
      printf("Goodbye.\n");
      break;
    }
  }
}

//displays all sayings currently in the database
void displayAll(char arr[][MAX], int size){
  for(int i = 0; i < size; i++){
    printf("%s\n", arr[i]);
  }

}

//enters a new saying into the database
int addSaying(char arr[][MAX], int size){
  char string1[MAX];
  printf("enter a new saying: ");
  getchar();

  fgets(string1, MAX, stdin);
  strcpy(arr[size], string1);
  size = size + 1;
  return size;
}

//list sayings that contain a given string entered by the user
void getString(char arr[][MAX], int size){
  char searchstring[MAX];
  printf("enter a string: ");
  scanf("%s", searchstring);

  int c = getchar();
  for(int i = 0; i < size; i++){
    if(strstr(arr[i], searchstring)){
      printf("%s", arr[i]);
    }
  }
}

//save all sayings in a new text file = print new file name
void newFile(char arr[][MAX], int size){
  FILE *fp;
  char infile[MAX];

  int c = getchar();
  printf("enter a file name: ");
  scanf("%s", infile);

  fp = fopen(infile, "w");
  int count = 0; 

  //
  for(int i = 0; i < size; i++){
    fputs(arr[i], fp);
  }
  printf("New file has been created with all your sayings.");
  fclose(fp);

}
