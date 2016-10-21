#include "head.h"
using namespace std;
class Stack {
public:
	// Push element x onto stack.
	void push(int x) {
		q.push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		int n = q.size();
		int temp = 0;
		for (int i = 0; i < n; ++i){
			temp = q.front();
			q.pop();
			if (i != n-1)
				q.push(temp);
		}
	}

	// Get the top element.
	int top() {
		int n = q.size();
		int temp = 0;
		for (int i = 0; i < n; ++i){
			temp = q.front();
			q.pop();
			q.push(temp);
		}
		return temp;
	}

	// Return whether the stack is empty.
	bool empty() {
		return q.empty();
	}
private:
	queue<int> q;
};