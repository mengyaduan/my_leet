#include "head.h"
using namespace std;

class Solution20 {
public:
	bool isValid(string s) {
		unordered_map<char,char> paren;
		paren['('] = ')';		
		paren['['] = ']';		
		paren['{'] = '}';
		stack<char> pa;
		for (int i = 0; i < s.length(); ++i){
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				pa.push(s[i]);
			else{
				if (pa.empty()){
					if (s[i] == ')' || s[i] == ']' || s[i] == '}')
						return false;
				}
				if (s[i] == paren[pa.top()])
					pa.pop();
				else
					return false;
			}
		}
		if (pa.empty())
			return true;
		return false;
	}
};

void leet20(){
	Solution20 x; 
	bool a = x.isValid("[])");
	cout << a << endl;
}