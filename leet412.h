#include "head.h"
using namespace std;

class Solution412 {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> res;
		for (int i = 1; i <= n; ++i){
			if (i % 3 == 0 && i % 5 != 0)
				res.push_back("Fizz");
			else if (i % 3 != 0 && i % 5 == 0)
				res.push_back("Buzz");
			else if (i % 3 == 0 && i % 5 == 0)
				res.push_back("FizzBuzz");
			else{
				string x = to_string(i);
				res.push_back(x);
			}
		}
		return res;
	}
};

void leet412(){
	Solution412 x;
	vector<string> a = x.fizzBuzz(15);
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << endl;
}