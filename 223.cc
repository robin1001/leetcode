/* Date: 2015-07-07
 * Author: robin1001
 * Comment: accepted
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int area1 = (C - A) * (D - B);		
		int area2 = (F - D) * (H - E);
		int overlap;
		if ((D <= F || H <= B) || (C <= E || G <= A)) {
			overlap = 0;
		}
		else {
			
		}
	}
};

int main() {
}
