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
    int sum = 0;
    void addNum(TreeNode* root) {
        if (!root) return;
        addNum(root->right);
        int t = root->val;
        root->val += sum;
        sum += t;
        addNum(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        addNum(root);
        return root;
    }
};
