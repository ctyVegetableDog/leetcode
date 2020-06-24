//Count Complete Tree Nodes

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
    int getHeight(TreeNode* root) {
        return root == nullptr ? -1 : 1 + getHeight(root->left);
    }
    
    int countNodes(TreeNode* root) {
        int height = getHeight(root);
        return height == -1 ? 0 : (getHeight(root->right) == height - 1 ? (1 << height) + countNodes(root->right) : (1 << height - 1) + countNodes(root->left));
    }
};
