/* Date: 2015-07-07
 * Author: robin1001
 * Comment: accepted
 */
#include <stdio.h>
#include <assert.h>


class Solution {
public:
	bool isPowerOfTwo(int n) {
		int x = n;
		for (x = n; x > 1 && x % 2 == 0; x = x / 2);
		return x == 1;
	}
};



int main() {
	Solution s;
	assert(s.isPowerOfTwo(8));
	assert(!s.isPowerOfTwo(10));
	assert(!s.isPowerOfTwo(12));
	assert(s.isPowerOfTwo(16));
}
