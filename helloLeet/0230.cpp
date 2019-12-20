//Kth smallest Element in a BST

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
    int cnt = 0;
    int res = INT_MIN;
    void getRes(TreeNode* root, int k) {
        if (!root) return;
        getRes(root->left, k);
        cnt ++;
        if (cnt == k) res = root->val;
        getRes(root->right, k);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        getRes(root, k);
        return res;
    }
};
