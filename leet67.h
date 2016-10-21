#include "head.h"
using namespace std;

class Solution67 {
public:
	string addBinary(string a, string b) {
		int m = a.length();
		int n = b.length();
		int flag = 0;
		string res = "";
		int i = 1;
		for (i = 1; m - i >= 0 && n - i >= 0; ++i){
			int x = a[m - i] - '0';
			int y = b[n - i] - '0';
			int temp = x + y + flag;
			flag = 0;
			if (temp >= 2){
				flag = 1;
				temp = temp % 2;
			}
			char uuu = temp + '0';
			res = uuu + res;
		}
		while (m - i >= 0){
			int x = a[m - i] - '0';
			int temp = x + flag;
			flag = 0;
			if (temp >= 2){
				flag = 1;
				temp = temp % 2;
			}
			char uuu = temp + '0';
			res = uuu + res;
			++i;
		}
		while (n - i >= 0){
			int x = b[n - i] - '0';
			int temp = x + flag;
			flag = 0;
			if (temp >= 2){
				flag = 1;
				temp = temp % 2;
			}
			char uuu = temp + '0';
			res = uuu + res;
			++i;
		}
		if (flag == 1)
			res = '1' + res;

		return res;
	}
};

void leet67(){
	Solution67 x;
	string a = x.addBinary("1", "1");
	cout << a << endl;
}