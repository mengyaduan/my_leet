#include "head.h"
#include <assert.h>

using namespace std;

typedef unsigned int uint32_t;
class Solution190 {
public:
	uint32_t reverseBits(uint32_t n) {
		vector<int> ones;
		int cnt = 0;
		while (n != 0){
			if ((n & 1) == 1){
				ones.push_back(cnt);
			}
			++cnt;
			n >>= 1;
		}
		uint32_t x = 0;
		for (int i = 0; i < ones.size(); ++i){
			x += pow(2, 31 - ones[i]);
		}
		return x;
	}
};

void leet190(){
	Solution190 x;
	uint32_t a = x.reverseBits(43261596);
	//assert(a == 964176192);
	cout << a << endl;
}