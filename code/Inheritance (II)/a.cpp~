#include <iostream>
using namespace std;

class Point2D{
public:
    Point2D(){ x = 0; y = 0; }
    void display() const{
	cout<<x<<","<<y<<endl;
    }
private:
    int x;
    int y;
};

class Circle{
public:
    Circle(Point2D &a, double b):center(a),radius(b){}
    void draw()const{
	cout<<"Center: ";
	center.display();
	cout<<"Radius: "<<radius<<endl;
    }
private:
    Point2D center;
    double radius;
};

class Triangle{
public:
    Triangle (Point2D *a):vertices(a){}
    ~Triangle(){ delete [] vertices; }
    void draw()const{
	cout<<"Vertices:"<<endl;
	for (int i=0; i<3; i++)
	    vertices[i].display();
    }
private:
    Point2D *vertices;
};

class Circle_in_Triangle: public Circle, public Triangle{
public:
    Circle_in_Triangle (Point2D &a, double b, Point2D *c):Circle(a,b), Triangle(c){}
    void draw()const{
	Circle::draw();
	Triangle::draw();
    }
};

int main(){
    Point2D p;
    Point2D *vec = new Point2D [3];
    Circle_in_Triangle ct(p, 0, vec);
    ct.draw();
    return 0;
}
