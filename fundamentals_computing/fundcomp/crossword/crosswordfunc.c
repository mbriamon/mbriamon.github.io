#include "crosswordfunc.h"

//create puzzle board
void makePuzzle(char puzzle[][MAXWORD]){
  printf("+");
  for(int i = 0; i < MAXWORD; i++){
    printf("-");
  }
  printf("+");
  printf("\n");
  for(int i = 0; i < MAXWORD; i++){
    printf("|");
    for(int j = 0; j < MAXWORD; j++){
      if((puzzle[i][j]) != '.'){
        printf(" ");
      }
      else{
        printf("#");
      }
    }
    printf("|");
    printf("\n");
  }
  printf("+");
  for(int i = 0; i < MAXWORD; i++){
    printf("-");
  }
  printf("+\n");
}

//create solution board
void makeSolution(char solution[][MAXWORD]){
  printf("+");
  for(int i = 0; i < MAXWORD; i++){
    printf("-");
  }
  printf("+");
  printf("\n");
  for(int i = 0; i < MAXWORD; i++){
    printf("|");
    for(int j = 0; j < MAXWORD; j++){
      printf("%c", solution[i][j]);
    }
    printf("|");
    printf("\n");
  }
  printf("+");
  for(int i = 0; i < MAXWORD; i++){
    printf("-");
  }
  printf("+\n");
}

void to_upper(char *word){
  for(int i = 0; i <strlen(word); i++){
    word[i] = toupper(word[i]);
    //printf("%c", word[i]);
  }
  //printf("\n");
}

//read in word from user for interactive mode
int getWords(WORD words[MAXWORDS]){
  printf("\nAnagram Crosword Puzzle Generator\n----------------------------------\n");
  char word[MAXWORD];
  int index = 0;
  bool too_long = false;
  printf("\nplease enter a list of words:\n");
  while(index < MAXWORDS){
    too_long = false;
    fgets(word, MAXWORD, stdin);
    if(word[strlen(word)-1] != '\n'){
      too_long = true;
      printf("sorry but this word is too long\n");
    }
    word[strlen(word)-1] = '\0';

    if(strcmp(word, ".") == 0){
      break;
    }
    
    if(strlen(word) <2){
      printf("sorry but this word is too short\n");
    }
    int allLetters = 0; 
    if(strlen(word) >= 2 && too_long == false){
      //make sure that all letters
      for(int i = 0; i <strlen(word); i++){
        if(isalpha(word[i]) == 0){
	  allLetters = 1;
	}
      }
      if(allLetters != 1){
        strcpy(words[index].word, word);
	to_upper(words[index].word);
	words[index].x = -1;
	words[index].y = -1;
	words[index].direction = true;
	words[index].used = false;
	index++;
      }
      else{
        printf("sorry but characters under than letters are in this word\n");
      }
    }
  }
  printf("\n");

  return index;
}

void lengthOrder(WORD words[MAXWORDS], int numWords){
  char temp[MAXWORD];
  for(int i = 0; i < (numWords-1); i++){
    for(int j = 0; j < (numWords-i-1); j++){
      if(strlen(words[j].word) < strlen(words[j+1].word)){
        strcpy(temp, words[j].word);
	strcpy(words[j].word, words[j+1].word);
	strcpy(words[j+1].word, temp);
        
      }
    }
  }
}

int readFile(char filename[MAXWORDS], WORD words[MAXWORDS]){
  FILE *fp = fopen(filename, "r");
  int index = 0;
  //int wordcount = 0;
 // char words[MAXWORDS][MAXWORD];
  char word[MAXWORD];
  while(1){
    bool too_long = false;
    fgets(word, MAXWORD, fp);
    if(feof(fp)) break;
    else{
     // fgets(word, MAXWORD, fp);
      if(word[strlen(word)-1] != '\n'){
        too_long = true;
        printf("%s: sorry but this word is too long\n", word);
      }
      word[strlen(word)-1] = '\0';

      if(strcmp(word, ".") == 0){
        break;
      }
    
      if(strlen(word) <2){
        printf("%s: sorry but this word is too short\n", word);
      }
    
      if(strlen(word) >= 2 && too_long == false){
        int allLetters = 0;
        //make sure that all letters
        for(int i = 0; i <strlen(word); i++){
          if(isalpha(word[i]) == 0){
	    allLetters = 1;
	  }
        }

      if(allLetters != 1){
        strcpy(words[index].word, word);
	to_upper(words[index].word);
	words[index].x = -1;
	words[index].y = -1;
	words[index].direction = true;
	words[index].used = false;
	//words[index].clue = "emtpy";
	index++;
      }

        else{
          printf("%s: sorry but characters under than letters are in this word\n", word);
        } 
      }
      //index = 0;
    }
    if(index == 20){
      break;
    }
  }

  return index;
}

