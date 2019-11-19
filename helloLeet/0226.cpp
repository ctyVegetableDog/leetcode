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
    void getRes(TreeNode* root) {
        if (!root) return;
        TreeNode* p;
        p = root->left;
        root->left = root->right;
        root->right = p;
        invertTree(root->left);
        invertTree(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        getRes(root);
        return root;
    }
};
