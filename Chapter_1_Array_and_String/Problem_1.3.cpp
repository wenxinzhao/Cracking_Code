#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;



bool permutation(string s, string t){
	if (s.length() != t.length())
		return false;
	int checker = 0;
	for (int i = 0; i < s.length(); i++ ){
		int val = s[i] - 'a';
		checker |= (1 << val);
	}
	for (int i = 0; i < t.length(); i++){
		int val = t[i] - 'a';
		checker ^= (1 << val);
	}
	return checker == 0 ? true: false;
}

int main(){

	cout << permutation("abc", "caa") << endl;
	system("pause");
	return 0;
}
