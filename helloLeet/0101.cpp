//recursion
//A tree is symmetric <-> right subtree is the mirror of leftt subtree
//two trees are mirror <-> 1.their roots have same value 2.right subtree of each one is mirror of the left subtree of the other one

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
    vector<TreeNode*> res;
    bool isMirror(TreeNode* r1, TreeNode* r2) {
        if (!r1 && !r2) return true;
        if (!r1 || !r2) return false;
        return (r1->val == r2->val && isMirror(r1->left, r2->right) && isMirror(r1->right, r2->left));
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};
