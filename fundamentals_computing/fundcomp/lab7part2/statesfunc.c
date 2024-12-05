//Mary Briamonte statesfunc.c

#include "statesfunc.h"

//function to read values from file and update list
int readValues(char filename[], State stateList[]){
  
  FILE *fp = fopen(filename, "r");
  if(!fp){
    printf("file %s is not found");
    exit(1);
  }
  
  char theline[MAXNAME];
  int index = 0;
  while(1){

    fgets(theline, MAXNAME, fp);
    if(feof(fp))break;
   
    char * temp;
    temp = strtok(theline, ",");
    strcpy(stateList[index].abbreviation, temp);
    strcpy(stateList[index].name, strtok(NULL, ","));
    strcpy(stateList[index].capital, strtok(NULL, ","));
    stateList[index].year = atoi(strtok(NULL, "\n"));
    index++;
  }

  return index;
}

void displayMenu(int count, State stateList[]){

  int choice = 0;

  printf("Menu:\n");
  printf("1: list all the data\n");
  printf("2: list a state's info based on its abbreviation\n");
  printf("3: list a state's name based on its capital\n");
  printf("4: list states who joined in a given year\n");
  printf("5: quit\n");

  printf("please chose an option: ");
  scanf("%d", &choice);

  while(choice != 5){

    if(choice == 1){
      getData(count, stateList);
    }
    else if(choice == 2){
      getStateInfo(count, stateList);
    }
    else if(choice == 3){
      getState(count, stateList);
    }
    else if(choice == 4){
      getStatesByYear(count, stateList);
    }
    else{
      printf("not an option");
    }
    printf("\n");
    printf("Menu:\n");
    printf("1: list all the data\n");
    printf("2: list a state's info based on its abbreviation\n");
    printf("3: list a state's name based on its capital\n");
    printf("4: list states who joined in a given year\n");
    printf("5: quit\n");
    printf("please chose an option: ");
    scanf("%d", &choice);
  }

}

void getData(int count, State stateList[]){

  for(int i = 0; i < count; i++){
    printf("Abbreviation: %s\n", stateList[i].abbreviation);
    printf("Name: %s\n", stateList[i].name);
    printf("Capital: %s\n", stateList[i].capital);
    printf("Year Joined: %d\n", stateList[i].year);
    printf("\n\n");
  }
}

void getStateInfo(int count, State stateList[]){
  char abb[10];
  printf("please enter an abbreviation:\n");
  scanf("%s", &abb);

  for(int i = 0; i < count; i++){
    int result = strcmp(abb, stateList[i].abbreviation);
    if(result == 0){
      printf("Name: %s\n", stateList[i].name);
      printf("Capital: %s\n", stateList[i].capital);
      printf("Year Joined: %d\n", stateList[i].year);
    }
  }
}

void getState(int count, State stateList[]){
  char temp[MAXNAME];
  printf("plesae enter a capital:\n");
  getchar();
  fgets(temp, MAXNAME, stdin);
  temp[strlen(temp)-1] = '\0';
  printf("%s", temp);

  for(int i = 0; i < count; i++){
    int result = strcmp(temp, stateList[i].capital);
    if(result == 0){
      printf("\n");
      printf("State:");
      printf("%s\n", stateList[i].name);
    }
  }
}
//list of states joined before or on given year
void getStatesByYear(int count, State stateList[]){
  int inputYear;
  printf("please enter a year:\n");
  scanf("%d", &inputYear);
  
  printf("States that joined before or during %d:\n", inputYear);
  for(int i = 0; i < count; i++){
    if(stateList[i].year <= inputYear){
      printf("%s\n", stateList[i].name);
    }
  }
}

