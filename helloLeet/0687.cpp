// 最长同值路径
// 二叉树路径问题分为两种，自顶向下和任意节点之间路径，一般都是用dfs，这题属于第二种


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
private:
    int ans = 0;
public:
    /*
        以root为根，包含root的往下的最长同值路径，即若root->val != root->left->val且root->val != root->right->val，则以root为根没有同值路径，若root->val只和其中一个子节点相同，则为那个字节点的最长同值路径长度+1，否则为其两个子节点最长同值路径最大值+1
    */
    int helper(TreeNode* root) {
        if (!root) return 0;
        int left = helper(root->left), right = helper(root->right);
        if (root->left && root->val == root->left->val) ++left;
        else left = 0;
        if (root->right && root->val == root->right->val) ++right;
        else right = 0;
        ans = max(ans, left + right);
        return max(left, right);
    }
    int longestUnivaluePath(TreeNode* root) {
        helper(root);
        return ans;
    }
};