void placeFirst(WORD words[MAXWORDS], char solution[MAXWORDS][MAXWORD]){
  int length = strlen(words[0].word);
  int compare = (MAXWORD - length) / 2;

  int row = 7;
  words[0].x = 7;
  words[0].y = compare;
  words[0].direction = false;
  words[0].used = true;
  int column = compare;
  int index = 0;
  for(int i = 0; i < length; i++){
    solution[row][column] = words[0].word[index];
    column++;
    index++;
  }
  //makePuzzle(solution);
  //makeSolution(solution);
}

void shuffleWords(WORD clues[MAXWORDS], int numWords, WORD words[MAXWORDS]){
  char temp[MAXWORD];
  for(int i = 0; i < numWords; i++){
    strcpy(temp, words[i].word);
    strfry(temp);
    strcpy(clues[i].word, temp);
    strcpy(words[i].clue, temp);
    //printf("%s\n", words[i].word);
  }
}


//displays clues function







int placeWords(WORD words[MAXWORDS], int numWords, WORD notPlaced[MAXWORDS], char solution[MAXWORDS][MAXWORD]){
 

  int noHome = 0;
  int direction = 0; //0 = vertical, 1 = horizontal, true = vertical, false = horizontal

  for(int word2 = 1; word2 < numWords; word2++){
    int length2 = strlen(words[word2].word);
    if(words[word2].used == true){
      continue;
    }
    else{
      for(int word1 = 0; word1 < numWords; word1++){
        int length1 = strlen(words[word1].word);
	if(words[word1].used == false){
	  continue;
	}
	else{
          for(int letter = 0; letter < length1; letter++){
          char letter1 = words[word1].word[letter];
            for(int index = 0; index < length2; index++){
              char letter2 = words[word2].word[index];
	      if(words[word2].used == true){
                continue;
	      }
	      if(letter1 == letter2){
	        //printf("found match in %s, %s, %c\n", words[word1].word, words[word2].word, letter2);

	        int count = 0;
	        for(int og = 0; og < length1; og++){
	          if(letter1 == words[word1].word[og]){
	            break;
	          }
	          count++;
	        }
	        //result = -1;
	        int row = words[word1].x;
	        int column = words[word1].y;

	        int x_compare = words[word1].x;
	        int y_compare = words[word1].y;

	        //printf("x: %d\n", x_compare);
	        //printf("y: %d\n", y_compare);

	        if(words[word1].direction == true){
	    
	          x_compare += count;
	        }
	        else{
	          y_compare += count;
		  y_compare = y_compare-1;
	        }
	        //printf("x: %d\n", x_compare);
	        //printf("y: %d\n", y_compare);

	        //CHECKS
	        if(words[word1].direction == true){
	          direction = 1;
	          if(solution[x_compare][y_compare+1] != '.'){
	            //printf("check 1\n");
		    continue;
		      strcpy(notPlaced[noHome].word, words[word2].word);
		      noHome++;
	          }
	          if(solution[x_compare][y_compare-1] != '.'){
	            //printf("check 2\n");
		    continue;
		      strcpy(notPlaced[noHome].word, words[word2].word);
		      noHome++;
	          }
	          if(solution[x_compare+1][y_compare+1] != '.'){
	            //printf("check 3\n");
		    continue;
		      strcpy(notPlaced[noHome].word, words[word2].word);
		      noHome++;
	          }
	          if(solution[x_compare-1][y_compare-1] != '.'){
	            //printf("check 4\n");
		    continue;
		      strcpy(notPlaced[noHome].word, words[word2].word);
		      noHome++;
	          }
	          if(solution[x_compare+1][y_compare-1] != '.'){
	            //printf("check 5\n");
		    continue;
		      strcpy(notPlaced[noHome].word, words[word2].word);
		      noHome++;
	          }
	          if(solution[x_compare-1][y_compare+1] != '.'){
	            //printf("check 6\n");
		    continue;
		      strcpy(notPlaced[noHome].word, words[word2].word);
		      noHome++;
	          }
	        }
	        else{
	          direction = 0;
	          if(solution[x_compare+1][y_compare] != '.'){
	            //printf("check 7\n");
		    continue;
		      strcpy(notPlaced[noHome].word, words[word2].word);
		      noHome++;
	          }
	          if(solution[x_compare-1][y_compare] != '.'){
	            //printf("check 8\n");
		    continue;
		      strcpy(notPlaced[noHome].word, words[word2].word);
		      noHome++;
	          }
	          if(solution[x_compare+1][y_compare+1] != '.'){
	            //printf("check 9\n");
		    continue; 
		    strcpy(notPlaced[noHome].word, words[word2].word);
		      noHome++;
	          }
	          if(solution[x_compare-1][y_compare-1] != '.'){
	            //printf("check 10\n");
		    continue;
		      strcpy(notPlaced[noHome].word, words[word2].word);
		      noHome++;
	          }
	          if(solution[x_compare+1][y_compare-1] != '.'){
	            //printf("check 11\n");
		    continue;
		      strcpy(notPlaced[noHome].word, words[word2].word);
		      noHome++;
	          }
	          if(solution[x_compare-1][y_compare+1] != '.'){
	            //printf("check 12\n");
		    continue;
		      strcpy(notPlaced[noHome].word, words[word2].word);
		      noHome++;
	          }
	        }    
                //place word
                if(direction == 0){

                  int cOL = words[word1].y + count;
	          column = column + word1; //column stays constant
	          //printf("index: %d\n", index);
	          int rowstart = row - index + 1 ;
	          int x = length2 - index;
	          int rowend = row + x;
	          int temp = index - 1 ;
	          int row1 = words[word1].x;
	          if(rowstart-1 < 0){
	            //printf("check 13\n");
		    continue;
	          }
	          if( rowend > 14){
	            //printf("check 14\n");
		    continue;
	          }

                  int try = words[word1].x - (length2-index-1);
		  //int top = length2 - index - 1;
                  int counter = 0;
	          int stop = 0;
		  int stop1 = 0;
	          for(int h = try; h < rowend+1; h++){
	            if(solution[h][cOL] != '.'){
                      if(solution[h][cOL] != words[word2].word[counter]){	  
		      strcpy(notPlaced[noHome].word, words[word2].word);
		      noHome++;
		      //printf("%s could not be placed\n", words[word2].word);
		      stop++;
		      }   
	            }
		    
		    if(solution[h][cOL+1] != '.'){
		      stop1++;
		    }
		    if(solution[h][cOL-1] != '.'){
		      stop1++;
		    }
		    
	            counter++;
	          }
	          if(stop > 1){
		    //printf("check 15\n");
	            continue;
	          }
		  
		  if(stop1 > 2){
		    continue;
		  }
		  

	          for(int rowplace = row1; rowplace < rowend; rowplace++){
	            //printf("row: %d\n", rowplace);
                    if(index == 0 ){
		      solution[rowplace][cOL] = words[word2].word[temp+1];
	            }
	            else{
	              solution[rowplace][cOL] = words[word2].word[temp+1];
	            }
	            temp++;
	          }
	          //printf("count: %d\n", count);
	          for(int j = index-1; j >= 0; j--){
	            solution[row1-1][cOL] = words[word2].word[j];
	            row1--;
	          
		  }

		  //makePuzzle(solution);
		  //makeSolution(solution);

		  words[word2].x = rowstart-1;
		  words[word2].y = cOL;
		  words[word2].direction = true;
		  words[word2].used = true;
	        }

                else{
	          int rOW = words[word1].x + count;
	          row = row + word1 -1 ; //row stays constant
	          int temp = index - 1;
	          int colstart = column - index;
	          int x = length2 - index;
	          int colend = column + x;
	          int col1 = words[word1].y;
	          if(colstart < 0){
	            //printf("check 16\n");
		    continue;
	          }
	          if(colend > 14){
	            //printf("check 17\n");
		    continue;
	          }

                  int try = words[word1].y - length2;
		  int stop = 0;
                  int top = length2 - index + 1;
                  int counter = 0;
	          for(int h = try; h < colend+2; h++){
	            if(solution[rOW][h] != '.'){
                      if(solution[rOW][h] != words[word2].word[counter]){	  
		        strcpy(notPlaced[noHome].word, words[word2].word);
			//printf("%s could not be placed\n", words[word2].word);
		        noHome++;
		        stop++;
		      }
	            }
	            counter++;
	          }
	          if(stop > 1){
	            //printf("check 18\n");
		    continue;
	          }


	          for(int colplace = col1; colplace < colend; colplace++){
	            if(index == 0){
	              solution[rOW][colplace] = words[word2].word[temp+1];
	            }
	            else{
	              solution[rOW][colplace] = words[word2].word[temp+1];
                    }
	            temp++;
	          }
	          for(int j = index -1 ; j >= 0; j--){
                    solution[rOW][col1-1] = words[word2].word[j];
	            col1--;
	          }
	          //makePuzzle(solution);
	          //makeSolution(solution);

	          words[word2].x = rOW;
	          words[word2].y = colstart;
	          words[word2].direction = false;
	          words[word2].used = true;

	        }

	      }
            }
          }
	}
      }
    }
  }
  //makePuzzle(solution);
  //makeSolution(solution);
  return noHome;
}
/*
void tryAgain(char solution[][MAXWORD], WORD notPlaced[MAXWORD], int num){

  for(int word2 = 0; word2 < num; word2++){
    int length = strlen(notPlaced[word2].word);
    for(int letter = 0; letter < length; letter++){
      for(int i = 0; i < MAXWORD; i++){
        for(int j = 0; j < MAXWORD; j++){
          if(notPlaced[word2].word[letter] == solution[i][j]){
            


	  }

	}

      }

    }

  }

}

*/
void fileMakePuzzle(char puzzle[][MAXWORD], FILE *fp){
  
  fputs("+",fp);
  for(int i = 0; i < MAXWORD; i++){
    fputs("-",fp);
  }
  fputs("+",fp);
  fputs("\n", fp);
  for(int i = 0; i < MAXWORD; i++){
    fputs("|", fp);
    for(int j = 0; j < MAXWORD; j++){
      if((puzzle[i][j]) != '.'){
        fputs(" ", fp);
      }
      else{
        fputs("#", fp);
      }
    }
    fputs("|", fp);
    fputs("\n", fp);
  }
  fputs("+", fp);
  for(int i = 0; i < MAXWORD; i++){
    fputs("-", fp);
  }
  fputs("+\n", fp);  

}

