//construct a binary tree from preorder and inorder traversal (very useful)
/*
	1. in the preorder, for each node, we always traverse itself and then its left node, it means the first node of the preorder vector must be the root of the tree
	2. in the inorder, for each node, we traverse the left subtree first and then itself, it means in inorder vector, nodes before node N must in its left subtree, and those after N must in the right subtree
	3. so we can create the tree recursionally, we get the val of current node from preorder tree(in this recursionally, it will always be the start index of a sub part of preorder vector), and then find its position in inorder vector to limit the range of its left subtree and right subtree.
	4. when the in_s > in_end or pre_s > v.size, it means we already get the layer deeper than leaf, so we return NULL
*/

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
    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int pre_s, int in_s, int in_end) {
        if (pre_s > preorder.size() - 1 || in_s > in_end) return NULL;
        TreeNode* root = new TreeNode(preorder[pre_s]);
        int ss = 0;
        for (int i = in_s; i <= in_end; i ++) {
            if (inorder[i] == root->val) ss = i;
        }
        root->left = createTree(preorder, inorder, pre_s + 1, in_s, ss - 1);
        root->right = createTree(preorder, inorder, pre_s + ss - in_s + 1, ss + 1, in_end);//the reason why new preorder_start is pre_s + ss - in_s + 1 is in preoder, after one node N,  always follow by its whole left subtree and then the the right subtree, and the number of node of its whole left subtree is the node at the left of N in the inorder vector, so the number will be (ss - in_s), it means in the preorder vector, from index preorder + 1 to index preorder + ss -in_s will be its left subtree, so the new start of its right subtree will be preorder + ss - in_s + !
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return createTree(preorder, inorder, 0, 0, inorder.size() - 1);
    }
};
