#include "head.h"
using namespace std;

class Solution14 {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string res = "";
		int n = strs.size();
		if (n == 0)
			return res;
		int i = 1;
		res += strs[0];
		while (i < n){
			res = findPrefix(strs[i], res);
			++i;
		}
		return res;
	}
	string findPrefix(string a, string b){
		int i = 0;
		string res = "";
		while (a[i] != '\0' && b[i] != '\0'){
			if (a[i] == b[i])
				res += a[i];
			else
				break;
			++i;
		}
		return res;
	}
};

void leet14(){
	Solution14 x; 
	vector<string> strs = { "acd", "ac", "acdfd", "acs" };
	//string a = x.findPrefix("sabcs", "abcd");
	string a = x.longestCommonPrefix(strs);
	cout << a << endl;
}