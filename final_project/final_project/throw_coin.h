#ifndef THROW_COIN_H
#define THROW_COIN_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "public_tool.h"
void Show_Image(SDL_Surface *png,SDL_Surface *screen,SDL_Rect rect) {
  SDL_BlitSurface( png, NULL, screen, &rect );
  SDL_Flip( screen );
  SDL_Delay( 1000 );
  SDL_FreeSurface( screen );
  screen = SDL_SetVideoMode( 600, 400, 32, SDL_SWSURFACE || SDL_OPENGL);
}
bool throw_coin () {   //screen is where to output,正面:True，反面:False
  int coin;
  srand(time(NULL));
  coin=rand()%2; 
  struct picture rc[9];
  rc[0].stored = Loadpicture("coin/", "1");
  rc[1].stored = Loadpicture("coin/", "2");
  rc[2].stored = Loadpicture("coin/", "3");
  rc[3].stored = Loadpicture("coin/", "4");
  rc[4].stored = Loadpicture("coin/", "5");
  rc[5].stored = Loadpicture("coin/", "6");
  rc[6].stored = Loadpicture("coin/", "coinfront");
  rc[7].stored = Loadpicture("coin/", "coinback");
  rc[8].stored = Loadpicture("coin/","background_0");
	  
  for (int i=0; i<8; i++){
	rc[i].x=250;
	rc[i].width=150;
	rc[i].y=150;
	rc[i].height=150;
  }
  while(rc[0].y>60) {
	glClear(GL_COLOR_BUFFER_BIT);
	  
	glPushMatrix(); //Start rendering phase
 
	glOrtho(0,600,400,0,-1,1); //Set the matrix
	showpicture(rc[8]);
	showpicture(rc[0]);
	rc[1].y-=10;
      glPopMatrix(); //End rendering phase
 
	  SDL_GL_SwapBuffers();
	  SDL_Delay(100);

      glClear(GL_COLOR_BUFFER_BIT);
	  
	  glPushMatrix(); //Start rendering phase
	  glOrtho(0,600,400,0,-1,1); //Set the matrix
	showpicture(rc[8]);
	showpicture(rc[1]);
	rc[2].y-=20;
	glPopMatrix(); //End rendering phase
 
	  SDL_GL_SwapBuffers();
	 SDL_Delay(100);

      glClear(GL_COLOR_BUFFER_BIT);
	  
	  glPushMatrix(); //Start rendering phase
 
	  glOrtho(0,600,400,0,-1,1); //Set the matrix
	showpicture(rc[8]);
	showpicture(rc[2]);
	rc[3].y-=30;
	glPopMatrix(); //End rendering phase
 
	  SDL_GL_SwapBuffers();
	 
	  SDL_Delay(100);

      glClear(GL_COLOR_BUFFER_BIT);
	  
	  glPushMatrix(); //Start rendering phase
 
	  glOrtho(0,600,400,0,-1,1); //Set the matrix
	showpicture(rc[8]);
	showpicture(rc[3]);
	rc[4].y-=40;
	glPopMatrix(); //End rendering phase
 
	  SDL_GL_SwapBuffers();
	 
	  SDL_Delay(100);

      glClear(GL_COLOR_BUFFER_BIT);
	  
	  glPushMatrix(); //Start rendering phase
 
	  glOrtho(0,600,400,0,-1,1); //Set the matrix
	showpicture(rc[8]);
	showpicture(rc[4]);
	rc[5].y-=50;
	glPopMatrix(); //End rendering phase
 
	  SDL_GL_SwapBuffers();
	 
	  SDL_Delay(100);

      glClear(GL_COLOR_BUFFER_BIT);
	  
	  glPushMatrix(); //Start rendering phase
 
	  glOrtho(0,600,400,0,-1,1); //Set the matrix
	showpicture(rc[8]);
	showpicture(rc[5]);
	rc[0].y-=60;
	glPopMatrix(); //End rendering phase
 
	SDL_GL_SwapBuffers();
	SDL_Delay(100);
	for(int i=0;i<5;i++) {
	  rc[i+1].y=rc[i].y;
	}
	
  }
  while(rc[0].y!=150) {

    glClear(GL_COLOR_BUFFER_BIT);
	  
	glPushMatrix(); //Start rendering phase
 
	glOrtho(0,600,400,0,-1,1); //Set the matrix
	showpicture(rc[8]);
	showpicture(rc[0]);
	rc[1].y+=10;
	glPopMatrix(); //End rendering phase
 
	SDL_GL_SwapBuffers();
	SDL_Delay(100);

    glClear(GL_COLOR_BUFFER_BIT);
	  
	glPushMatrix(); //Start rendering phase
 
    glOrtho(0,600,400,0,-1,1); //Set the matrix
	showpicture(rc[8]);
	showpicture(rc[1]);
	glPopMatrix(); //End rendering phase
 
	SDL_GL_SwapBuffers();
	rc[2].y+=20;
	SDL_Delay(100);

	glClear(GL_COLOR_BUFFER_BIT);
	  
	glPushMatrix(); //Start rendering phase
 
	glOrtho(0,600,400,0,-1,1); //Set the matrix
	showpicture(rc[8]);
	showpicture(rc[2]);
	glPopMatrix(); //End rendering phase
 
	SDL_GL_SwapBuffers();
	 
	rc[3].y+=30;
	SDL_Delay(100);

    glClear(GL_COLOR_BUFFER_BIT);
	  
	glPushMatrix(); //Start rendering phase
 
	glOrtho(0,600,400,0,-1,1); //Set the matrix
	showpicture(rc[8]);
	showpicture(rc[3]);
	glPopMatrix(); //End rendering phase
 
	SDL_GL_SwapBuffers();
	SDL_Delay(100);
	rc[4].y+=40;

    glClear(GL_COLOR_BUFFER_BIT);
	  
	glPushMatrix(); //Start rendering phase
 
	glOrtho(0,600,400,0,-1,1); //Set the matrix
	showpicture(rc[8]);
	showpicture(rc[4]);
	glPopMatrix(); //End rendering phase
 
	SDL_GL_SwapBuffers();
	SDL_Delay(100);
	rc[5].y+=50;

    glClear(GL_COLOR_BUFFER_BIT);
	  
	glPushMatrix(); //Start rendering phase
 
	glOrtho(0,600,400,0,-1,1); //Set the matrix
	showpicture(rc[8]);
	showpicture(rc[5]);
	glPopMatrix(); //End rendering phase
 
	SDL_GL_SwapBuffers();
	SDL_Delay(100);
	rc[0].y+=60;
	for(int i=0;i<6;i++) {
	  rc[i+1].y=rc[i].y;
	}
  }
  if(coin==0) {
	glClear(GL_COLOR_BUFFER_BIT);
	  
	glPushMatrix(); //Start rendering phase
 
	glOrtho(0,600,400,0,-1,1); //Set the matrix
	showpicture(rc[8]);
	showpicture(rc[6]);
	glPopMatrix(); //End rendering phase
 
	SDL_GL_SwapBuffers();
	SDL_Delay(2000);

	return true;
  }
  else {
	glClear(GL_COLOR_BUFFER_BIT);
	  
	glPushMatrix(); //Start rendering phase
 
	glOrtho(0,600,400,0,-1,1); //Set the matrix
	showpicture(rc[8]);
	showpicture(rc[7]);
	glPopMatrix(); //End rendering phase
 
	SDL_GL_SwapBuffers();
	SDL_Delay(2000);
	return false;
  }
}
#endif