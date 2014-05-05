#include<iostream>
#include<algorithm>
using namespace std; 

bool compare(string &a, string &b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int pa = 0, pb = 0; pb < b.length();)
	{
		while ((pa < a.length()) && (a[pa] < b[pb]))
		{
			++pa;
		}
		if ((pa >= a.length()) || (a[pa] > b[pb]))
		{
			return false;
		}
		//a[pa] == b[pb]
		++pb;
	}
	return 1;
}

int main()
{


	string  a = "ABCDEFGHLMNOPQRS";
	string b = "DCGSRQPZ";
	cout<<compare(a,b);
	getchar();

}
