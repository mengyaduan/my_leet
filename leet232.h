#include "head.h"
using namespace std;

class myQueue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		stack<int> temp;
		while (!st.empty()){
			temp.push(st.top());
			st.pop();
		}
		st.push(x);
		while (!temp.empty()){
			st.push(temp.top());
			temp.pop();
		}
	}

	// Removes the element from in front of queue.
	void pop(void) {
		st.pop();
	}

	// Get the front element.
	int peek(void) {
		return st.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return st.empty();
	}
private:
	stack<int> st;
};