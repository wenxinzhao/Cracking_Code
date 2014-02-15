/*
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

*/



#include<iostream>
using namespace std;
#define MAX3(a,b,c) (a>b?(a>c?a:c):(b>c?b:c))
#define MAX2(a, b)  (((a) > (b)) ? (a) : (b))

int J;
void main(){
	char *ch[] = {
		"75 00 00 00 00 00 00 00 00 00 00 00 00 00 00",
		"95 64 00 00 00 00 00 00 00 00 00 00 00 00 00",
		"17 47 82 00 00 00 00 00 00 00 00 00 00 00 00",
		"18 35 87 10 00 00 00 00 00 00 00 00 00 00 00",
		"20 04 82 47 65 00 00 00 00 00 00 00 00 00 00",
		"19 01 23 75 03 34 00 00 00 00 00 00 00 00 00",
		"88 02 77 73 07 63 67 00 00 00 00 00 00 00 00",
		"99 65 04 28 06 16 70 92 00 00 00 00 00 00 00",
		"40 41 26 56 83 40 80 70 33 00 00 00 00 00 00",
		"41 48 72 33 47 32 37 16 94 29 00 00 00 00 00",
		"53 71 44 65 25 43 91 52 97 51 14 00 00 00 00",
		"70 11 33 28 77 73 17 78 39 68 17 57 00 00 00",
		"91 71 52 38 17 14 91 43 58 50 27 29 48 00 00",
		"63 66 04 68 89 53 67 30 73 16 69 87 40 31 00",
		"04 62 98 27 23 09 70 98 73 93 38 53 60 04  "
	};
	int data[15][15];
	int i;
	for (i = 0; i < 15; i++){
		sscanf_s(ch[i], "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
			data[i], data[i] + 1, data[i] + 2, data[i] + 3, data[i] + 4, data[i] + 5, data[i] + 6, data[i] + 7,
			data[i] + 8, data[i] + 9, data[i] + 10, data[i] + 11, data[i] + 12, data[i] + 13, data[i] + 14);
	}
	int obj = data[0][0];
	J = 0;
	for (i = 0; i < 14;i++){
		for (int j = J; j <= i; j++){
			if (J == 0){
				if (data[i + 1][j] > data[i + 1][j + 1]){
					obj += data[i + 1][j];
					J = j;
				}

				else {
					obj += data[i + 1][j + 1];
					J = j + 1;
				}
				break;
			}


			else if (j >= 1)
				if (data[i + 1][j - 1] > data[i + 1][j] && data[i + 1][j - 1] > data[i + 1][j + 1]){
					obj += data[i + 1][j - 1];
					J = j - 1;
				}
				else if (data[i + 1][j] > data[i + 1][j-1] && data[i + 1][j ] > data[i + 1][j + 1]){
					obj += data[i + 1][j];
					J = j ;
				}
				else{
					obj += data[i + 1][j+1];
					J = j+1;
				}

				break;
			 
		}
	}
	cout<<obj<<endl;
	system("pause");
}

