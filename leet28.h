#include "head.h"
using namespace std;

class Solution28 {
public:
	int strStr(string haystack, string needle) {
		int m = haystack.size();
		int n = needle.size();
		int i = 0;
		int res = -1;
		while (i <= m - n){
			int j = 0;
			for (j ; j < n; ++j){
				if (haystack[i + j] != needle[j])
					break;
			}
			if (j == n){
				res = i;
				break;
			}
			++i;
		}
		return res;

	}
};

void leet28(){
	Solution28 x;
	int a = x.strStr(";alkjlaskjflasf", "sf");
	cout << a << endl;
}