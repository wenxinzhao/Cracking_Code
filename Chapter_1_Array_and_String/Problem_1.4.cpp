#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;



void replaceSpace( string str){
	string res;
	for (int i = 0; i < str.length(); i++){
		if (str[i] == ' ')  res += "%20";
		else res += str[i];
	}
}

int main(){

	replaceSpace("asad sa a");
	system("pause");
	return 0;
}
