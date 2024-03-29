/* CC150  Question 3.3
Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold.
Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks,
and should create a new stack once the previous one exceeds capacity. SetOfStacks.push()
and SetOfStacks.pop() should behave identically to a single stack (that is, pop() should
return the same values as it would if there were just a single stack).

FOLLOW UP

Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.


*/


#include<iostream>
#include <stack>
using namespace std;

#define STACK_NUM 100





class SetOfStacks{
public:

	int num = 0;
	int capacity = 2;
	stack<int> stacks[100];

	int count = 0;

	void push(int v){
		if (isFull() == 0)
			stacks[num].push(v);
		else {
			num++;
			stacks[num].push(v);
		}
	}

	void pop(){
		if (stacks[num].empty() == 0)
			stacks[num].pop();
		else {
			num--;
			stacks[num].pop();
		}
	}

	int popAt(int index){ //do pop on specific stack
		return stacks[index].top();
	}

	bool isFull(){
		if (stacks[num].size() == capacity)
			return true;
		else 
			return false;
	}

	bool isEmpty(){
		if (stacks[num].size() == 0)
			return true;
		else return false;
	}
	int top(){
		return stacks[num].top();
	}
};

SetOfStacks Stack;
int main(){

	Stack.push(5);
	Stack.push(2);
	Stack.push(3);
	Stack.push(7);
	Stack.pop();
	Stack.push(10);
	Stack.popAt(0);
	Stack.popAt(1);
	cout << Stack.popAt(0) << endl;
	cout << Stack.top() << endl;
	system("pause");
	return 0;

}
