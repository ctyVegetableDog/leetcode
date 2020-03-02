//Find Bottom Left Tree Value(dfs)

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
    void dfs(TreeNode* root, int& maxDepth, int& res, int depth) {
        if (!root) return;
        dfs(root->left, maxDepth, res, depth + 1);
        dfs(root->right, maxDepth, res, depth + 1);
        if (depth > maxDepth) {
            maxDepth = depth;
            res = root->val;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        int res = root->val, maxDepth = 0;
        dfs(root, maxDepth, res, 0);
        return res;
    }
};
