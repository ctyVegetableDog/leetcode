//Path sum 2 (dfs)

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
    vector<vector<int>> res;
    void getRes(TreeNode* root, int sum, vector<int>& v) {
        if (!root) return;
        
        vector<int> nv = v;
        nv.push_back(root->val);
        
        if (root && !root->left && !root->right) {
            if (sum == root->val) {
                res.push_back(nv);
            }
            return;
        } else {
            if (root->left) getRes(root->left, sum - root->val, nv);
            if (root->right) getRes(root->right, sum - root->val, nv);
        }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> v;
        getRes(root, sum, v);
        return res;
    }
};
