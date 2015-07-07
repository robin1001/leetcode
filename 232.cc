/* Date: 2015-07-07
 * Author: robin1001
 * Comment: accepted
 */

#include <stdio.h>
#include <assert.h>

#include <stack>


class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		stack1_.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (stack2_.empty()) {
			while (!stack1_.empty()) {
				stack2_.push(stack1_.top());
				stack1_.pop();
			}
		}
		assert(stack2_.size() > 0);
		stack2_.pop();
	}

	// Get the front element.
	int peek(void) {
		if (stack2_.empty()) {
			while (!stack1_.empty()) {
				stack2_.push(stack1_.top());
				stack1_.pop();
			}
		}
		assert(stack2_.size() > 0);
		return stack2_.top();		
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return (stack1_.size() == 0 && stack2_.size() == 0);
	}
private:
	std::stack<int> stack1_, stack2_;
};


int main() {
	Queue queue;
	for (int i = 0; i < 10; i++)
		queue.push(i);
	for (int i = 0; i < 10; i++) {
		printf("%d\n", queue.peek());
		queue.pop();
	}
	assert(queue.empty());
}
