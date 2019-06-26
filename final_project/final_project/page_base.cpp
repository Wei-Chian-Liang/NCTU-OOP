#include "page_base.h"


int page_base::judge_type(string &my_type){
  string type[4] = {"background_", "word_", "character_", "tool_"};
  for (int i=0; i<4; i++)
	if (my_type == type[i])
	  return i;
}

void page_base::loadpicture(string &my_type, int my_start, int total){
  int typenum = judge_type(my_type);
  for (int i=0; i<total; i++, my_start++){
	std::stringstream ss;
	ss<<my_start;
	string num = ss.str();
	picture[typenum][i].type = my_type;	
	picture[typenum][i].stored = Loadpicture(picture[typenum][i].type, num);
  }
}

page_base::page_base(int *num){
  string type[4] = {"background_", "word_", "character_", "tool_"};
  int total[4] = {num[0], num[1], num[2], num[3]};
  picture[0] = new struct picture [num[0]];
  picture[1] = new struct picture [num[1]];
  picture[2] = new struct picture [num[2]];
  picture[3] = new struct picture [num[3]];
  for (int i=0; i<4; i++)
	if (total != 0)
	  page_base::loadpicture(type[i], num[4], total[i]);
}


void page_base::show(string &my_type, int my_num){
  int typenum = judge_type(my_type);
  if (picture[typenum][my_num].exist == false)
	return;
  showpicture(picture[typenum][my_num]);
}