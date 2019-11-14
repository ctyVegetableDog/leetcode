//recursion (theoretically is the best solution (On and without queue) but don't know why is perform bad)

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
            cur.push_back(root->val);
            res.push_back(cur);
            mxl++;
        } else {
            res[layer].push_back(root->val);
        }
        layer++;
        addRes(root->left, layer);
        addRes(root->right, layer);
        layer--;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        addRes(root, 0);
        return res;
    }
};
