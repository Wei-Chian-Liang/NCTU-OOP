#include <iostream>
#include <string.h>
#include <iomanip>
#include <map>
using namespace std;

class Book {
    string Name; // name of book
    int Number; // how many books in your store
public:
    Book(){;}
    Book(string _name, int _number):Name(_name),Number(_number){}
    friend ostream &operator <<(ostream &out, const Book &book){
	out<<setw(20)<<book.Name<<setw(7)<<book.Number;
    }
    void sell(){
	cout<<"enter sell number\n";
	int sellnum;
	cin>>sellnum;
	Number=Number-sellnum;
    }
};

int main() {
    map<int, Book> BookMap;
    BookMap[1] = Book("C++ Programing", 1);
    BookMap[2] = Book("Java", 2);
    BookMap[3] = Book("Python", 3);
    int count=3;
    int step;
    while(1) {
	cout <<"1. show information of book store" << endl;
	cout <<"2. add new books" << endl;
	cout <<"3. sell books " << endl;
	cout <<"4. exit" << endl;
	cin >> step;
	if(step==1) {
	    cout<<setw(3)<<"ID"<<setw(20)<<"Name"<<setw(10)<<"Number\n";
	    for (map<int, Book>::const_iterator iter=BookMap.begin(); iter!=BookMap.end(); iter++){
		cout<<setw(3)<<iter->first<<iter->second<<endl;
	    }
	}
	else if(step==2) {
	    cout <<"enter Name and Number of new book"<<endl;
	    string name;
	    getline(cin, name,'\n');
	    getline(cin, name,'\n');
	    int number;
	    cin>>number;
	    count++;
	    BookMap[count]=Book(name, number);
	}	
	else if(step==3) {
	    cout << "enter sell id" << endl;
	    int id;
	    cin>>id;
	    BookMap[id].sell();
	}      
	else if(step==4) {
	    break;
	}
    }
    return 0;
}
