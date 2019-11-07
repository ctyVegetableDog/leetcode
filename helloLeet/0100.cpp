//Recurion

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
    bool checkSame(TreeNode* p, TreeNode* q) {
        if (!q && !p) return true;
        else if ((!p && q) || (p && !q)) return false;
        else if (p->val == q->val && checkSame(p->left, q->left) && checkSame(p->right, q->right)) return true;
        else return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checkSame(p,q);
    }
};
