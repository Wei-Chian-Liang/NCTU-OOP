#include "include.h"
#include "public_tool.h"

#ifndef PAGE_BASE_H
#define PAGE_BASE_H

struct page_base{
  page_base(int *num);
  void loadpicture(string &my_type, int my_start, int total);
  void show(string &my_type, int my_num);
  int judge_type(string &my_type);

  struct picture *picture[4]; //store 4 picture types
};

#endif