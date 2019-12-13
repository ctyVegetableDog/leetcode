//check a tree is a subtree of another (simple recursion, but there is an unbelievable solution, serialize the tree to a string, and use kmp)

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
    bool isSame(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        return s->val == t->val && isSame(s->left,t->left) && isSame(s->right, t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (isSame(s, t)) return true;
        if (!s) return false;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
