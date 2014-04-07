#include<iostream>
using namespace std;
typedef struct node{
	int val, min;
}node;

const int stackSize = 100;
node buffer[stackSize];

int stackNum = 0;
int minValue = 1000;

int min(){
	minValue = buffer[stackNum].min;
	return minValue;
}
void push(int value){	
	buffer[stackNum].val  = value;
	stackNum++;
	if (minValue > value)
		minValue = value;
	buffer[stackNum].min = minValue;

}

int pop(){

	int value = buffer[stackNum-1].val;
	buffer[stackNum-1].val = 0;
	
	minValue = buffer[stackNum - 1].min;
	stackNum--;
	return value;
}



int main(){
	push(5);
	push(2);
	push(3);
	push(7);
	pop();
	pop();
	pop();
	cout << min() << endl;
	system("pause");
	return 0;
}


///////----save space version--------------------------
#include<iostream>
using namespace std;


const int stackSize = 100;
int buffer[stackSize];
int bufferMin[stackSize] = { 1000 };

int stackNum = 0;
int stackNumMin = 0;
int minValue = 1000;

int min(){
	minValue = bufferMin[stackNumMin-1];
	return minValue;
}

void push(int value){	
	buffer[stackNum]  = value;
	stackNum++;
	if (minValue > value){
		minValue = value;
		bufferMin[stackNumMin] = minValue;
		stackNumMin++;
	}
	

}

int pop(){
	stackNum--;

	int value = buffer[stackNum];
	buffer[stackNum] = 0;
	
	if (bufferMin[stackNumMin - 1] == value){
		stackNumMin--;
	}
	
	return value;
}



int main(){
	push(5);
	push(9);
	push(3);
	push(1);
	push(4);
	//pop();
	pop();
	//pop();
	cout << min() << endl;
	system("pause");
	return 0;
}
