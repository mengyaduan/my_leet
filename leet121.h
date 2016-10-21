#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<cstdlib>
using namespace std;

class Solution121 {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n == 0)
			return 0;
		int mp = 0;//result
		int low = prices[0];
		int high = 0;
		if (n == 0)
			return 0;
		for (int i = 0; i < n; ++i){
			if (prices[i] < low){
				low = prices[i];
				high = 0;
			}
			else if (prices[i] > high){
				high = prices[i];
				int temp = prices[i] - low;
				if (temp > mp)
					mp = temp;
			}
			else
				continue;
		}
		return mp;

	}
};
void leet121(){
	vector<int> prices = { 7, 6, 4, 3, 1 };
	Solution121 x;
	int a = x.maxProfit(prices);
	cout << a << endl;
}