#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <iomanip>
using namespace std;


class Point2D
{
private:
    int x;
    int y;
public:
    void set();
    bool operator<(Point2D &);
    friend ostream& operator<<(ostream&,Point2D);
};

template <class T>
T *new1D(int n, int k)
{
 T *vec = new T [n];
 return vec;
}

template <class T>
void rand1D(double *vec, int n)
{
    for (int i=0; i<n; i++)
	vec[i]=(rand()%1000)/100.00;
}

template <class T>
void rand1D(int *vec, int n)
{
    for (int i=0; i<n; i++)
	vec[i]=rand()%10;
}

template <class T>
void rand1D(char *vec, int n)
{
    for (int i=0; i<n; i++)
	vec[i]=rand()%26+97;
}

template <class T>
void rand1D(Point2D *vec, int n)
{
    for (int i=0; i<n; i++){
	vec[i].set();
    }
}

template <class T>
void display1D(T *vec, int n)
{
 cout << fixed << setprecision(2);
 for (int i = 0;i < n; i++)
     cout << vec[i] << " ";
 cout << endl;
}

template <class T>
void sort1D(T *vec, int n)
{
    for (int i=0; i<n; i++){
	for (int j=i; j<n; j++){
	    if (vec[j]<vec[i]){
		T temp=vec[j];
		vec[j]=vec[i];
		vec[i]=temp;
	    }
	}
    }
}

void Point2D::set(){
    x=rand()%10;
    y=rand()%10;
}

bool Point2D::operator<(Point2D &right)
{
    if (x < right.x)
	return true;
    if (x > right.x)
	return false;
    if (y < right.y)
	return true;
    return false;
}

ostream& operator<<(ostream& out, Point2D p2d)
{
    out << "("<< p2d.x<<","<<p2d.y<<")";
    return out;
}

template<class T>
void analysis(int n, int k = 0)
{
T *vec = new1D<T> (n, k);
rand1D<T>(vec,n);
// for int 1~10, for double 0.00~10.00, for char a~z,
// for Point2D x: 0~9 y:0~9
display1D<T>(vec,n);
sort1D<T>(vec,n);
display1D<T>(vec,n);
}

int main()
{
int n;
cout << "Enter n: ";
cin >> n;
srand(1);
analysis<int>(n);
analysis<double>(n);
analysis<char>(n);
analysis<Point2D>(n);
return 0;
}
