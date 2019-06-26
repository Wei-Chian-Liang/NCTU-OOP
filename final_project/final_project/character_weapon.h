#include <iostream>
#include "public_tool.h"

using namespace std;

#ifndef CHARACTER_WEAPON_H
#define CHARACTER_WEAPON_H

const int weapon_picture_num=3;

void load_picture(struct picture *picture, string my_type, int my_start, int total);
void set_pic_coordi(struct picture &picture, float my_x, float my_y, float my_width, float my_height);
void set_x(struct picture *picture, float my_x);
void set_y(struct picture *picture, float my_y);

class Weapon
{
	public:
		int hit;
		int skillhit;
		float mass;
		struct picture picture[weapon_picture_num]; //store weapon, bullet, skill bullet
	    void set_hit(int h, int s) {
	        hit = h;
	        skillhit = s;
	        mass = 1;
	    }
};
class Dog
{
    public:
        int hp;
        Weapon wpon;
		struct picture picture;
        Dog() {
            hp = 125;
            wpon.set_hit(10, 17);
			load_picture(wpon.picture, "tool_", 0, 3);
			set_pic_coordi(wpon.picture[0], 0,0,50,50);
			set_pic_coordi(wpon.picture[1], 0,0,30,50);
			set_pic_coordi(wpon.picture[2], 0,0,60,100);
			load_picture(&picture, "character_", 0, 1);
			set_pic_coordi(picture, 0,340,70,70);
        }
};
class Cat
{
    public:
        int hp;
        Weapon wpon;
		struct picture picture;
        Cat() {
            hp = 100;
            wpon.set_hit(15, 20);
			load_picture(wpon.picture, "tool_" , 3, 3);
			set_pic_coordi(wpon.picture[0],0,0,50,50);
			set_pic_coordi(wpon.picture[1],0,0,30,30);
			set_pic_coordi(wpon.picture[2],0,0,50,30);
			load_picture(&picture, "character_", 1, 1);
			set_pic_coordi(picture, 0,340,70,70);
        }
};
class Lion
{
    public:
        int hp;
        Weapon wpon;
		struct picture picture;
        Lion() {
            hp = 150;
            wpon.set_hit(5, 7);
			load_picture(wpon.picture, "tool_" , 6, 3);
			set_pic_coordi(wpon.picture[0], 0,0,50,50);
			set_pic_coordi(wpon.picture[1], 0,0,30,30);
			set_pic_coordi(wpon.picture[2], 0,0,50,30);
			load_picture(&picture, "character_", 2, 1);
			set_pic_coordi(picture, 0,340,70,70);
        }
};

void load_picture(struct picture *picture, string my_type, int my_start, int total){
  for (int i=0; i<total; i++, my_start++){
	std::stringstream ss;
	ss<<my_start;
	string num = ss.str();
	picture->type = my_type;
	picture->stored = Loadpicture(picture->type, num);
	picture++;
  }
}

void set_pic_coordi(struct picture &picture, float my_x, float my_y, float my_width, float my_height){
  picture.set(my_x, my_y, my_width, my_height);
}

void set_x(struct picture *picture, float my_x){
  picture->x=my_x;
}
void set_y(struct picture *picture, float my_y){
  picture->y=my_y;
}

#endif
