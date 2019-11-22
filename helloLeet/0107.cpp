//just dfs, it's too slow cz insert, but I don't know why the solutions like reverse the result or get depth before recursion could be faster

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
    vector<vector<int> > res;
    void getRes(TreeNode* root, int layer) {
        if (!root) return;
        if (layer >= res.size()) {
            vector<int> cur;
            auto tt = res.insert(res.begin(),cur);
        }
        getRes(root->left, layer + 1);
        getRes(root->right, layer + 1);
        res[res.size() - layer - 1].push_back(root->val);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        getRes(root, 0);
        return res;
    }
};
