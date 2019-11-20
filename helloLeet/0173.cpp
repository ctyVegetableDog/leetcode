//tranverse the tree without recursion (important and basic ques)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<int> st;
public:
    BSTIterator(TreeNode* root) {
        if (!root) return;
        TreeNode* rt = root;
        stack<TreeNode*> cur;
        while(!cur.empty() || rt) {
            while(rt) {
                cur.push(rt);
                rt = rt->right;
            }
            if(!cur.empty()) {
                rt = cur.top();
                st.push(rt->val);
                cur.pop();
                rt = rt->left;
            }
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int res = st.top();
        st.pop();
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
