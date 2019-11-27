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
    vector<double> res;
    vector<int> cnt;
    void getRes(TreeNode* root, int layer) {
        if (!root) return;
        if (layer == res.size()) {
            res.push_back(0);
            cnt.push_back(0);
        }
        res[layer] += root->val;
        cnt[layer]++;
        getRes(root->left, layer + 1);
        getRes(root->right, layer + 1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        getRes(root, 0);
        for (int i = 0; i < res.size(); i ++) res[i] /= cnt[i];
        return res;
    }
};
