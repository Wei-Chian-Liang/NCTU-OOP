#include <iostream>
using namespace std;


class Point2D
{
 private:
 int *x;
 int *y;
 public:
 Point2D(int a, int b){x = new int (a);y=new int (b);}
 virtual ~Point2D(){delete x; delete y;}
 int getx(){return *x;}
 int gety(){return *y;}
}; 

class Shape
{
protected:
 int color;
public:
 virtual void draw() = 0;
 virtual bool is_closed() = 0;
 virtual ~Shape(){}
};

class Circle: public Shape{
public:
 Circle(Point2D &x, double y, int z):center(x),radius(y){color=z;}
 void draw(){
    cout<<"Color: "<<color<<endl
	<<"Center: "<<center.getx()<<","<<center.gety()<<endl
	<<"Radius: "<<radius<<endl;
 }
 bool is_closed() { return true; }
private:
 Point2D center;
 double radius;
};

int main(){
 Point2D pt(3,4);
 Circle c(pt,5,255);
 c.draw();
 return 0;
}
