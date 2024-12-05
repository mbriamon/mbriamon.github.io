// mary briamonte
// fund comp
// lab 10
// fractals.c
// main driver to test the Sierpinski fractal
// NOTE: you may only use this code if you fully understand how it works.

#include "gfx.h"
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define HEIGHT 700
#define WIDTH 700

void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 );
void shrinking(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void square_spiral(int x, int y, float angle, float size);
void lace(int x, int y, int radius);
void snowflake(int x, int y, int radius);
void tree(int x, int y, float radius, float angle);
void fern(int x, int y, float radius, float angle);
void spiral_spiral(int x, int y, float radius, float angle);
void drawTriangle( int x1, int y1, int x2, int y2, int x3, int y3 );
void draw_square(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void draw_spiral_square(int x, int y, int length);

int main()
{
  int width = 700;
  int height = 700;
  int radius = 200;
  int margin;
  char c;
  bool loop = true;
 
 
  gfx_open(width, height, "fractals");

  while(loop) {
    
    c = gfx_wait();
    gfx_clear();

   // if ( gfx_wait() == 'q' ) break;

    switch (c) {
      case '1': // Sierpinski Triangle   
        gfx_clear();
	margin = 20;
        sierpinski(margin, margin, width - margin, margin, width / 2, height - margin);
        break;

      case '2': // Shrinking Squares  
        gfx_clear();
        shrinking(width / 4, height / 4, 3 * width / 4, height / 4, 3 * width / 4, 3 * height / 4, width / 4, 3 * height / 4);
        break;

      case '3': //spiral of squares
        gfx_clear();
	square_spiral(width / 2, height / 2, M_PI * 5, HEIGHT / 4.5);
	break;
 
      case '4': //circular lace
        gfx_clear();
	lace(width / 2, height / 2, radius);
	break;

      case '5': //snowflake
        gfx_clear();
        snowflake(width / 2, height / 2, radius);
	break;

      case '6':  // tree
        gfx_clear();
	tree(width / 2, height - margin, width / 4, M_PI / 2);
	break;

      case '7':  //fern 
        gfx_clear();
        fern(width / 2, height - margin, width / 7, M_PI / 2);
	break;

      case '8': // Spiral of Spirals 
        gfx_clear();
	spiral_spiral(width / 2, height / 2, radius * 4, M_PI * 8);
        break;

      case 'q':
        loop = false;
      
      default:
        break;
    }
  }
}

//triangles
void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 )
{
  // Base case
  if( abs(x2-x1) < 5 ) {
    return;
  }

  // Draw a big triangle
  drawTriangle( x1, y1, x2, y2, x3, y3 );

  // Recursive calls
  sierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
  sierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
  sierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );
}

//shrinking squares
void shrinking(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
  //legnth of side
  int length = x3 - x1;
  //base case
  if(abs(length) < 6){
    return;
  }

  //draw big square
  draw_square(x1, y1, x2, y2, x3, y3, x4, y4);

  //value used to scale scale squares down
  float shrink = .2 * length;

  //recursive calls
  shrinking(x1 - shrink, y1 - shrink, x1 - shrink, y1 + shrink, x1 + shrink, y1 + shrink, x1 + shrink, y1 - shrink);
  shrinking(x2 - shrink, y2 - shrink, x2 - shrink, y2 + shrink, x2 + shrink, y2 + shrink, x2 + shrink, y2 - shrink);
  shrinking(x3 - shrink, y3 - shrink, x3 - shrink, y3 + shrink, x3 + shrink, y3 + shrink, x3 + shrink, y3 - shrink);
  shrinking(x4 - shrink, y4 - shrink, x4 - shrink, y4 + shrink, x4 + shrink, y4 + shrink, x4 + shrink, y4 - shrink);
}

//spiral of squares
void square_spiral(int x, int y, float angle, float size){
  float a = .7;
  float b = .8;
  float radius;

  //change space between each, location of square
  radius = 29 * (pow, (a, (angle * cos(b) / sin(b))));
  x = (int)((WIDTH / 2) + radius * cos(angle));
  y = (int)((WIDTH / 2) + radius * sin(angle));

  //going around spiral
  angle -= M_PI / 6;
  //change size of squares
  size -= size / 5;

  //base case
  if (angle <= (M_PI / 20)){
    return;
  }

  //recursive calls
  square_spiral(x, x, angle, size);
  draw_spiral_square(x, y, size);
}

