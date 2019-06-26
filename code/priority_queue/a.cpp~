#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

class Message{
private:
    string name;
    int parameter;
    int priority_number;
public:
    Message (string x, int y, int z):name(x), parameter(y), priority_number(z){;}
    bool operator<(const Message &m) const{
	return (priority_number>=m.priority_number);
    }
    friend ostream &operator<<(ostream &out, const Message &mes){
	out<<mes.name<<" "<<mes.parameter;
	return out;
    }
};

int main(){
    priority_queue<Message> msg_queue;
    string command;

    while(cin>>command){
	if (cin.eof())
	    return 0;
	if (command=="GET"){
	    if (msg_queue.empty()==true)
		cout<<"EMPTY QUEUE!\n";
	    else{
		cout<<msg_queue.top()<<endl;
		msg_queue.pop();
	    }
	}
	if (command=="PUT"){
	    string name;
	    int parameter, priority_number;
	    cin>>name>>parameter>>priority_number;
	    msg_queue.push(Message(name, parameter, priority_number));
	}
    }
    return 0;
}
