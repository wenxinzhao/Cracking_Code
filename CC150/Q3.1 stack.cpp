#include<iostream>
using namespace std;

const int stackSize = 100;
int buffer[stackSize * 3] ;
int stackPointer[] = {-1,-1,-1};

int absTopOfStack(int stackNum){
	return stackNum*stackSize + stackPointer[stackNum];
}

void push(int stackNum, int value){
	if (stackPointer[stackNum] + 1 >= stackSize)
		cout << "out of space";

	stackPointer[stackNum]++;
	buffer[absTopOfStack(stackNum)] = value;
}

int pop(int stackNum){
	if (stackPointer[stackNum] == -1)
		cout << "empty stack";
	int value = buffer[absTopOfStack(stackNum)];
	buffer[absTopOfStack(stackNum)] = 0;
	stackPointer[stackNum]--;
	return value;	
}

int peek(int stackNum){
	int index = absTopOfStack(stackNum);
	return buffer[index];
}


int main(){
	push(0, 4);
	push(0, 7);
	push(0, 8);
	cout<<peek(0)<<endl;
	pop(0);
	cout << peek(0);
	getchar();
}
