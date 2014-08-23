#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;




void reverse(char * str){
	char tmp;
	int n = strlen(str);
	for (int i = 0; i < n/2; i++ ){
		tmp = str[i];
		str[i] = str[n - i - 1];
		str[n - i - 1] = tmp;
	}
}


int main(){
	
	char s[] = "abcd";
	reverse(s);
	system("pause");
	return 0;
}
