/* Date: 2015-07-07
 * Author: robin1001
 * Comment: accepted
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <vector>

class Solution {
public:
	int majorityElement(std::vector<int>& nums) {
		int index = 0, count = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (0 == count) {
				index = i;
				count = 1;
			} else {
				if (nums[i] == nums[index]) count++;
				else count--;
			}
		}
		return nums[index];
	}
};

int main() {
	int arr1[] = {1,1,2,2,2};
	int arr2[] = {1,1,2,2,2,1,1};
	Solution solution;
	std::vector<int> nums1(arr1, arr1+5);
	std::vector<int> nums2(arr2, arr2+7);
	assert(2 == solution.majorityElement(nums1));
	assert(1 == solution.majorityElement(nums2));
}
