//very stupid solution

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
    int mxl = -1;
    void addRes(TreeNode* root, int layer) {
        if (root == NULL) return;
        if (layer > mxl) {
            vector<int> cur;
            if (layer%2 == 0) cur.push_back(root->val);
            else auto it = cur.insert(cur.begin(), root->val);
            res.push_back(cur);
            mxl++;
        } else {
            if (layer%2 == 0) res[layer].push_back(root->val);
            else auto it = res[layer].insert(res[layer].begin(), root->val);
        }
        layer++;
        addRes(root->left, layer);
        addRes(root->right, layer);
        layer--;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        addRes(root, 0);
        return res;
    }
};
