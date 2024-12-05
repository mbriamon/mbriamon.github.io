//Mary Briamonte
//Fund Comp
//symbol.c: symbolic typewriter
//lab 9 

#include "gfx.h"
#include <math.h>
void square(int, int, int);
void triangle(int, int, int);
void polygon(int, int, int, char);

int main(){

  int wd = 500;
  int ht = 400;
  int SIZE = 50;
  char c;
  int xm;
  int ym;

  gfx_open(wd, ht, "symbolic typewriter");

  while(1){

    gfx_flush();
    c = gfx_wait();
    xm = gfx_xpos();
    ym = gfx_ypos();

    //close window
    if(c == 'q'){
      break;
    }

    switch(c){
      //make blue square
      case 1:
      gfx_color(0, 0, 255);
      square(xm, ym, SIZE);
      break;

      //make a green triangle
      case 'c':
        gfx_color(255, 255, 255);
	gfx_circle(xm, ym, SIZE/2);
	break;
      case 't':
      gfx_color(0,200,100);
      triangle(xm,ym,SIZE);
      break;
    }
  }
  return 0;
}

//make a square
void square(int x, int y, int length){

  gfx_line(x-(length/2), y - (length/2), x+(length/2), y-(length/2));
  gfx_line(x + (length/2), y - (length/2), x+(length/2), y+(length/2));
  gfx_line(x+(length/2), y + (length/2), x-(length/2), y+(length/2));
  gfx_line(x-(length/2), y+(length/2), x-(length/2), y-(length/2));

}

//make a triangle
void triangle(int x, int y, int length){

  gfx_color(0,200,100);
  gfx_line(x-(length/2), y-(length/2), x+(length/2), y-(length/2));
  gfx_line(x+(length/2), y-(length/2), x,y+length);
  gfx_line(x,y+length,x-(length/2), y-(length/2));

}

//make a polygon
void polygon(int x, int y, int length, char s){

  int n;
  int x1;
  int y1;
  int x2;
  int y2;
  int angle = 90;

  for(n = 0; n <(s-'0'); n++){
    x1 = x-((length/2)*cos(angle*M_PI/180));
    y1 =y - ((length/2)*sin(angle*M_PI/180));
    angle = angle + (360/(s-'0'));
    x2 = x - ((length/2)*cos(angle*M_PI/180));
    y2 = y - ((length/2)*sin(angle*M_PI/180));
    gfx_line(x1, y1, x2,y2);

  }

}
