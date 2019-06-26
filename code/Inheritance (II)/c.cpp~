#include <iostream>
#include <iomanip>
using namespace std;

class Shape{
public:
    Shape():color(255){}
protected:
    int color;
};

class Point2D{
public:
    Point2D(int a=0, int b=0):x(a),y(b){}
    void display() const{
	cout<<x<<","<<y<<endl;
    }
    void set (int a, int b){
	x=a;
	y=b;
    }
    int getx(){return x;}
    int gety(){return y;}
private:
    int x;
    int y;
};

class Circle:virtual public Shape{
public:
    Circle(Point2D &a, double b):center(a),radius(b){}
    void draw()const{
	cout<<"Center: ";
	center.display();
	cout<<"Radius: "<<radius<<endl;
    }
    double area(){
	return 3.14*radius*radius;
    }
private:
    Point2D center;
    double radius;
};

class Triangle:virtual public Shape{
public:
    Triangle (Point2D *a):vertices(a){}
    ~Triangle(){ delete [] vertices; }
    void draw()const{
	cout<<"Vertices:"<<endl;
	for (int i=0; i<3; i++)
	    vertices[i].display();
    }
    double area(){
	Point2D v1(vertices[1].getx()-vertices[0].getx(), vertices[1].gety()-vertices[0].gety());
	Point2D v2(vertices[2].getx()-vertices[0].getx(), vertices[2].gety()-vertices[0].gety());
	return (v1.getx()*v2.gety()-v1.gety()*v2.getx())/2.00;
    }
private:
    Point2D *vertices;
};

class Circle_in_Triangle: public Circle, public Triangle{
public:
    Circle_in_Triangle (Point2D &a, double b, Point2D *c):Circle(a,b), Triangle(c){}
    void draw()const{
	cout << "Circle's color: " << Circle::color << endl;
	cout << "Triangle's color: " << Triangle::color << endl;
	Circle::draw();
	Triangle::draw();
    }
    double area(){
	return Triangle::area()-Circle::area();
    }
};

int main(){
    Point2D p(2,2);
    Point2D *vec = new Point2D [3];
    vec[0].set(1,1);
    vec[1].set(3,1);
    vec[2].set(1,6);
    Circle_in_Triangle ct(p, 1, vec);
    ct.draw();
    cout << "Area of Circle: " << ct.Circle::area() << endl;
    cout << "Area of Triangle: " << fixed<<setprecision(2)<<ct.Triangle::area() << endl;
    cout << "Area of Circle_in_Triangle: " << ct.area() << endl;
    return 0;
}
