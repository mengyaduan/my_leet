#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution38 {
public:
	string countAndSay(int n) {
		string res = "1";
		while (n-1){
			res = count1(res);
			--n;
		}
		return res;
	}

	string count1(string s){
		string res = "";
		int sum = 1;
		int i = 1;
		char last = s[0];
		char temp = '1';
		while (i<s.length()){
			if (s[i] == last){
				++sum;
			}
			else{
				temp = '0' + sum;
				res = res + temp + last;
				last = s[i];
				sum = 1;
			}
			++i;
		}
		temp = '0' + sum;
		res = res + temp + last;
		return res;
	}

};

void leet38(){
	int n = 4;
	Solution38 x;
	//string b = x.count1("11");
	//cout << b << endl;


	string s = x.countAndSay(n);
	cout << s << endl;

}