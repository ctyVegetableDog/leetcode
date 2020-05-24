//Construct Binary Search Tree from Preorder Traversal (backtracking, important question)

/*
	If A[i] smaller than current node than becoming left child
	If not backtracking to its parent
*/

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
    int i = 0;
    TreeNode* contructBST(vector<int>& preorder, int bound)  {
        if(i == preorder.size() || preorder[i] > bound) return nullptr;
        TreeNode *node = new TreeNode(preorder[i++]);
        node->left = contructBST(preorder, node->val);
        node->right = contructBST(preorder, bound);
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return contructBST(preorder, INT_MAX);
    }
};
