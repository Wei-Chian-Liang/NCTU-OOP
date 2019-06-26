#ifndef POINT4D_H
#define POINT4D_H
#include <iostream>
using namespace std;
class Point4D:public Point2D
{
public:
    Point4D(int n1 = 0,int n2 = 0,int n3 = 0,int n4 = 0):Point2D(n1,n2){
	z=new int(n3);
	t=new int(n4);
    }
    void display() const{
	Point2D::display();
	cout << "," << *z << "," << *t;
    }
    void operator = (const Point2D &d){
	Point2D::reset(d);
	*z=7;
	*t=8;
    }
private:
int *z;
int *t;
};
#endif
