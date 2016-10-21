#include "head.h"
using namespace std;

class Solution414 {
public:
	int thirdMax(vector<int>& nums) {
		int n = nums.size();
		if (n == 1)
			return nums[0];
		if (n == 2)
			return max(nums[0], nums[1]);
		int max1, max2, max3;
		max1 = max2 = max3 = 0;
		int i = 0;
		while (i < n){
			if (nums[i] == max1 || nums[i] == max2 || nums[i] == max3){
				++i;
				continue;
			}
			if (nums[i]>max1){
				max3 = max2;
				max2 = max1;
				max1 = nums[i];
			}
			else if (nums[i] < max1&&nums[i]>max2){
				max3 = max2;
				max2 = nums[i];
			}
			else if (nums[i]<max2&&nums[i]>max3){
				max3 = nums[i];
			}
			else
				max1;
			++i;
		}
		if (max1 == max2 || max2 == max3)
			return max1;
		else
			return max3;

	}
};

void leet414(){
	vector<int> nums = { 2,2,3,1 };
	Solution414 x;
	int a = x.thirdMax(nums);
	cout << a << endl;
}