/* Date: 2015-07-07
 * Author: robin1001
 * Comment: accepted
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <stack>

using namespace std;

class MinStack {
private:
	stack<int> stack1, stack2;
public:
	void push(int x) {
		stack1.push(x);
		if (stack2.empty()) {
			stack2.push(x);
		} 
		else {
			int min = x < stack2.top() ? x : stack2.top();
			stack2.push(min);
		}
	}

	void pop() {
		stack1.pop();
		stack2.pop();
	}

	int top() {
		return stack1.top();
	}

	int getMin() {
		return stack2.top();
	}
};

int main() {
}
