#include "head.h"
using namespace std;


class Solution415 {
public:
	string addStrings(string num1, string num2) {
		int m = num1.length() - 1;
		int n = num2.length() - 1;
		string res = "";
		int flag = 0;
		while (m >= 0 && n >= 0){
			int a = num1[m] - '0';
			int b = num2[n] - '0';
			int temp = a + b + flag;
			flag = 0;
			if (temp >= 10){
				flag = 1;
				temp -= 10;
			}
			char dig = '0' + temp;
			res = dig + res;
			--m;
			--n;
		}
		if (m < 0 && n >= 0){
			string temp = processrest(num2, n, flag);
			res = temp + res;
		}
		if (n < 0 && m >= 0){
			string temp = processrest(num1, m, flag);
			res = temp + res;
		}
		if (flag == 1)
			res = '1' + res;
		return res;
	}
	string processrest(string num, int m, int& flag){
		string result = "";
		while (m >= 0){
			int x = num[m] - '0';
			int temp = x + flag;
			flag = 0;
			if (temp >= 10){
				flag = 1;
				temp -= 10;
			}
			char dig = '0' + temp;
			result = dig + result;
			--m;
		}
		return result;
	}
};

void leet415(){
	Solution415 x;
	string a = x.addStrings("954", "1934");
	cout << a << endl;
}