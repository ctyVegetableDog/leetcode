//stack(good ques, have to come back)

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
    stack<TreeNode*> st;
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* node = root;
        while(true) {
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
            if (!st.empty()) {
                node->left = NULL;
                node->right = st.top();
                st.pop();
                node = node->right;
            } else break;
        }
    }
};
