#include "head.h"
using namespace std;

class Solution168 {
public:
	string convertToTitle(int n) {
		vector<char> letter;
		letter.push_back('Z');
		for (int i = 0; i<25; ++i)
			letter.push_back('A' + i);
		string res = "";
		while (n>26){
			int rest = n % 26;
			res = letter[rest] + res;
			if (n % 26 == 0)
				n = n / 26 - 1;
			else
				n = n / 26;
		}
		n %= 26;
		res = letter[n] + res;
		return res;
	}
};

void leet168(){
	Solution168 x;
	int n;
	cin >> n;
	string a = x.convertToTitle(n);
	cout << a << endl;
}