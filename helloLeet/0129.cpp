//dfs

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
    int res = 0;
    void getNum(int sum, TreeNode* root) {
        if (!root->left && !root->right) {
            res += (sum*10 + root->val);
            return;
        }
        if (root->left) getNum(sum*10 + root->val, root->left);
        if (root->right) getNum(sum*10 + root->val, root->right);
    }
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        getNum(0, root);
        return res;
    }
};
