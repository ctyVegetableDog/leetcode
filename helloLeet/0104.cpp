//get depth of a tree
/*
	if !root->left && !root->right return 1;
	if root->left && !root->right return func(root->left)+1
	if !root0>left && root->right return func(root->right)+1
	if left && right return max(func(left),func(right)+1)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getDeep(TreeNode* root) {
        if (!root->left && !root->right) return 1;
        else if (!root->left && root->right) return getDeep(root->right) + 1;
        else if (root->left && !root->right) return getDeep(root->left) + 1;
        else return max(getDeep(root->left), getDeep(root->right)) + 1;
    }
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return getDeep(root);
    }
};

/*
	simpler version
	if !root return 0;
	else return max(func(left),func(right))+1
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
