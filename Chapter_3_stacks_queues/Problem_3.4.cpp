#include <iostream>
#include <stack>
using namespace std;
class Tower{
	int index;
	stack<int> disks;
public:
	Tower(int i){
		index = i;
	}
	void add(int i) {
		disks.push(i);
	}
	int getIndex() {
		return index;
	}
	void pushDisk(int disk) {
		
		disks.push(disk);
	}
	void moveTopto(Tower *to) {

		int top_disk = disks.top();
		to->pushDisk(top_disk);
		disks.pop();
		cout << "moving disk " << top_disk << " from " << index << " to " << to->getIndex() << endl;
	}
	void hanoi(int n, Tower *right, Tower *middle) {

		if (n == 1) {
			moveTopto(right);
		}
		else {
			hanoi(n - 1, middle, right);
			moveTopto(right);
			middle->hanoi(n - 1, right, this);
		}
	}
};
int main() {
	Tower *towers[3];
	for (int i = 0; i < 3; i++) {
		towers[i] = new Tower(i);
	}
	
	int N = 5;
	for (int i = N; i > 0; i--) {
		towers[0]->add(i);
	}

	towers[0]->hanoi(N, towers[2], towers[1]);
	system("pause");
	return 0;
}
