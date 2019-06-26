#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;
class Complex{
public:
    Complex();
    Complex(double , double);
    friend bool operator < (const Complex& ,const Complex& );
    friend ostream &operator << (ostream &out, const Complex &p){
        out << "(" << p.x << "," << p.y << ")";
    }
    //friend void sort(vector,vector);
private:
    double x,y;
};
bool operator < (const Complex& a,const Complex& b) {
    if (a.x < b.x)
	return 0;
    if (a.x == b.x && a.y < b.y)
	return 0;
    return 1;
}
void ReadFile(ifstream& infile, vector<Complex>& vec) {
    char temp[10];
    double num[2];
    char *start=temp;
    int i=0;
    while (infile.getline(temp, 10)){
	start=temp;
	start=strtok(start, " ");
	for (int k=0; start!=NULL; k++){
	    char t[30];
	    strcpy(t, start);
	    num[k]=strtod(t,NULL);
	    start=strtok(NULL, " ");
	}
	vec.push_back(Complex(num[0], num[1]));
    }
    infile.close();
}
int main(int argc, char** argv) {
    if(argc != 2) return 0;
    ifstream infile(argv[1]);
    if(!infile.is_open()) {
	cout << "can not oepn file " << endl;
	return 0;
    }
    vector<Complex> vec;
    ReadFile(infile, vec);
    cout << "Original sequence:" << endl;
    for(size_t i = 0; i< vec.size(); i++)
	cout << vec[i] <<" ";
    cout << endl;
    sort(vec.begin(),vec.end());
    cout << "Sorted sequence:" << endl;
    for(size_t i = 0; i< vec.size(); i++)
	cout << vec[i] <<" ";
    cout << endl;
    return 0;
}

Complex::Complex(){
    x=0;
    y=0;
}

Complex::Complex(double tx, double ty){
    x=tx;
    y=ty;
}
