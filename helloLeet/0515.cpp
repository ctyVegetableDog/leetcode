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
    void getNum(TreeNode* root, int layer) {
        if (!root) return;
        if (layer >= res.size()) res.push_back(root->val);
        else res[layer] = max(res[layer], root->val);
        layer++;
        getNum(root->left, layer);
        getNum(root->right, layer);
        layer--;
    }
    vector<int> largestValues(TreeNode* root) {
        getNum(root, 0);
        return res;
    }
};
