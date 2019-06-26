#include <iostream>
using namespace std;

class Point2D
{
private:
int *x;
int *y;
public:
Point2D(){x = new int (0);y=new int (0);}
Point2D(int a, int b){x = new int (a);y=new int (b);}
virtual ~Point2D(){delete x; delete y;}
void setPoint2D(int a, int b){*x=a; *y=b;}
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
virtual double area() = 0;
};

class Polygon: public Shape
{
public:
bool is_closed() { return true; }
};

class Triangle: public Polygon
{
public:
    Triangle(Point2D *a){
	vertices=new Point2D[3];
	for (int i=0; i<3; i++)
	    vertices[i].setPoint2D(a[i].getx(), a[i].gety());
    }
    ~Triangle() { delete [] vertices; }
    double area(){
	Point2D v1(vertices[1].getx()-vertices[0].getx(), vertices[1].gety()-vertices[0].gety());
	Point2D v2(vertices[2].getx()-vertices[0].getx(), vertices[2].gety()-vertices[0].gety());
	return (v1.gety()*v2.getx()-v1.getx()*v2.gety())/2.00;
    }
    void draw(){}
private:
    Point2D *vertices;
};

class Circle: public Shape
{
public:
    Circle (Point2D a, int b):center(a), radius(b){}
    void draw(){}
    bool is_closed() { return true; }
    double area(){
	return 3.14*radius*radius;
    }
private:
    Point2D center;
    double radius;
};

class Rectangle: public Shape{
public:
    Rectangle (Point2D *a){
	vertices=new Point2D[4];
	for (int i=0; i<3; i++)
	    vertices[i].setPoint2D(a[i].getx(), a[i].gety());
    }
    double area(){
	Point2D v1(vertices[1].getx()-vertices[0].getx(), vertices[1].gety()-vertices[0].gety());
	Point2D v2(vertices[2].getx()-vertices[0].getx(), vertices[2].gety()-vertices[0].gety());
	return (v1.getx()*v2.gety()-v1.gety()*v2.getx());
    }
    void draw(){}
    bool is_closed() { return true; }
private:
    Point2D *vertices;
};

int main()
{
Point2D pt(3,4);
Circle cir(pt, 5);

Point2D *vec = new Point2D [3];
vec[0].setPoint2D(1,1);
vec[1].setPoint2D(1,6);
vec[2].setPoint2D(8,1);
Triangle tri(vec);
delete []vec;

vec = new Point2D [4];
vec[0].setPoint2D(1,1);
vec[1].setPoint2D(6,1);
vec[2].setPoint2D(6,6);
vec[3].setPoint2D(1,6);
Rectangle rect(vec);
delete [] vec;

Shape *collection[3];
collection[0] = &cir;
collection[1] = &tri;
collection[2] = &rect;

cout << "Area of Circle: " << collection[0]->area()
<< endl;
cout << "Area of Triangle: " << collection[1]->area()
<< endl;
cout << "Area of Rectangle: " << collection[2]->area()
<< endl;

return 0;
}
