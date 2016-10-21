#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<cstdlib>
using namespace std;

class Solution299 {
public:
	string getHint(string secret, string guess) {
		unordered_map<char, int> sec;
		int A = 0; // bulls
		int B = 0; // cows
		for (int i = 0; i < secret.length(); ++i)
			++sec[secret[i]];
		for (int i = 0; i < guess.length(); ++i){
			auto iter = sec.find(guess[i]);
			if (iter != sec.end() && sec[guess[i]]>0){
				++B;
				--sec[guess[i]];
			}
		}
		for (int i = 0; i < secret.length(); ++i){
			if (secret[i] == guess[i]){
				++A;
				--B;
			}
		}
		char tempA = '0' + A;
		char tempB = '0' + B;
		string res = "";
		char stringA[25];
		_itoa_s(A, stringA, 10);
		int m = 0;
		while (1){
			if (stringA[m] == '\0')
				break;
			res += stringA[m];
			++m;
		}
		res += "A";
		char stringB[25];
		_itoa_s(B, stringB, 10);
		int n = 0;
		while (1){
			if (stringB[n] == '\0')
				break;
			res += stringB[n];
			++n;
		}
		res += "B";
		return res;
	}
};


void leet299(){
	string secret = "1123";
	string guess = "0111";
	Solution299 x;
	string a = x.getHint(secret, guess);
	cout << a << endl;
}