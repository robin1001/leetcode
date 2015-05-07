#include <stdio.h>
#include <assert.h>


#include <iostream>
#include <vector>
#include <map>


using namespace std;

vector<int> two_sum(vector<int>& nums, int target) {
    map<int, int> table; 
    vector<int> index(2, 0);
    for (int i = 0; i < nums.size(); i++) {
        if (table.find(target - nums[i]) != table.end()) {
            index[0] = table[target - nums[i]] + 1;
            index[1] = i + 1;
            return index;
        }
        table.insert(pair<int, int>(nums[i], i));
    }
    return index;
}

void test_two_sum() {
    vector<int> nums(10, 0);
    vector<int> index(2, 0);
    index[0] = 1, index[1] = 2;
    assert(two_sum(nums, 0)== index);

    nums[2] = 3, nums[5] = 7;
    index[0] = 3, index[1] = 6;
    assert(two_sum(nums, 10)== index);
}

int main() {
    test_two_sum(); 
}
