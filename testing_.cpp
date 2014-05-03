#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm> 
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
struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int maxProfit3(vector<int> &prices) {
    if(prices.size() == 0 || prices.size() == 1)
    	return 0; 
    int *profit = new int[prices.size()-1];
    for(int i = 0; i<prices.size()-1; i++)
    	profit[i] =  prices[i+1]-prices[i];
    int max = 0;
    std::vector<int> vm;
    int m = 0;
//3,2,6,5,0,3
//-1,4,-1, -5,3

    for(int i = 0; i < prices.size()-1; i++){

    	
    	if(profit[i]>0){
    		max += profit[i];
    	}
    	if(profit[i]<0 || i == prices.size()-2){
    		vm.push_back(max);
    		max = 0;
    	}
    }

    std::sort (vm.begin(), vm.end(), myobject);
    int max_ = vm.back();
    vm.pop_back();
    return max_+vm.back();

}

int maxProfit4(vector<int> &prices){
	if(prices.size() <= 1)
    	return 0; 
	vector<int> subprice;

	int lowest = prices[0];
	int max = 0;
	subprice.push_back(0);
	for(int i= 0; i<prices.size();i++){
		int profit = prices[i]-lowest;
		if(profit> max)
			max = profit;
		subprice.push_back(max);
		if(prices[i]<lowest)
			lowest = prices[i];		
	}

	int ret = subprice[prices.size() - 1];
    int max_2= 0;   
	int highest = prices[prices.size()-1];
	for(int i = prices.size()-2;i>=0; --i){
		int profit_2 = highest-prices[i];
		if(profit_2>max_2)
			max_2 = profit_2;
		int final_profit = max_2+subprice[i];
		if(final_profit>ret) 
			ret = final_profit;
		if(highest<prices[i])
			highest = prices[i];

	}
     
        return ret;

}

int main(){

		int price[] = {-3,2,6,5,9,3};
		vector<int> prices;
		for(int i = 0; i<6;i++)
			prices.push_back(price[i]);

		cout<<maxProfit3(prices)<<endl;
		return 0;
		//system("pause");
}


