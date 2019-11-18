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
    vector<string> res;
    void getPath(TreeNode* root, string str) {
        if (!root->left && !root->right) {
            res.push_back(str+to_string(root->val));
            return;
        }
        if (root->left) getPath(root->left, str+to_string(root->val)+"->");
        if (root->right) getPath(root->right, str+to_string(root->val)+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return res;
        getPath(root, "");
        return res;
    }
};
