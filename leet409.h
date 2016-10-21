#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<cstdlib>
using namespace std;

class Solution409 {
public:
	int longestPalindrome(string s) {
		int sum = 0;
		unordered_map<char, int> letter;
		for (int i = 0; i < s.length(); ++i){
			++letter[s[i]];
		}
		auto iter = letter.begin();
		for (iter; iter != letter.end(); ++iter){
			if (iter->second % 2 == 0){
				sum += iter->second;
				iter->second = 0;
			}
			else {
				sum += iter->second - 1;
				iter->second = 1;
			}
		}
		for (iter = letter.begin(); iter != letter.end(); ++iter){
			if (iter->second == 1){
				++sum;
				break;
			}
		}
		return sum;
	}
};

void leet409(){
	string s = "abcccccdd";
	Solution409 x;
	int a = x.longestPalindrome(s);
	cout << a << endl;
}

