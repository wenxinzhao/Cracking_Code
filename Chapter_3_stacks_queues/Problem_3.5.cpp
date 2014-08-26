#include <iostream>
#include <stack>
using namespace std;

template <typename T> // use for diff data type
class myQueue{
private:
	stack<T> stackin;
	stack<T> stackout;
public:
	myQueue(){
	};
	~myQueue(){
	};
	void push(T val){
		stackin.push(val);
	}
	void pop(){
		move(stackin, stackout);
		stackout.pop();
	}
	void move(stack<T> &src, stack<T> &dst){
		while (!src.empty()){
			dst.push(src.top());
			src.pop();
		}
	}
	T front(){
		move(stackin, stackout);
		return stackout.top();
	}
	T back(){
		move(stackout, stackin);
		return stackin.top();
	}
	int size(){
		return stackin.size() + stackout.size();
	}

	bool empty(){
		return stackin.empty() && stackout.empty();
	}
};

int main(){
	myQueue<int> myQ;
	myQ.push(1);
	myQ.push(2);
	myQ.push(3);
	myQ.pop();
	cout << myQ.front() <<" "<<myQ.back()<< endl;
	system("pause");
	return 0;	
}

