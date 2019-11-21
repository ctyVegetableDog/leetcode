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
    void getRes(TreeNode* root, int layer) {
        if (!root) return;
        if (layer >= res.size()) res.push_back(root->val);
        else res[layer] = root->val;
        layer++;
        getRes(root->left, layer);
        getRes(root->right, layer);
        layer--;
    }
    vector<int> rightSideView(TreeNode* root) {
        getRes(root, 0);
        return res;
    }
};