//circular lace
void lace (int x, int y , int radius ){
  int i;
  int number = 6;
 
  //base case
  if (radius < 1){
    return ;
  }

  //draw big circle
  gfx_circle(x, y, radius);

  //recursive calls
  for ( i = 0; i < number; ++i){
    lace(x + radius * cos((2*M_PI / number) * i), y + radius * sin((2*M_PI / number) * i), radius/3);
  }
}

//snowflake
void snowflake(int x, int y, int radius){
  int i;
  int number = 5;
  float angle = M_PI / 2;

  //bae case
  if(radius < 3){
    return;
  }
  //recurisev
  for(i = 0; i < number; ++i){
    gfx_line(x, y, x + radius * cos((2*M_PI / number) *i), y + radius * sin((2 * M_PI / number) * i));
    snowflake(x + radius * cos((2 * M_PI / number) * i), y + radius * sin((2 * M_PI / number) * i), radius * .4);
  }
}


//tree
void tree(int x, int y, float radius, float angle){
  int x1 = x - radius * cos(angle);
  int y1 = y - radius * sin(angle);

  //base case
  if(radius < 3){
    return;
  }

  //draw big line
  gfx_line(x, y, x1, y1);

  gfx_flush();

  //recurive calls
  tree(x1, y1, .7 * radius, angle + (M_PI / 6));
  tree( x1, y1, .7 * radius, angle - (M_PI / 6));
}

//fern
void fern(int x, int y, float radius, float angle){
  int x1;
  int x2;
  int y1;
  int y2;
  float a = angle;

  //keep track of how tall
  static int number = 0;

  //base case
  if ((radius <= 2) || number >= 4){
    return;
  }
  
  //change endpoint
  x1 = x - radius * cos(a);
  y1 = y - radius * sin(a);
  ++number;

  gfx_flush();

  gfx_line(x, y, x1, y1);
  fern(x1, y1, radius, a);

  number = 0;

  //base case
  if((number >= 4) || (radius <= 2)){
    return;
  }

  //draw lines at angles
  radius *= .4;
  a = angle - M_PI / 4.5;
  x2 = x1 - radius * cos(a);
  y2 = y1 - radius * sin(a);
  ++number;

  gfx_flush();

  gfx_line(x1, y1, x2, y2);
  fern(x1, y1, radius, a);

  number = 0;

  //base case
  if((number >= 4) || (radius <= 2)){
    return;
  }

  a = angle + M_PI / 4.5;
  x2 = x1 - radius * cos(a);
  y2 = y1 - radius * sin(a);
  ++number;

  gfx_flush();
  gfx_line(x1, y1, x2, y2);
  fern(x1, y1, radius, a);

}

//spiral of spirals
void spiral_spiral(int x, int y, float radius, float angle){
  //base case
  if(radius < 1.5){
    return;
  }

  //draw points at specific angle
  gfx_point(x + radius * cos(angle), y + radius * sin(angle));
  //recurseive calls
  spiral_spiral(x + radius * cos(angle), y + radius * sin(angle), radius * .25, angle);
  spiral_spiral(x, y, radius * .95, angle + M_PI / 4 * .55);
}

//basic triangle
void drawTriangle( int x1, int y1, int x2, int y2, int x3, int y3 )
{
  gfx_line(x1,y1,x2,y2);
  gfx_line(x2,y2,x3,y3);
  gfx_line(x3,y3,x1,y1);

  gfx_flush();
}

//basic square
void draw_square(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
  gfx_line(x1, y1, x2, y2);
  gfx_line(x2, y2, x3, y3);
  gfx_line(x3, y3, x4, y4);
  gfx_line(x4, y4, x1, y1);

  gfx_flush();
}

//spiral square
void draw_spiral_square(int x, int y, int length){
  gfx_line(x - (length/2), y-(length/2), x + (length/2), y-(length/2));
  gfx_line(x + (length/2), y-(length/2), x + (length/2), y+(length/2));
  gfx_line(x + (length/2), y+(length/2), x - (length/2), y+(length/2));
  gfx_line(x - (length/2), y+(length/2), x - (length/2), y-(length/2));

  gfx_flush();
}
