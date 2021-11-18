// findTilt
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int helper(TreeNode* root) {
        if (!root) return 0;
        int l = helper(root->left), r = helper(root->right);
        ans += abs(l - r);
        return l + r + root->val;
        
    }
    int findTilt(TreeNode* root) {
        helper(root);
        return ans;
    }
};
