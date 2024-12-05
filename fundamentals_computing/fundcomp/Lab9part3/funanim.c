//Mary Briamonte
//Fund Comp
//Lab 9 Part 3: Rotating Animation


#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "gfx.h"

void square(int, int, int);
void triangle(int, int, int);

int main(){
  int width = 600;
  int height = 600;
  int path = 15;
  int xo_circle = 300; //inital x position of circle
  int x_circle;
  int yo_circle = 400;
  int y_circle;
  int radius = 20;
  int side = 200;
  int xo_square = 300;
  int x_square;
  int yo_square = 200;
  int y_square;
  float angle = 0 * M_PI;
  int pause_time = 90000;
  char c;

  gfx_open(width, height, "rotating animation");


  while(1){
    gfx_clear();
    //change color based on input
    if(c == 'g'){
      gfx_color(0,200,100);
    }
    else if(c == 'b'){
      gfx_color(0,0,255);
    }
    else if(c == 'r'){
      gfx_color(255, 0,0);
    }

    //make shapes
    triangle(x_circle, y_circle, radius);
    gfx_circle(x_circle, y_circle, radius);
    square(x_square, y_square, side);
    gfx_flush();

    //change position based on location in path
    x_circle = xo_circle + cos(angle) * path;
    y_circle = yo_circle + sin(angle) * path;
    x_square = xo_square + cos(angle) * path;
    y_square = yo_square + sin(angle) * path;

    //update angle
    angle += M_PI /12;
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

//make square 
void square(int x, int y, int length){
  gfx_line(x-(length/2), y - (length/2), x+(length/2), y-(length/2));
  gfx_line(x + (length/2), y - (length/2), x+(length/2), y+(length/2));
  gfx_line(x+(length/2), y + (length/2), x-(length/2), y+(length/2));
  gfx_line(x-(length/2), y+(length/2), x-(length/2), y-(length/2));
}

void triangle(int x, int y, int length){
  gfx_line(x-(length/2), y-(length/2), x+(length/2), y-(length/2));
  gfx_line(x+(length/2), y-(length/2), x,y+length);
  gfx_line(x,y+length,x-(length/2), y-(length/2));
}
