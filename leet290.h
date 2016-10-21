#include "head.h"
using namespace std;

class Solution290 {
public:
	bool wordPattern(string pattern, string str) {
		vector<string> words;
		int index = 0;
		while (index < str.length()){
			string temp = "";
			while (str[index] != ' '&&index<str.length()){
				temp += str[index];
				++index;
			}
			words.push_back(temp);
			++index;
		}
		if (words.size() != pattern.length())
			return false;
		unordered_map<char, string> p2w;
		unordered_map<string, char> w2p;
		for (int i = 0; i < words.size(); ++i){
			if (p2w.count(pattern[i])==0)
				p2w[pattern[i]] = words[i];
			else{
				if (p2w[pattern[i]] == words[i])
					continue;
				else
					return false;
			}
		}
		for (int i = 0; i < words.size(); ++i){
			if (w2p.count(words[i]) == 0)
				w2p[words[i]] = pattern[i];
			else{
				if (w2p[words[i]] == pattern[i])
					continue;
				else
					return false;
			}
		}

		return true;
	}
};

void leet290(){
	Solution290 x;
	bool a = x.wordPattern("aaaa", "dog dog dog dog");
	cout << a << endl;
}