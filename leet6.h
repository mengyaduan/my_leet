#include "head.h"
using namespace std;

class Solution6 {
public:
	string convert(string s, int numRows) {
		int n = s.size();
		if (n <= numRows || numRows <= 1)
			return s;
		//计算列数
		int num_a = n / (numRows * 2 - 2);
		int num_rest = n % (numRows * 2 - 2);
		int cols = num_a * (1 + numRows - 2);
		if (num_rest <= numRows)
			cols += 1;
		else
			cols += 1 + (num_rest - numRows);
		if (cols <= 1)
			return s;
		string res = "";
		int x = 0;
		int temp = 2 * numRows - 2;
		for (int i = 0; i < numRows; ++i){
			int cnt = 0;
			if (i == 0 || i == numRows - 1){
				while (cnt < n){
					res += s[i + cnt];
					cnt += temp;
				}
			}
			else{
				int step1 = 2 * (numRows - 1 - i);
				int step2 = 2 * i;
				while (cnt < n){
					res += s[i + cnt];
					cnt += step1;
					if (cnt < n){
						res += s[i + cnt];
						cnt += step2;
					}
				}
			}
		}
		return res;
	}
};



// memory exceeded
//class Solution6 {
//public:
//	string convert(string s, int numRows) {
//		vector<vector<string> > res;
//		int n = s.size();
//		if (n <= numRows || numRows <= 1)
//			return s;
//		//计算列数
//		int num_a = n / (numRows * 2 - 2);
//		int num_rest = n % (numRows * 2 - 2);
//		int cols = num_a * (1 + numRows - 2);
//		if (num_rest <= numRows)
//			cols += 1;
//		else
//			cols += 1 + (num_rest - numRows);
//		if (cols <= 1)
//			return s;
//		for (int i = 0; i < numRows; ++i){
//			vector<string> temp(cols, "");
//			res.push_back(temp);
//		}
//		int x = 0;
//		for (int i = 0; i < cols; ++i){
//			if (i % (numRows - 1) == 0){
//				for (int j = 0; j < numRows; ++j){
//					if (x < n){
//						res[j][i] = s[x];
//						++x;
//					}
//					else
//						break;
//				}
//			}
//			else{
//				if (x < n){
//					int temp = numRows - 1;
//					res[temp - (i%temp)][i] = s[x];
//					++x;
//				}
//				else
//					break;
//			}
//		}
//		string result = "";
//		for (int i = 0; i < numRows; ++i){
//			for (int j = 0; j < cols; ++j){
//				if (res[i][j] != "")
//					result = result + res[i][j];
//			}
//		}
//		return result;
//	}
//};

void leet6(){
	Solution6 x;
	string a = x.convert("ABC", 2);
	cout << a << endl;
}