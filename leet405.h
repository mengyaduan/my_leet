#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<cstdlib>
using namespace std;

// 该方法可行，但是可以直接与15&，这样能减少运行时间。
class Solution405 {
public:
	string toHex(int num) {
		if (num == 0)
			return "0";
		vector<vector<int> > res;
		// init
		for (int i = 0; i < 8; ++i){
			vector<int> a(4, 0);
			res.push_back(a);
		}
		int n = num;
		int index = 0;
		while (n != 0){
			for (int i = 0; i < 4; ++i){
				int temp = n & 1;
				n = n >> 1;
				res[index][4-i-1] = temp;
			}
			++index;
			if (index == 8)
				break;
		}
		string result = "";
		for (int i = index - 1; i >= 0; --i){
			string temp = toHex4bit(res[i]);
			result += temp;
		}
		return result;
	}
	string toHex4bit(vector<int>& a){
		char letter[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
		int x = a[0] * 8 + a[1] * 4 + a[2] * 2 + a[3] * 1;
		string res = "";
		return res + letter[x];
	}
};

void leet405(){
	int n = -1;
	Solution405 x;
	string a = x.toHex(n);
	cout << a << endl;
}