


#include <iostream>
#include <cstring>
using namespace std;

//void swap(char &a, char &b){
//	a = a^b;
//	b = a^b;
//	a = a^b;
//}
//
//void reverse2(char *s){
//	int n = strlen(s);
//	for (int i = 0; i<n / 2; ++i)
//		swap(s[i], s[n - i - 1]);
//}
//
//void reverse1(char *s){
//	if (!s) return;
//	char *p = s, *q = s;
//	while (*q) ++q;
//	--q;
//	while (p < q)
//		swap(*p++, *q--);
//}
void reverse(char *str)
{
	char* end = str;
	char tmp;
	if (str){
		while (*end){
			++end;

		}
		--end;


		while (str < end)
		{
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
	}
}

int main(){
	char s[] = "1234567890";
	reverse(s);
	cout << s << endl;
	getchar();
	return 0;
}