//Maximum Binary Tree

/*
	O(n) solution
	Build the tree one node by one step
	maintain a stack by decreasing order
	for each number, the left child is the biggest number in the stack that smaller than it, and it'll be the right child of the smallest number that bigger than it.
	The left child must from the previous number, and the right node must from the later number
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> v;
        for (int i : nums) {
            TreeNode *node = new TreeNode(i);
            while (!v.empty() && v.back()->val < node->val) {
                node->left = v.back();
                v.pop_back();
            }
            if (!v.empty()) v.back()->right = node;
            v.push_back(node);
        }
        return v.front();
    }
};
