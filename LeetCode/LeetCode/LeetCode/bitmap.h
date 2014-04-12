#include<iostream>
using namespace std; 

class bitmap {
public: bitmap(int n); ~bitmap();
		void set(int k);
		bool val(int k);


private: int len;
		 unsigned int * map;
		 unsigned int * reversemap;
		 bool zero;
};