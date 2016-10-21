#include "head.h"
using namespace std;

class Solution204 {
public:
	int countPrimes(int n) {
		int sum = 0;
		for (int i = 2; i < n;++i){
			while (n%i == 0){
				n /= i;
			}
			++sum;
			++i;
		}
		return sum;
	}
};

void leet204(){
	Solution204 x;
	int a = x.countPrimes(13);
	cout << a << endl;
}