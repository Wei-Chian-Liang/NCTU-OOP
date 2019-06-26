#include <iostream>
#include <string>
#include <cmath>
#include "SDL.h"
#include "SDL_image.h"
#include <Windows.h>
#include "SDL_ttf.h"
#include "public_tool.h"
#include "character_weapon.h"

using namespace std;
#ifndef PLAYER_H
#define PLAYER_H

/*void Set_Image(SDL_Surface *png,SDL_Surface *screen,SDL_Rect rect) { //set background
  SDL_FreeSurface(screen);
  screen = SDL_SetVideoMode( 600, 400, 32, SDL_SWSURFACE );
  SDL_BlitSurface( png, NULL, screen, &rect );
  SDL_Flip( screen );
}*/

class Player {
public:
  float x;//player
  float y;//player
  int power;
  float angle;
  int force;
  int HP;
  int type;
  int tool_type;
  Dog dog;
  Cat cat;
  Lion lion;
  Weapon weapon;
  struct picture tool;
  struct picture playerpic;

  Player(float ix=50,float iy=20) {
    x=ix;
	y=iy;
	power=0;
	tool_type=-1;
  }

  void set_charac_type(int i);
  //void print_word();

  void move_right() {
	 playerpic.x+=5;
  }
  void move_left() {
	  playerpic.x -= 5;
  }
  void deHP() {  
	HP-=weapon.hit;//武器攻擊力
  }
  void attack(float image_x,int num) {      //powerline and angle's x
	                                //call function後會開始選擇角度，按任意鍵盤上的鍵決定角度，接著決定力道，也是按任意鍵決定，角度跟力道都是從0開始跑到最大值再跑回0。
	int test=1;
    struct picture rc[6];
	//rc[0].stored = Loadpicture("c/", "background_500");
	rc[1].stored = Loadpicture("attack/", "powerline");
	rc[2].stored = Loadpicture("attack/", "line");
    rc[3].stored = Loadpicture("attack/", "angle");
	rc[4].stored = Loadpicture("attack/", "angle_line");
	for(int i=1;i<4;i++) {
	  rc[i].x=image_x;
	  rc[i].y=200;
	  rc[i].height=50;
	  rc[i].width=50;
	}
	rc[1].width=210;
	rc[2].width=5;
	rc[3].x=playerpic.x;
	rc[3].y=280;
	rc[4].x=0;
	rc[4].y=0;
	rc[4].height=5;
	rc[4].width=50;
	/*SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface *background;
	background = SDL_SetVideoMode( 600, 400, 32, SDL_SWSURFACE );
	SDL_Surface *power;
	SDL_Surface *line;
	power=IMG_Load("powerline.png");
	line=IMG_Load("line.png");
	SDL_Rect rect1;
	rect1.x=100;
	rect1.y=100;
	SDL_Rect rect2(rect1);
	Set_Image(power,background,rect1);
	SDL_BlitSurface( line, NULL, background, &rect1 );
    SDL_Flip( background );*/
	SDL_Event evt;
	while(test==1) {
		for(float i=0;i<=90&&test==1;i++){
		angle=i;
		//glClear(GL_COLOR_BUFFER_BIT);
	  
	    glPushMatrix(); //Start rendering phase

	    //glOrtho(0,600,400,0,-1,1); //Set the matrix
		//showpicture(pic[0]);
		//showpicture(pic[5]);*/
		if(num==2) {
		  glTranslated(playerpic.x,280,0);
		  glRotatef(90,0,0,-1);
		  glTranslated(-playerpic.x,-280,0);
		}
		showpicture(rc[3]);
		glTranslated(playerpic.x,325,0);
		if(num==2) {
		  glRotatef(-i,0,0,-1);
		  glRotatef(90,0,0,-1);
		}
		else
		  glRotatef(i,0,0,-1);
		showpicture(rc[4]);
		SDL_Delay(10);
		//SDL_Delay(1000);
		glPopMatrix(); //End rendering phase
 
	    SDL_GL_SwapBuffers();
		SDL_PollEvent(&evt);
		//SDL_Delay(10);
		if(evt.type==SDL_KEYDOWN) { 
		  test=-1;
		  SDL_Delay(100);
		  break;
		}
	  }
	  for(float i=angle;i>=0&&test==1;i--) {
	    angle=i;
		//glClear(GL_COLOR_BUFFER_BIT);
	  
	    glPushMatrix(); //Start rendering phase

	    //glOrtho(0,600,400,0,-1,1); //Set the matrix
		//showpicture(pic[0]);
		//showpicture(pic[5]);)*/
		if(num==2) {
		  glTranslated(playerpic.x,280,0);
		  glRotatef(90,0,0,-1);
		  glTranslated(-playerpic.x,-280,0);
		}
		showpicture(rc[3]);
		glTranslated(playerpic.x,325,0);
		if(num==2) {
		  glRotatef(-i,0,0,-1);
		  glRotatef(90,0,0,-1);
		}
		else
		  glRotatef(i,0,0,-1);
		showpicture(rc[4]);
		SDL_Delay(10);
		glPopMatrix(); //End rendering phase
 
	    SDL_GL_SwapBuffers();
		SDL_PollEvent(&evt);
		//SDL_Delay(10);
		if(evt.type==SDL_KEYDOWN) {
		  test=-1;
		  SDL_Delay(100);
		  break;
		}
	  }
	}
	angle=angle/180*3.14;
	test=1;
	while(test==1) {
	  for(int i=0;i<=100&&test==1;i++){
		force=i;
		//glClear(GL_COLOR_BUFFER_BIT);
	  
	    glPushMatrix(); //Start rendering phase

	    //glOrtho(0,600,400,0,-1,1); //Set the matrix
		//showpicture(pic[0]);
		//showpicture(pic[5]);*/
		showpicture(rc[1]);
		showpicture(rc[2]);
		SDL_Delay(10);
		glPopMatrix(); //End rendering phase
 
	    SDL_GL_SwapBuffers();
		rc[2].x+=2;
		/*rect2.x+=4;
		Set_Image(power,background,rect1);
		SDL_BlitSurface( line, NULL, background, &rect2 );
        SDL_Flip( background );*/
		SDL_PollEvent(&evt);
		//SDL_Delay(10);
		if(evt.type==SDL_KEYDOWN) {
		  test=-1;
		  break;
		}
	  }
	  for(int i=100;i>=0&&test==1;i--) {
	    force=i;
		//glClear(GL_COLOR_BUFFER_BIT);
	  
	    glPushMatrix(); //Start rendering phase

	    //glOrtho(0,600,400,0,-1,1); //Set the matrix
		//showpicture(pic[0]);
		//showpicture(pic[5]);*/
		showpicture(rc[1]);
		showpicture(rc[2]);
		SDL_Delay(10);
		glPopMatrix(); //End rendering phase
 
	    SDL_GL_SwapBuffers();
		rc[2].x-=2;
		/*rect2.x-=4;
		Set_Image(power,background,rect1);
		SDL_BlitSurface( line, NULL, background, &rect2 );
        SDL_Flip( background );*/
		SDL_PollEvent(&evt);
		//SDL_Delay(10);
		if(evt.type==SDL_KEYDOWN) {
		  test=-1;
		  break;
		}
	  }
	}
	/*SDL_FreeSurface(background);
	SDL_FreeSurface(power);
	SDL_FreeSurface(line);*/
	float ivx=(force/weapon.mass)*cos(angle);//initial velocity in x direction
	float ivy=(force/weapon.mass)*sin(angle);//initial velocity in y direction
	if(num==2)
	  weapon.picture[0].set_vx(-ivx);
	else
		weapon.picture[0].set_vx(ivx);
	weapon.picture[0].set_vy(ivy);
	power++;
  }
};

