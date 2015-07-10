/* Date: 2015-07-10
 * Author: robin1001
 * Comment: accepted
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root != NULL) {
			TreeNode *t = root->left;
			root->left = root->right;
			root->right = t;
			invertTree(root->left);
			invertTree(root->right);
		}
		return root;
	}
};

int main() {
}
