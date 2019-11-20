//preorder traverse a tree without recursion

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
    vector<int> res;
    void addNum(TreeNode* root) {
        if (!root) return;
        TreeNode* p = root;
        stack<TreeNode*> st;
        while(!st.empty() || p) {
            while(p) {
                st.push(p);
                res.push_back(p->val);
                p = p->left;
            }
            if (!st.empty()) {
                p = st.top();
                st.pop();
                p = p->right;
            }
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        addNum(root);
        return res;
    }
};
