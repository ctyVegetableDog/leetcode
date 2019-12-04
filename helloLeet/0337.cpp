//dp on a tree, if key is not a value, we can't use map, the solution is use dp during the recursion

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
    pair<int, int> rb(TreeNode* root) {
        if (!root) return {0, 0};
        pair<int, int> l = rb(root->left);
        pair<int, int> r = rb(root->right);
        pair<int, int> res(max(l.first, l.second) + max(r.first, r.second), root->val + l.first + r.first);
        return res;
    }
    int rob(TreeNode* root) {
        pair<int, int> res = rb(root);
        return max(res.first, res.second);
    }
};
