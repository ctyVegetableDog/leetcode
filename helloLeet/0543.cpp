//bfs

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
    int res = 1;
    int getDepth(TreeNode* root) {
        if (!root) return 0;
        int l = getDepth(root->left);
        int r = getDepth(root->right);
        res = max(res, l + r + 1);
        return max(r, l) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d = getDepth(root);
        return res - 1;
    }
};