void fileMakeSolution(char solution[][MAXWORD], FILE *fp){

  fputs("+", fp);
  for(int i = 0; i < MAXWORD; i++){
    fputs("-",fp);
  }
  fputs("+",fp);
  fputs("\n", fp);
  for(int i = 0; i < MAXWORD; i++){
    fputs("|",fp);
    for(int j = 0; j < MAXWORD; j++){
      //fputs( solution[i][j], fp);
      fprintf(fp, "%c", solution[i][j]);
    }
    fputs("|",fp);
    fputs("\n",fp);
  }
  fputs("+", fp);
  for(int i = 0; i < MAXWORD; i++){
    fputs("-", fp);
  }
  fputs("+\n", fp);
}

/*
void placeFirstFile(WORD words[MAXWORDS], char solution[MAXWORDS][MAXWORD], FILE *fp){
  int length = strlen(words[0].word);
  int compare = (MAXWORD - length) / 2;

  int row = 7;
  words[0].x = 7;
  words[0].y = compare;
  words[0].direction = false;
  int column = compare;
  int index = 0;
  for(int i = 0; i < length; i++){
    solution[row][column] = words[0].word[index];
    column++;
    index++;
  }
}

void shuffleWordsFile(WORD clues[MAXWORDS], int numWords, WORD words[MAXWORDS], FILE *fp){
  char temp[MAXWORD];
  for(int i = 0; i < numWords; i++){
    strcpy(temp, words[i].word);
    strfry(temp);
    strcpy(clues[i].word, temp);
    fputs(words[i].word, fp);
  }
}

void placeWordsFile(WORD words[MAXWORDS], int numWords, WORD notPlaced[MAXWORDS], char solution[MAXWORDS][MAXWORD], FILE *fp){
  int result = 0;
  int direction = 0; //0 = vertical, 1 = horizontal, true = vertical, false = horizontal
  for(int i = 0; i < numWords-1; i++){
    int length1 = strlen(words[i].word);
    int length2 = strlen(words[i+1].word);
    for(int letter = 0; letter < length1; letter++){
      char letter1 = words[i].word[letter];
      //printf("letter from word1: %c\n", letter1);
      for(int index = 0; index < length2; index++){
        char letter2 = words[i+1].word[index];
	//printf("letter from word2: %c\n", letter2);
	if(words[i+1].used == true){
          continue;
	}
	if(letter1 == letter2){
	  //printf("found match in %s, %s, %c\n", words[i].word, words[i+1].word, letter2);

	  int count = 0;
	  for(int og = 0; og < length1; og++){
	    if(letter1 == words[i].word[og]){
	      break;
	    }
	    count++;
	  }
	  result = -1;
	  int row = words[i].x;
	  int column = words[i].y;

	  int x_compare = words[i].x;
	  int y_compare = words[i].y;

	  //printf("x: %d\n", x_compare);
	  //printf("y: %d\n", y_compare);

	  if(words[i].direction == true){
	    
	    x_compare += count;
	  }
	  else{
	    y_compare += count;
	  }
	  //printf("x: %d\n", x_compare);
	  //printf("y: %d\n", y_compare);

	  
	  //CHECKS
	  if(words[i].direction == true){
	    direction = 1;
	    if(solution[x_compare][y_compare+1] != '.'){
	      continue;
	    }
	    if(solution[x_compare][y_compare-1] != '.'){
	      continue;
	    }
	    if(solution[x_compare+1][y_compare+1] != '.'){
	      continue;
	    }
	    if(solution[x_compare-1][y_compare-1] != '.'){
	      continue;
	    }
	    if(solution[x_compare+1][y_compare-1] != '.'){
	      continue;
	    }
	    if(solution[x_compare-1][y_compare+1] != '.'){
	      continue;
	    }
	  }

	  else{
	    direction = 0;
	    if(solution[x_compare+1][y_compare] != '.'){
	      continue;
	    }
	    if(solution[x_compare-1][y_compare] != '.'){
	      continue;
	    }
	    if(solution[x_compare+1][y_compare+1] != '.'){
	      continue;
	    }
	    if(solution[x_compare-1][y_compare-1] != '.'){
	      continue;
	    }
	    if(solution[x_compare+1][y_compare-1] != '.'){
	      continue;
	    }
	    if(solution[x_compare-1][y_compare+1] != '.'){
	      continue;
	    }
	  }

	  //place word
          if(direction == 0){

            int cOL = words[i].y + count;
	    column = column + i; //column stays constant
	    //printf("index: %d\n", index);
	    int rowstart = row - index + 1 ;
	    int x = length2 - index;
	    int rowend = row + x;
	    int temp = index - 1 ;
	    int row1 = words[i].x;
	    if(rowstart-1 < 0){
	      continue;
	    }
	    if( rowend > 14){
	      continue;
	    }
	    for(int rowplace = row1; rowplace < rowend; rowplace++){
	      //printf("row: %d\n", rowplace);
              if(index == 0 ){
                solution[rowplace][cOL] = words[i+1].word[temp+1];
	      }
	      else{
	        solution[rowplace][cOL] = words[i+1].word[temp+1];
	      }
	      temp++;
	    }
	    //printf("count: %d\n", count);
	    //if (count != 0){
	      for(int j = index-1; j >= 0; j--){
	        solution[row1-1][cOL] = words[i+1].word[j];
	        row1--;
	      }  
	    //}

	   // fileMakePuzzle(solution, fp);
	    //fileMakeSolution(solution, fp);

	    words[i+1].x = rowstart-1;
	    words[i+1].y = cOL;
	    words[i+1].direction = true;
	    words[i+1].used = true;

          }

	  else{
	    //row = row - 1;
	    int rOW = words[i].x + count;
	    row = row + i -1 ; //row stays constant
	    int temp = index - 1;
	    int colstart = column - index;
	    int x = length2 - index;
	    int colend = column + x;
	    int col1 = words[i].y;
	    if(colstart < 0){
	      continue;
	    }
	    if(colend > 14){
	      continue;
	    }
	    for(int colplace = col1; colplace < colend; colplace++){
	      if(index == 0){
	        solution[rOW][colplace] = words[i+1].word[temp+1];
	      }
	      else{
	        solution[rOW][colplace] = words[i+1].word[temp+1];
              }
	      temp++;
	    }
	    for(int j = index -1 ; j >= 0; j--){
              solution[rOW][col1-1] = words[i+1].word[j];
	      col1--;
	    }
	    //fileMakePuzzle(solution, fp);
	    //fileMakeSolution(solution, fp);

	    words[i+1].x = rOW;
	    words[i+1].y = colstart;
	    words[i+1].direction = false;
	    words[i+1].used = true;

	  }
	  break;
	}
	else{
	  result++;
	}
      }

    }
    result = 0;
  }
}
 


void toFile(WORD words[MAXWORDS], WORD clues[MAXWORDS], WORD notPlaced[MAXWORDS], char solution[MAXWORDS][MAXWORD], char filename2[MAXWORD], char filename1[MAXWORD]){

  FILE *fp;
  fp = fopen(filename2, "w");

  int numWords = readFile(filename1, words);

  lengthOrder(words, numWords);

  placeFirstFile(words, solution, fp);

  shuffleWordsFile(clues, numWords, words, fp);

  placeWordsFile(words, numWords, notPlaced, solution, fp); 

  fileMakePuzzle(solution, fp);
  fileMakeSolution(solution, fp);


}

*/
