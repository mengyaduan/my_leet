#include "head.h"
using namespace std;

class Solution204 {
public:
	int countPrimes(int n) {
		int sum = 0;
		int i = 2;
		while (i < n){
			if (isPrime(i))
				++sum;
			++i;
		}
		return sum;
	}
	bool isPrime(int x){
		int temp = sqrt(x);
		if (x == 2)
			return true;
		if (x % 2 == 0)
			return false;
		for (int i = 3; i <= temp; i = i + 2){
			if (x%i == 0)
				return false;
		}
		return true;
	}
};

void leet204(){
	Solution204 x;
	int a = x.countPrimes(13);
	cout << a << endl;
}