#include<iostream>
#include<fstream>
#include<queue>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* CreateBitree(TreeNode *pNode, fstream &fin)//level order create tree
		{
			int END_OF_TREE = '#';	
			int i = 0;
			int dat;
			fin>>dat;
			pNode = new TreeNode(dat);
			queue <TreeNode*> q;
			q.push(pNode);
			while (q.size() > 0 &&  dat != '*'){
				TreeNode* nd = q.front();
				q.pop();
				if (dat == END_OF_TREE)
					nd->left = NULL;
				else{
					nd->left = new TreeNode(dat);
					cout<<dat<<" ";
					q.push(nd->left);
				}


				fin>>dat;
				if (dat == END_OF_TREE)
					nd->right= NULL;
				else{
					nd->right= new TreeNode(dat);
					cout<<dat<<" ";
					q.push(nd->right);
				}

				i = i + 2;
				fin>>dat;
			}
			return pNode;
		}
int maxProfit(vector<int> &prices) {  
	if(prices.size() == 0 ||prices.size() == 1 )
		return 0;
	int* profit = new int[prices.size()-1];
	for (int i =0; i<prices.size()-1; i++)
		profit[i]  = prices[i+1]-prices[i];

	int max = profit[0];
	int cur = profit[0];

	for(int i = 1; i<prices.size()-1; i++){
		if( cur < 0)
			cur = profit [i];
		else 
			cur = cur+ profit[i];

		if(max < cur)
			max = cur;
	}

	return max<0?0:max;  

}
int maxProfit2(vector<int> &prices) {
    if(prices.size() == 0 || prices.size() == 1)
    	return 0; 
    int *profit = new int[prices.size()-1];
    for(int i = 0; i<prices.size()-1; i++)
    	profit[i] =  prices[i+1]-prices[i];
    int max = 0;
    for(int i = 0; i < prices.size()-1; i++){
    	if(profit[i]>0)
    		max +=profit[i];
    }
    return max;
}
int maxProfit3(vector<int> &prices) {
    if(prices.size() == 0 || prices.size() == 1)
    	return 0; 
    int *profit = new int[prices.size()-1];
    for(int i = 0; i<prices.size()-1; i++)
    	profit[i] =  prices[i+1]-prices[i];
    int max = 0;
    std::vector<int> vm;
    int m = 0;
    for(int i = 0; i < prices.size()-1; i++){
    	int max_pre = max;
    	if(profit[i]>0)
    		max += profit[i];
    	if(max_pre> max){

    		vm.push_back(max_pre);
			max = 0;
    		
    	}

    }
    int tmp = vm.back();
    int max_value = tmp;
    while(vm.size()>0){
    	

    	vm.pop_back();
    	tmp = vm.back();
    	if(max_value<tmp)
    		max_value = tmp;
    }
    return max_value;

}

void main(){
		fstream fin("tree.txt");
		int tree[] = {1, 2, 3, '#', '#', 4, '#', '#', 5 };
		TreeNode *pRoot = NULL;
		pRoot = CreateBitree(pRoot, fin);
		cout<<pRoot->val<<endl;

		int price[] = {3,2,6,5,0,3};
		vector<int> prices;
		for(int i = 0; i<6;i++)
			prices.push_back(price[i]);

		cout<<maxProfit3(prices)<<endl;
		system("pause");
}


