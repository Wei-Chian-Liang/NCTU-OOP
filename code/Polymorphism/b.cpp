#include <iostream>
using namespace std;

class Shape
{
protected:
int color;
public:
virtual void draw() = 0;
virtual bool is_closed() = 0;
virtual ~Shape(){}
};

class Point2D
{
private:
int *x;
int *y;
public:
Point2D(){x = new int (0);y=new int (0);}
virtual ~Point2D(){delete x; delete y;}
void setPoint2D(int a, int b){*x=a; *y=b;}
int getx(){return *x;}
int gety(){return *y;}
};

class Polygon: public Shape
{
public:
bool is_closed() { return true; }
};

class Triangle: public Polygon
{
public:
    Triangle(Point2D *a, int b){
	vertices=new Point2D[3];
	for (int i=0; i<3; i++)
	    vertices[i].setPoint2D(a[i].getx(), a[i].gety());
       	color=b;
    }
    ~Triangle() { delete [] vertices; }
    void draw(){
	cout<<"Color: "<<color<<endl
	   <<"Vertices:"<<endl;
	for (int i=0; i<3; i++){
	    cout<<vertices[i].getx()<<","<<vertices[i].gety()<<endl;
	}
    }
private:
Point2D *vertices;
};

int main()
{
Point2D *vec = new Point2D[3];
vec[0].setPoint2D(1,1);
vec[1].setPoint2D(6,1);
vec[2].setPoint2D(1,8);
Triangle t(vec,255);
delete []vec;
t.draw();
return 0;
}
