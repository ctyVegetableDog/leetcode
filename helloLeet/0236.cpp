//recursion

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
    TreeNode* res;
    bool containChild(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return false;
        int left = containChild(root->left, p, q) ? 1 : 0;
        int right = containChild(root->right, p, q) ? 1 : 0;
        int mid = (root == p) || (root == q) ? 1 : 0;
        if (left + right + mid >= 2) res = root;
        return (left + right + mid) > 0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool b = containChild(root, p, q);
        return res;
    }
};
