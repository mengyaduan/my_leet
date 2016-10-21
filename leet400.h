#include "head.h"
using namespace std;

class Solution400 {
public:
	int findNthDigit(int n) {
		if (n < 10)
			return n;
		int rest = 0;
		int dig = 1;
		//��ȷ��λ��
		rest = n - 9 * dig *pow(10, dig - 1);
		while (rest > 0){
			++dig;
			int temp = 9 * dig*pow(10, dig - 1);
			if (rest > temp){
				rest -= temp;
			}
			else
				break;
		}
		//��ȷ���ĸ�����
		int num = (rest - 1) / dig + 1;
		int number = pow(10, dig - 1) - 1 + num;
		//��ȷ����λ
		int x =dig - (rest-1) % dig;
		int res = 0;
		for (int i = 0; i < x; ++i){
			res = number % 10;
			number /= 10;
		}
		return res;
	}
};

void leet400(){
	Solution400 x;
	int a = x.findNthDigit(1000);
	cout << a << endl;
}