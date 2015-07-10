/* Date: 2015-07-10
 * Author: robin1001
 * Comment: accepted
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		int s = 0, cur = 0;				
		vector<string> vec;
		while (cur < nums.size()) {
			stringstream ss;
			s = cur;
			while (cur < nums.size() - 1 && nums[cur] + 1 == nums[cur+1])
				cur++;
			if (s != cur) {
				printf("%d->%d\n", nums[s], nums[cur]);
				ss << nums[s] << "->" << nums[cur];
			} else {
				printf("%d\n", nums[s]);
				ss << nums[s];
			}
			vec.push_back(ss.str());	
			cur++ ;
		}
		return vec;
	}
};

int main() {
	int arr[] = {0,1,2,4,5,7,8};
	vector<int> nums(arr, arr+7);
	Solution().summaryRanges(nums);
	//assert(3 == Solution().summaryRanges(nums).size());
}
