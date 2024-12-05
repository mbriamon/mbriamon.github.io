//Mary Briamonte
//FUND COMP
//bounce.c : bouncing ball
//lab 9 part 2


#include <unistd.h>
#include <stdlib.h>
#include "gfx.h"


int main(){

  //seed
  srand(time(0));

  int width = 500;
  int height = 400;
  int x = 200;
  int y  = 250;
  int dx = rand () % (5 - -15 + 1) + -15;
  int dy = rand () % (5 - -15 + 1) + -15;
  int x_click;
  int y_click;
  int radius = 20;
  int low = -5;
  int high = 5;
  int pause_time = 20000;
  char c;

  //make sure that dx, dy != 0
  if(dx == 0){
    while(dx == 0){
      dx = rand () % (5 - -5 + 1) + -5;
    }
  }
  if(dy == 0){
    while(dy == 0){
      dy = rand () % (5 - -5 + 1) + -5;
    }
  }
  
  gfx_open(width, height, "bouncing ball");

  //make bouncing circle, set location of new velocities of moving circle upon mouse click
  while(1){
    gfx_clear ();
    gfx_circle(x, y, radius);
    gfx_flush;

    x += dx;
    y += dy;


    if(c == 1){
      srand(time(0));
      x = x_click;
      y = y_click;
      c = 27;
      dx = rand () % (5 - -5 + 1) + -5;
      dy = rand () % (5 - -5 +1) + -5;

      if(dx == 0){
        while(dx == 0){
	  dx = rand () % (5 - -5 + 1) + -5;
	}
      }
      if(dy == 0){
        while(dy == 0){
	  dy = rand () % (5 - -5 + 1) + -5;
	}
      }

      continue;
    }

    if(gfx_event_waiting()){
      char w = gfx_wait();
      if(w == '1');
      x = gfx_xpos();
      y = gfx_ypos();
      dx = rand() % -5 + 5;
      dy = rand() % -5 + 5;
    }

    //check walls
    if (x + radius >= width){
      dx = -dx;
    }
    if (x + radius <= (2 * radius)){
      dx = -dx;
    }

    if(y + radius >= height){
      dy = -dy;
    }
    if(y+radius <= (2 * radius)){
      dy = -dy;
    }
    if(gfx_event_waiting()){
        c = gfx_wait();
    }
    if(c == 'q'){
      break;
    }
    usleep(pause_time);
  }
  return 0;

}
