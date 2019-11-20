//postorder traversal without recursion(use invsert)

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
        stack<TreeNode*> st;
        TreeNode* p = root;
        while(!st.empty() || p) {
            if (p) {
                st.push(p);
                auto cur = res.insert(res.begin(), p->val);
                p = p->right;
            } else {
                p = st.top();
                st.pop();
                p = p->left;
            }
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        addNum(root);
        return res;
    }
};
