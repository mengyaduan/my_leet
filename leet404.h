#include "head.h"
using namespace std;

class Solution404 {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL || (root->left == NULL && root->right == NULL))
			return 0;
		if (root->left == NULL && root->right != NULL)
			return sumOfLeftLeaves(root->right);
		if (has_left_leaf(root)){
			if (root->right == NULL || (root->right->left == NULL&&root->right->right == NULL))
				return root->left->val;
			return root->left->val + sumOfLeftLeaves(root->right);
		}
		return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
	}
	bool has_left_leaf(TreeNode* root){
		if (root->left->left == NULL && root->left->right == NULL)
			return true;
		return false;
	}
};
// smart solution
class Solution404_2 {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		return helper(root, 0);
	}

	int helper(TreeNode* root, int flag) {
		if (!root) {
			return 0;
		}
		if (flag == 0) {
			return helper(root->left, 1) + helper(root->right, 2);
		}
		if (flag == 1) {
			if (!root->left && !root->right) {
				return root->val;
			}
		}
		return helper(root->left, 1) + helper(root->right, 2);
	}
};