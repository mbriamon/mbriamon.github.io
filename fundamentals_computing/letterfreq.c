//Mary Briamonte Fund Comp Lab 5 Part 1
//Justifying Scrabble's Letter point values

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void getCounts(int [], int);
void getPercents(int[], float, int);

int main(){

  int numbers[26] = {0};

  char filename[30];
  printf("enter file name: ");
  scanf("%s", &filename);
  
  FILE * fp = fopen(filename, "r");
  if(!fp){
    printf("file %s not found\n", filename);
    return 1;
  }
  
  char letter;
  int charactertotal = 0;
  float lettercount = 0;

  while(1){
    letter = fgetc(fp);
    if(feof (fp)){
      break;
    }
    if(isalpha(letter)){
      letter = tolower(letter);
      lettercount++;
      numbers[letter - 'a']++;
    }
    charactertotal++;
  }

  printf("general summary for %s:\n", filename);
  printf("there are %d total characters\n", charactertotal);
  printf("there are %0lf total letters\n", lettercount);

  int size = sizeof(numbers) / sizeof(int);

  getCounts(numbers, size);
  getPercents(numbers, lettercount, size);

  return 0;
}

void getCounts(int numbers[], int s){
//counts
  int charcount = 97;
  printf("\nletter counts:\n");
  for(int i = 0; i < s; i++){
    if(i % 6 == 0){
      printf("\n");
    }
    printf("%6c : %6d", charcount, numbers[i]);
    charcount++;
  }
  printf("\n");
}

void getPercents(int numbers[], float count, int s){
//get percents
  int charcount = 97;
  float rate = 0;
  for(int i = 0; i < s; i++){
    if( i % 6 == 0){
      printf("\n");
    }
    rate = (numbers[i] / count) * 100;
    printf("%6c : %6.1f %%", charcount, rate);
    charcount++;
  }
  printf("\n");
}
