#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution205 {
public:
	bool isIsomorphic(string s, string t) {
		return isIso(s, t) && isIso(t, s);
	}
	bool isIso(string s, string t){
		int n = s.length();
		unordered_map<char, char> dict;
		for (int i = 0; i < n; ++i){
			unordered_map<char, char>::iterator it;
			it = dict.find(s[i]);
			if (it != dict.end()) {
				if (it->second != t[i]){
					return false;
				}
			}
			else{
				dict[s[i]] = t[i];
			}
		}
		return true;
	}
};

void leet205(){
	Solution205 x;
	bool a = x.isIsomorphic("asdf", "qwer");
	cout << a << endl;
	bool b = x.isIsomorphic("ass", "foo");
	cout << b << endl;
	bool c = x.isIsomorphic("egg", "asd");
	cout << c << endl;
	bool d = x.isIsomorphic("ab", "aa");
	cout << d << endl;
}
