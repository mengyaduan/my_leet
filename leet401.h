#include "head.h"
using namespace std;

class Solution401 {
public:
	vector<bool> time; // first four bits for hours..remaining four bits for minutes
	vector<string> ans;
	string t;
	void solve(int num, int start, int index)
	{
		if (num <= 0)
		{
			int hour = 0, mins = 0;
			for (int i = 0; i<4; i++) hour += pow(2, i)*time[i];
			for (int i = 4; i<10; i++) mins += pow(2, i - 4)*time[i];
			if (hour>11 || mins>59)  return;
			t = to_string(mins);
			if (mins / 10 == 0) t = "0" + t;
			t = to_string(hour) + ":" + t;
			ans.push_back(t);
			return;
		}
		for (int i = start; i<10; i++)
		{
			time[i] = 1;
			solve(num - 1, i + 1, index + 1);
			time[i] = 0;
		}
	}

	vector<string> readBinaryWatch(int num) {
		time.resize(10, 0);
		solve(num, 0, 0);
		return ans;
	}
};

//class Solution401 {
//public:
//	vector<string> readBinaryWatch(int num) {
//		vector<string>res;
//		if (num > 8)
//			return res;
//		for (int i = 0; i < 4; ++i){
//			if (i>num)
//				break;
//			vector<string> hours = findhour(i);
//			vector<string> minutes = findminute(num - i);
//			for (int x = 0; x < hours.size(); ++x){
//				for (int y = 0; y < minutes.size(); ++y){
//					string temp = hours[x] + ":";
//					temp = temp + minutes[y];
//					res.push_back(temp);
//				}
//			}
//		}
//		return res;
//	}
//	vector<string> findhour(int n){
//		vector<string> hours;
//		if (n == 0)
//			hours = { "0" };
//		if (n == 1)
//			hours = { "1", "2", "4", "8" };
//		if (n == 2)
//			hours = { "3", "5", "6", "9", "10" };
//		if (n == 3)
//			hours = { "7", "11" };
//		return hours;
//	}
//	vector<string> findminute(int n){
//		set<int> res;
//		if (n == 0){
//			vector<string> n0 = { "00" };
//			return n0;
//		}
//		vector<int> n1 = { 1, 2, 4, 8, 16, 32 };
//		if (n == 1)
//			return tos(n1);
//		vector<int> n2;
//		for (int i = 0; i < n1.size(); ++i){
//			for (int j = i + 1; j < n1.size(); ++j){
//				int temp = n1[i] + n1[j];
//				if (res.count(temp) == 0){
//					n2.push_back(temp);
//					res.insert(temp);
//				}
//			}
//		}
//		if (n == 2)
//			return tos(n2);
//		vector<int> n3;
//		for (int i = 0; i < n1.size(); ++i){
//			for (int j = 0; j < n2.size(); ++j){
//				if ((n1[i] & n2[j]) == 0 && (n1[i] + n2[j] < 60)){
//					int temp = n1[i] + n2[j];
//					if (res.count(temp) == 0){
//						n3.push_back(temp);
//						res.insert(temp);
//					}
//				}
//			}
//		}
//		if (n == 3)
//			return tos(n3);
//		vector<int> n4;
//		for (int i = 0; i < n1.size(); ++i){
//			for (int j = 0; j < n3.size(); ++j){
//				if ((n1[i] & n3[j]) == 0 && (n1[i] + n3[j] < 60)){
//					int temp = n1[i] + n3[j];
//					if (res.count(temp) == 0){
//						n4.push_back(temp);
//						res.insert(temp);
//					}
//				}
//			}
//		}
//		if (n == 4)
//			return tos(n4);
//		vector<int> n5;
//		for (int i = 0; i < n1.size(); ++i){
//			for (int j = 0; j < n4.size(); ++j){
//				if ((n1[i] & n4[j]) == 0 && (n1[i] + n4[j] < 60)){
//					int temp = n1[i] + n4[j];
//					if (res.count(temp) == 0){
//						n5.push_back(temp);
//						res.insert(temp);
//					}
//				}
//			}
//		}
//		for (int i = 0; i < n2.size(); ++i){
//			for (int j = 0; j < n3.size(); ++j){
//				if ((n2[i] & n3[j]) == 0 && (n2[i] + n3[j] < 60)){
//					int temp = n2[i] + n3[j];
//					if (res.count(temp) == 0){
//						n5.push_back(temp);
//						res.insert(temp);
//					}
//				}
//			}
//		}
//		if (n == 5)
//			return tos(n5);
//		vector<string> wr;
//		return wr;
//	}
//	vector<string> tos(vector<int>& n1){
//		vector<string> res;
//		for (int i = 0; i < n1.size(); ++i){
//			if (n1[i] < 10){
//				string a = "0";
//				char x = '0' + n1[i];
//				res.push_back(a + x);
//			}
//			else
//				res.push_back(to_string(n1[i]));
//		}
//		return res;
//	}
//};

void leet401(){
	Solution401 x;
	vector<string> a = x.readBinaryWatch(1);
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << " ";
	cout << endl;
	//int n;
	//while (cin >> n){
	//	vector<string> a = x.findminute(n);
	//	for (int i = 0; i < a.size(); ++i)
	//		cout << a[i] << " ";
	//	cout << endl;
	}
}