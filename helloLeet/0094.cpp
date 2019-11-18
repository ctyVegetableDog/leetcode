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
    vector<int> res;
    void getRes(TreeNode* root) {
        if (!root) return;
        getRes(root->left);
        res.push_back(root->val);
        getRes(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return res;
        getRes(root);
        return res;
    }
};
