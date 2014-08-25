#include <iostream>
using namespace std;

const int stackSize = 100;
int array[3 * stackSize];
int stackPointer[] = { -1, -1, -1 };

class stack{
public:
	int element(int stackNum){
		return (stackNum - 1)*stackSize + stackPointer[stackNum];
	}

	void push(int stackNum, int val){
		if (stackPointer[stackNum] + 1 > 0)
			cout << "out of space" << endl;
		stackPointer[stackNum]++;
		array[element(stackNum)] = val;

	}

	int pop(int stackNum){
		if (stackPointer[stackNum] == -1)
			cout << "empty stack" << endl;
		int value = array[element(stackNum)];
		stackPointer[stackNum]--;
		return value;
	}
};



stack Stack;
int main(){
	Stack.push(1, 4);
	Stack.push(2, 5);
	cout << Stack.pop(2) << endl;
	system("pause");
	return 0;
}
