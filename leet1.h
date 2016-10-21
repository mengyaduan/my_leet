#include "head.h"
using namespace std;


class Solution1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hash;
		vector<int> res(2, 0);
		int n = nums.size();
		for (int i = 0; i < n; ++i){
			int temp = target - nums[i];
			if (hash.count(temp) > 0){
				res[1] = i;
				res[0] = hash[temp];
				return res;
			}
			hash[nums[i]] = i;
		}
		return res;
	}
};

void leet1(){
	vector<int> nums = { 3,2, 4 };
	Solution1 x;
	vector<int> a = x.twoSum(nums, 6);
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << " ";
	cout << endl;
}