#include "head.h"
using namespace std;
//比较经过处理后前后两个数组的差别，可以得到公式，fk = fk-1 + sum - 4*A[n-k]
class Solution396 {
public:
	int maxRotateFunction(vector<int>& A) {
		int sum = 0;
		int n = A.size();
		int fi = 0;
		for (int i = 0; i < n; ++i){
			sum += A[i];
			fi += A[i] * i;
		}
		int res = fi;//max
		for (int j = 1; j < n; j++){
			fi = fi + sum - n*A[n - j];
			if (fi > res)
				res = fi;
		}
		return res;
	}
};
//// Time Limited Exceeded
//class Solution396 {
//public:
//	int maxRotateFunction(vector<int>& A) {
//		int n = A.size();
//		vector<int> F;// rotate
//		for (int i = 0; i < n; ++i)
//			F.push_back(i);
//		int res = 0;
//		for (int j = 0; j < n; ++j)
//			res += F[j]++ * A[j];
//		for (int i = 1; i < n; ++i){
//			int sum = 0;
//			for (int j = 0; j < n; ++j)
//				sum += (F[j]++) % n * A[j];
//			if (sum > res)
//				res = sum;
//		}
//		return res;
//	}
//};

void leet396(){
	vector<int> A = { 4, 3, 2, 6 };
	Solution396 x;
	int a = x.maxRotateFunction(A);
	cout << a << endl;
}