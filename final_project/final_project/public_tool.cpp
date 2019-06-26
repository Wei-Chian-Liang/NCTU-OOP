#include "public_tool.h"

GLuint Loadpicture(const string &type, string num){
  string fileName("./picture/");
  fileName += type;
  fileName += num;
  fileName += ".png";

  SDL_Surface *image = IMG_Load( fileName.c_str() );
 
  SDL_DisplayFormatAlpha(image);
 
  unsigned object(0);
 
  glGenTextures(1, &object);
 
  glBindTexture(GL_TEXTURE_2D, object);
 
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
   
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->w, image->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);
 
  //Free surface
  SDL_FreeSurface(image);
 
  return object;
}

void showpicture(picture &p){
  p.x+=p.vx;
  p.y-=p.vy;
  glColor4ub(255,255,255,255); //White color

  //Enable textures when we are going to blend an texture
  glEnable(GL_TEXTURE_2D);

  glBindTexture(GL_TEXTURE_2D,p.stored); 
  //Render screen size rect and bind a texture to it
  glBegin(GL_QUADS);

  glTexCoord2d(0,0); glVertex2f(p.x,p.y);
  glTexCoord2d(1,0); glVertex2f(p.x+p.width,p.y);
  glTexCoord2d(1,1); glVertex2f(p.x+p.width,p.y+p.height);
  glTexCoord2d(0,1); glVertex2f(p.x,p.y+p.height);
  
  glEnd();
	  
  glDisable(GL_TEXTURE_2D);
}