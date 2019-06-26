#ifndef POINT2D_H
#define POINT2D_H
#include <iostream>
using namespace std;
class Point2D
{
public:
    Point2D(int n1=0, int n2=0){
	x=new int(n1);
	y=new int(n2);
    }
    void display()const{
	cout<< *x << "," << *y;
    }
    void reset(const Point2D &d){
	x=d.x;
	y=d.y;
    }
private:
int *x;
int *y;
};
#endif
