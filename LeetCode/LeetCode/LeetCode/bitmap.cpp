#include"bitmap.h"

//-------------Bit Map---------------------
bitmap::bitmap(int n) {
	len = n / 32 + 1;
	map = new unsigned int[len];
	reversemap = new unsigned int[len];


	for (int i = 0; i < len; i++) {
		map[i] = 0;
		reversemap[i] = 0;
		zero = false;
	}
}

void bitmap::set(int k) {
	bool reverse = true;
	if (k == 0) {
		zero = true;
	}
	else if (k < 0) {
		reverse = false;
		k = -k;
	}
	int a = k / 31;
	int b = k % 31;


	if (a >= len) {
		return;
	}
	else {
		if (reverse) {
			int tmp = reversemap[a] / pow(2, b);
			if (tmp % 2 == 0) {
				reversemap[a] += pow(2, b);
			}
		}
		else {
			int tmp = map[a] / pow(2, b);
			if (tmp % 2 == 0) {
				map[a] += pow(2, b);
			}
		}
	}
}

bool bitmap::val(int k) {
	bool reverse = true;
	if (k == 0) {
		return zero;
	}
	else if (k < 0) {
		reverse = false;
		k = -k;
	}
	int a = k / 31;
	int b = k % 31;


	if (a >= len) {
		return false;
	}
	else {
		if (reverse) {
			int tmp = reversemap[a] / pow(2, b);
			if (tmp % 2 == 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			int tmp = map[a] / pow(2, b);
			if (tmp % 2 == 1) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}
//------------------------------------------