#include <iostream>
#include <stack>
using namespace std;

class StackWithMin{
public:
	void push(int value);
	void pop();
	int min();
	int top();
private:
	stack<int> realStack;
	stack<int> minStack;
};

void StackWithMin::push(int value)
{
	int currMin = 0;
	if (!minStack.empty())
		currMin = minStack.top();
	else
		currMin = INT_MAX;

	if (value < currMin)
		minStack.push(value);
	else
		minStack.push(minStack.top());

	realStack.push(value);
}

void StackWithMin::pop()
{
	if (realStack.empty() || minStack.empty()){
		cout << "stack empty!" << endl;
		return;
	}
	realStack.pop();
	minStack.pop();
}

int StackWithMin::min()
{
	if (realStack.empty() || minStack.empty())
	{
		cout << "stack empty!" << endl;
		return INT_MAX;
	}
	return minStack.top();
}

int StackWithMin::top()
{
	if (realStack.empty() || minStack.empty())
	{
		cout << "stack empty!" << endl;
		return -1;
	}

	return realStack.top();
}

int main()
{
	StackWithMin stk;
	for (int i = 0; i < 10; i++)
	{
		int value = rand() % 150;
		cout << "push : " << value << endl;
		stk.push(value);
	}
	cout << "Push 10 Elements and current min is : " << stk.min() << endl << endl;

	for (int i = 0; i < 5; i++)
	{
		int value = stk.top();
		cout << "pop : " << value << endl;
		stk.pop();
	}
	cout << "After pop 5 Elements, current min is : " << stk.min() << endl;
	system("pause");
	return 0;
}
