//recursion

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
    bool func(TreeNode* root, long small, long big) {
        if (!root) return true;
        if (small >= root->val || big <= root->val || !func(root->left, small, root->val) || !func(root->right, root->val, big)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return func(root, LONG_MIN, LONG_MAX);
    }
};
