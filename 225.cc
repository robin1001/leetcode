/* Date: 2015-07-07
 * Author: robin1001
 * Comment: accepted
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <queue>

using namespace std;

class Stack {
public:
	Stack(): cur_(0) {}
	// Push element x onto stack.
	void push(int x) {
		queue_[cur_].push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		while (queue_[cur_].size() > 1) {
			queue_[1-cur_].push(queue_[cur_].front());
			queue_[cur_].pop();
		}
		queue_[cur_].pop();	
		cur_ = 1 - cur_;
	}

	// Get the top element.
	int top() {	
		while (queue_[cur_].size() > 1) {
			queue_[1-cur_].push(queue_[cur_].front());
			queue_[cur_].pop();
		}
		return queue_[cur_].front();	
	}

	// Return whether the stack is empty.
	bool empty() {
		return (queue_[0].empty() && queue_[1].empty());
	}
private:
	queue<int> queue_[2];
	int cur_;
};

int main() {
	Stack st;
	for (int i = 0; i < 5; i++) {
		st.push(i);
	}
	for (int i = 0; i < 5; i++) {
		printf("%d\n", st.top());
		st.pop();
	}
	assert(st.empty());
}
