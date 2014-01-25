/*输入一个表示整数的字符串，把该字符串转换成整数并输出，
例如输入字符串"345"，则输出整数345。 给定函数原型
int StrToIntconst char *str) ，完成函数StrToInt，
实现字符串转换成整数的功能，不得用库函数atoi

1/25/2014
Terry  */

#include<iostream>
using namespace std;

long value;
int StrToInt(const char *str){
	if (*str == NULL)
		value = 0;
	else if (*str == '-'){
		str = str + 1;
		while (*str != '\0')
		{

			value = value * 10 + (*str - '0');

			str = str + 1;
		}
		value = -value;
	}
	else if (*str == '+'){
		str = str + 1;

		while (*str != '\0')
		{

			value = value * 10 + (*str - '0');

			str = str + 1;
		}
	}
	return value;
}

int main(){

	const char *a = "+133";
	value = StrToInt(a);
	cout << value << endl;
	getchar();
}
