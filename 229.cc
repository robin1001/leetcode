/* Date: 2015-07-07
 * Author: robin1001
 * Comment: accepted
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <vector>

using namespace std;
/* 可以肯定的是，每次丢弃c，都有另外K个元素也一起被丢弃 */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
		if (nums.size() <= 1) return nums;        
		vector<int> result;
		int count1 = 1, count2 = 0;
		int top1 = nums[0], top2 = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == top1) {
				count1++;
			} 
			else if (nums[i] == top2) {
				count2++;
			}
			else if (0 == count1) {
				top1 = nums[i];
				count1 = 1;
			}
			else if (0 == count2) {
				top2 = nums[i];
				count2 = 1;
			}
			else {
				count1--;
				count2--;
			}
		}
		count1 = 0, count2 = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == top1) count1++;
			else if(nums[i] == top2) count2++;
		}
		//printf("%d %d\n", top1, count1);
		//printf("%d %d\n", top2, count2);
		if (count1 > nums.size() / 3) result.push_back(top1);
		if (count2 > nums.size() / 3) result.push_back(top2);
		return result;
	}
};



int main() {
	int arr[] = {1,1,0,0};
	vector<int> nums(arr, arr+4);
	Solution solution;
	vector<int> result = solution.majorityElement(nums);
	assert(result.size() == 2);
	printf("%d %d\n", 0, result[0]);
}
