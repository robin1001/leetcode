/* Date: 2015-07-07
 * Author: robin1001
 * Comment: accepted
 */
#include <stdio.h>
#include <assert.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		int count = 0, result;
		transverse(root, k, &count, &result);
		return result;
	}

	void transverse(TreeNode *node, int k, int *count, int *result) {
		if (*count >= k) return;
		if (NULL == node) return;
		transverse(node->left, k, count, result);	
		if (*count < k) {
			*count += 1;
			if (*count == k)  *result = node->val;
		}
		transverse(node->right, k, count, result);
	}
};


int main() {
}
