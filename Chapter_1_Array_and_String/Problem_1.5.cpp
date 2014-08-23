#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

string compressedString(string str){
	string a;
	a = new char[100];
	int cnt = 1, j = 0;
	for (int i = 0; i < str.length(); i++){
		a[j] = str[i];
		//to_string(cnt);
		a[j + 1] = (char)(((int)'0') + cnt);
		if (str[i + 1] == str[i]) 
			cnt++;
		else{
			j += 2;
			cnt = 1;
		}			
	}
	a[j] = '\0';
	a.c_str();
	string b (a.data());
	if ( b.length() > str.length())		
		return str;
	else
		return b;

}

int main(){
	cout << compressedString("aaaaaaaabbbbbbbsasds") << endl;
	system("pause");
	return 0;
}
