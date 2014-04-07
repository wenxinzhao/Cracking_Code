#include<iostream>
#include<algorithm>
using namespace std;

bool anagram(string s1, string s2){
	int a = s1.length();
	int b = s2.length();
	sort(&s1[0], &s1[0] + a);
	sort(&s2[0], &s2[0] + b);
	return s1 == s2;


}
void exchange(string &a1, string &a2){
	string t = a1;
	a1 = a2;
	a2 = t;
}

int main(){
	string array[] = {
		"live", "ga", "evil", "abc", "cba", "qwer", "ag"
	};
	cout << anagram(array[0], array[1]) << endl;
	for (int i = 0; i < 7; i++){
		for (int j = i+1; j < 7; j++){
			if (anagram(array[i], array[j]))
				exchange(array[i + 1], array[j]);
		}
	}
		
	cout << anagram(array[0], array[1]) << endl;

		
	system("pause");
	
}
