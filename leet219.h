#include "head.h"
using namespace std;

class Solution219 {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int n = nums.size();
		unordered_map<int, int> finddup;
		for (int i = 0; i < n; ++i){
			if (finddup.count(nums[i])){
				int temp = i - finddup[nums[i]];
				if (temp <= k)
					return true;
				else
					finddup[nums[i]] = i;
			}
			else{
				finddup[nums[i]] = i;
			}
		}
		return false;
	}
};

void leet219(){
	Solution219 x;
	vector<int> nums = { 4, 7, 2, 1, 5, 2, 6, 7, 8, 5, 1 };
	bool a = x.containsNearbyDuplicate(nums, 3);
	cout << a << endl;
}