void Player::set_charac_type(int i){
    type=i;
    if (i==0){
	  playerpic=dog.picture;
	  playerpic.x=x;
	  playerpic.y=y;
	  HP=dog.hp;
	  weapon=dog.wpon;
	  weapon.picture[0].x=playerpic.x;
	  weapon.picture[0].y=playerpic.y;
	}
	else if (i==1){
	  playerpic=cat.picture;
	  playerpic.x=x;
	  playerpic.y=y;
	  HP=cat.hp;
	  weapon=cat.wpon;
	  weapon.picture[0].x=playerpic.x;
	  weapon.picture[0].y=playerpic.y;
	}
	else if (i==2){
	  playerpic=lion.picture;
	  playerpic.x=x;
	  playerpic.y=y;
	  HP=lion.hp;
	  weapon=lion.wpon;
	  weapon.picture[0].x=playerpic.x;
	  weapon.picture[0].y=playerpic.y;
	}
}

/*void Player::print_word(){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Color colort={255,255,255};
    SDL_Color colorb={0,0,0};
	TTF_Init();
    TTF_Font *font;
	font=TTF_OpenFont("INFROMAN.ttf", 20);
	SDL_Surface *text;
	text=TTF_RenderText_Shaded(font, "Enter name :\n", colort,colorb);
	SDL_Surface *background;
	background = SDL_SetVideoMode( 600, 400, 32, SDL_SWSURFACE );
    SDL_Rect re={200,200,0,0};
    SDL_BlitSurface( text, NULL, background, &re );
    SDL_Flip( background );
	SDL_Delay(2000);
  }*/

#endif