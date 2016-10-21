#include <iostream>
#include <vector>
using namespace std;

class Solution36 {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		//扫每一行
		int record[10] = { 0 };
		for (int i = 0; i < 9; ++i){
			for (int j = 0; j < 9; ++j){
				if (board[i][j] != '.'){
					int temp = board[i][j] - '0';
					++record[temp];
					if (record[temp] > 1){
						return false;
					}
				}
			}
			for (int a = 0; a < 10; ++a) record[a] = 0;
		}
		//扫每一列
		for (int i = 0; i < 9; ++i){
			for (int j = 0; j < 9; ++j){
				if (board[j][i] != '.'){
					int temp = board[j][i] - '0';
					++record[temp];
					if (record[temp] > 1){
						return false;
					}
				}
			}
			for (int a = 0; a < 10; ++a) record[a] = 0;
		}
		//扫小九宫格
		int rec[3][3][10] = { 0 };
		for (int i = 0; i < 9; ++i){
			for (int j = 0; j < 9; ++j){
				if (board[i][j] != '.'){
					int temp = board[i][j] - '0';
					++rec[i / 3][j / 3][temp];
					if (rec[i / 3][j / 3][temp]>1){
						return false;
					}
				}
			}
		}
		cout << "fuck4" << endl;

		return true;
	}
};

void leet36(){
	Solution36 a;
	vector<vector<char>> board;
	string source[9] = { ".87654321", "2........", "3........", "4........", "5........", "6........", "7........", "8........", "9........" };
	for (int i = 0; i < 9; ++i){
		vector<char> temp;
		for (int j = 0; j < 9; ++j){
			temp.push_back(source[i][j]);
		}
		board.push_back(temp);
	}
	bool haha = a.isValidSudoku(board);
	cout << haha << endl;
}