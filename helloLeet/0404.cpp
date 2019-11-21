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
    int sum = 0;
    void getSum(TreeNode* root, bool ok) {
        if (!root) return;
        if (!root->left && !root->right && ok) sum += root->val;
        getSum(root->left, true);
        getSum(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        getSum(root, false);
        return sum;
    }
};
