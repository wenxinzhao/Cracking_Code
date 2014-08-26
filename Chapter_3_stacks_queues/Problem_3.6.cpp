/*
Write a program to sort a stack in ascending order. 
You should not make any assumptions about how the stack is implemented. 
The following are the only functions that should be used to write this program: 
push | pop | peek | isEmpty.

Terry
8/26/2014
*/

#include<iostream>
#include<stack>
using namespace std;

stack<int> box1,box2;

stack<int> sort(stack<int>src, stack<int>dst){
	dst.push(src.top());
	src.pop();
	int tmp ;
	while (!src.empty()){
		tmp = src.top();
		src.pop();
		if (tmp > dst.top()){ //tmp > dst.top
			dst.push(tmp);
			
		}
		else // temp <= dst.top
		{
			
			while (dst.top() > tmp ){
					src.push(dst.top());
					dst.pop();
					if (dst.empty()) break;					
			} 
			
			dst.push(tmp);			
			dst.push(src.top());
			src.pop();
		}
	
	}
				
	return dst;
}


void main(){
	
	int a[15] = { 43,7,5, 2, 8, 3, 9 ,12,51,21,56,13,34,1,0};
	for (int i = 0; i < 15; i++)
	{
		box1.push(a[i]);
	}
	
	cout << sort(box1, box2).top() << endl;
	system("pause");

}
