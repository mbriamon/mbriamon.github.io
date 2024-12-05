//Mary Briamonte LAB 11
#include "gfx.h"
#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>

#define MAX 3
#define TOTAL 9

/*
typedef struct {
  
  int x;
  int y;
  bool used; //true = space filled, false = empty 
  char player; //player o or player x
} Space;
*/

typedef struct{
  int r; //red values
  int g; //blue values
  int b; //green values
} Thing;

//tic tac toe functions
void init_board(char [MAX][MAX]);
void print_board(char [MAX][MAX]);
int check_winner(char [MAX][MAX]);

//flappy bird functions
void start(char *, char *, char *, char *);
void make_things(Thing []);
void loser(char *, char *, char *, char *);
void end(char *, char *, char *, char *);

int main(){
  char c; 
  /*
  printf("WELCOME TO MY MINI GAME ROOM!\nYou have 2 choices:\n 1. Tic Tac Toe (2 person game)\n 2. My Version of Flappy Bird (1 person game)\n");
  printf("to play Tic Tac Toe please enter: t\n");
  printf("to play Flappy Bird please enter: f\n");
  printf("to quit please enter: q\n");
  scanf("%c", c);
*/
  bool loop = true;
  //char c;

  char board[MAX][MAX];
  int row, col, player = 1, total_moves = 0;

  int width = 600;
  int height = 500;

  int score = 0;
  char print_score[5];
  char score_title[200];



//initial position for bird(bx, by), first  thing(tx, ty)
      int bx = 200;
      int tx = 600;
      int by = 200;
      int ty = 200;

      //user input
      char c1;

      //initial distance and radius (for checking collision)
      float distance = 90;
      int total_radius = 7;

      //struct of things
      Thing things[8];
      make_things(things);

      //starting at first planet, set radius
      int i = 0;
      int radius = 20;

      //message to screen
      char intro1[200];
      char intro2[200];
      char intro3[200];
      char intro4[200];
      char wild_space1[200];
      char wild_space2[100];
      char collision1[200];
      char collision2[200];
      char end1[200];
      char end2[200];


  printf("WELCOME TO MY MINI GAME ROOM!\nYou have 2 choices:\n 1. Tic Tac Toe (2 person game)\n 2. My Version of Flappy Bird (1 person game)\n");
  printf("to play Tic Tac Toe please enter: t\n");
  printf("to play Flappy Bird please enter: f\n");
  printf("to quit please enter: q\n");

  scanf("%c", &c);

  //printf("here");

  while(loop){
   switch(c){
    case 't':  //play tic tac toe
      //Space spaces[TOTAL];
      //char board[MAX][MAX];  // 3x3 game board

      //int row, col, player = 1, total_moves = 0;

      init_board(board);
      printf("Welcome to Tic-Tac-Toe!\n");
      printf("Player 1 (X) - Player 2 (O)\n");
      print_board(board);

      while (total_moves < TOTAL) {
        printf("Player %d, enter row (1-3) and column (1-3) to place your mark: ", player);
        scanf("%d %d", &row, &col);
        //spaces[total_moves].player = player;

        if (row < 1 || row > 3 || col < 1 || col > 3) {
          printf("Invalid row or column number. Please try again.\n");
          continue;
        }
        row--;
        col--;
        //spaces[total_moves].x = row;
	//spaces[total_moves].y = col;

        if (board[row][col] != ' ') {
            printf("That spot is already taken. Please try again.\n");
            continue;
        }
        board[row][col] = (player == 1) ? 'X' : 'O';
        print_board(board);
        //spaces[total_moves].used = true;

        if (check_winner(board)) {
            printf("Player %d wins!\n", player);
	    break;
            //return 0;
        }
        player = (player == 1) ? 2 : 1;
        total_moves++;
      }

      if(total_moves == 8){
        printf("It's a tie!\n");
	break;
      }

      //return 0;
     

      break;

    
    case 'f':  //play flappy bird
       //messages
      strcpy(intro1, "Welcome to Flappy Bird! Meet your new best friend, Bob the Bird");
      strcpy(intro2, "Don't hit the things coming at you, or go off the screen.");
      strcpy(intro3, "Navigating:  U = Up, D = Down.");
      strcpy(intro4, "Hit any key to start. Hit Q to quit. Good Luck!! :) ");
      strcpy(wild_space1, "Really, you can't do any better than that. I told you not to fly off screen!!");
      strcpy(wild_space2, "WOW. It's not that hard. I beat this course blindfolded. Try harder!");
      strcpy(collision1, "That's sad. Are you trying to crash Bob the Bird!?!?!?");
      strcpy(collision2, "Bob is flapping his wings for you, and you can't even direct him! It's your only job.");
      strcpy(end1, "Congrats! You survived. Took you long enough.");
      strcpy(end2, "I'm impressed. You made it to the end without killing Bob. Q to quit.");
      strcpy(score_title, "score is: ");

      //setting color of thing 1
      int red = things[0].r;
      int green = things[0].g;
      int blue = things[0].b;

      gfx_open(width, height, "Flappy Bird");

      //instructions
      start(intro1, intro2, intro3, intro4);

      gfx_wait();

      while(1){
        gfx_clear();

	if(c1 == 'q'){
	  break;
	}

	//make Bob
	gfx_color(red, green, blue);
	gfx_circle(tx, ty, radius);
	gfx_color(209, 209, 209);
	gfx_circle(bx, by, 25);
	gfx_color(255, 0, 0);
	gfx_line(bx-25, by, bx-25, by+25);
	gfx_line(bx-8, by-4, bx-8, by-3);
	gfx_line(bx+8, by-4, bx+8, by-3);
	gfx_line(bx-8, by+4, bx+8, by+4);
	gfx_line(bx+25, by, bx+25, by+25);
	gfx_color(0, 255, 0);
	//gfx_text(tx - radius -40, ty  + radius + 40);

	//print score
	sprintf(print_score, "%d", score);
	gfx_text(340, 10, score_title);
	gfx_text(400, 10, print_score);

	gfx_flush();

	//calculating distance between Bob and planet to determine collision
	distance = sqrt((pow(bx-tx,2))+(pow(by-ty,2)));
	total_radius = 25 + radius;

	//if collsion, end
	if(pow(2, distance) <= pow(2, total_radius)){
	  while(1){
	    sprintf(print_score, "%d", score);
	    loser(collision1, collision2, score_title, print_score);
	    c1 = gfx_wait();

	    if(c1 == 'q'){
	      break;
	    }
	  }
	}

	if(gfx_event_waiting()){
	  c1 = gfx_wait();
	}

	//if quit, end game
	if(c1 == 'q'){
	  break;
	}

	// u = up
	if(c1 == 'u'){
	  by -= 10;
	}
	//d = down
	if(c1 == 'd'){
	  by += 10;
	}

	//across
	tx -= 8;

	//off top of screen
	if(by - 25 < 0){
	  while(1){
	    sprintf(print_score, "%d", score);
	    loser(wild_space1, wild_space2, score_title, print_score);
	    c1 = gfx_wait();

	    if(c1 == 'q'){
	      break;
	    }
	  }
	}
	//off bottom of screen
	if(by + 25 > 500){
	  while(1){
	    sprintf(print_score, "%d", score);
	    loser(wild_space1, wild_space2, score_title, print_score);
	    c1 = gfx_wait();

	    if(c1 == 'q'){
	      break;
	    }
	  }
	}

	//when reaches end
	if(tx + 25 < 0){
	  //send next thing
	  ++ i;
	  //are all things done
	  if(i == 8){
	    while(1){
	      sprintf(print_score, "%d", score);
	      end(end1, end2, score_title, print_score);
	      c1 = gfx_wait();

	      if(c1 == 'q'){
	        break;
              }
	    }
	  }

	  //random height of thing
	  ty = rand() %(200 +1) + 100;

	  //start off screen
	  tx = 700;

	  //color
	  red = things[i].r;
	  green = things[i].g;
	  blue = things[i].b;

	  //random size
	  radius = rand() %(50 +1) +10;
	}

	//increment score
	score++;

	usleep(90000);
      }

      break;
    
    case 'q':
      loop = false;

    default:
      break;
  
   }
  printf("to play Tic Tac Toe please enter: t\n");
  printf("to play Flappy Bird please enter: f\n");
  printf("to quit please enter: q\n");
  scanf("%c", &c);
  }


}

