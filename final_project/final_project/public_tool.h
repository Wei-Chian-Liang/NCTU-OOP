#include "include.h"

#ifndef PUBLIC_TOOL_H
#define PUBLIC_TOOL_H


GLuint Loadpicture(const string &type, string num);//ex:"word_0" the "word_" is type, and the "0" is num

struct picture{
  picture(){stored=0; x=y=0; width=600; height=400; vx=0; vy=0; exist=true;}
  string type;
  unsigned int stored; //used for storing picture
  float x;
  float y;
  float width;
  float height;
  float vx;
  float vy;

  bool exist; //judge the picture is exist(true) or not exist(false)
  void set(float my_x, float my_y, float my_width, float my_height){
	x=my_x; y=my_y; width=my_width; height=my_height;
  }
  void set_vx(float new_vx){vx=new_vx;}
  void set_vy(float new_vy){vy=new_vy;}
};

void showpicture(picture &p);

#endif