//Tic Tac Toe functions
void init_board(char board[MAX][MAX]) {
    // Initialize game board with empty spaces
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board(char board[MAX][MAX]) {
    // Print the current state of the game board
    int i, j;
    for (i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i != 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int check_winner(char board[MAX][MAX]) {
    // Check if there is a winner
    int i;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') {
            return 1;  // Row i has a winner
        }
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ') {
            return 1;  // Column i has a winner
        }
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') {
        return 1;  // Diagonal from top-left to bottom-right has a winner
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ') {
        return 1;  // Diagonal from top-right to bottom-left has a winner
    }
    return 0;  // No winner yet
}


//flappy bird functions
void start(char * first, char * second, char * third, char * fourth){
  gfx_clear();
  gfx_color(0,255,255);
  gfx_text(10,20, first);
  gfx_text(10,50, second);
  gfx_text(10,80, third);
  gfx_text(10,110, fourth);

  gfx_flush();
}

void loser(char * lost1, char * lost2, char * score_is, char * score){
  gfx_clear();
  gfx_color(0,255,255);
  gfx_text(10,150, lost1);
  gfx_text(10,180, lost2);
  gfx_text(10,210,score_is);
  gfx_text(10,250, score);

  gfx_flush();
}

void end(char * first, char * second, char * score_is, char * score){
  
  gfx_clear();
  gfx_color(0,255,255);
  gfx_text(5,150,first);
  gfx_text(5, 180,second);
  gfx_text(5, 210, score_is);
  gfx_text(5, 240, score);
  gfx_flush();
}

void make_things(Thing things[]){
  //colors
  things[0].r = 77;
  things[1].r = 156;
  things[2].r = 22;
  things[3].r = 65;
  things[4].r = 25;
  things[5].r = 255;
  things[6].r = 57;
  things[7].r = 13;

  things[0].g = 77;
  things[1].g = 140;
  things[2].g = 66;
  things[3].g = 195;
  things[4].g = 120;
  things[5].g = 201;
  things[6].g = 167;
  things[7].g = 45;

  things[0].b = 77;
  things[1].b = 106;
  things[2].b = 29;
  things[3].b = 204;
  things[4].b = 67;
  things[5].b = 51;
  things[6].b = 255;
  things[7].b = 110;
}

