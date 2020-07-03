//N-ary Tree Level Order Traversal(dfs)

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> res;
    
    void helper(Node* root, int depth) {
        if (!root) return;
        if (depth >= res.size()) {
            res.push_back(vector<int>());
        }
        res[depth].push_back(root->val);
        ++depth;
        for (Node* nd : root->children) {
            helper(nd, depth);
        }
        --depth;
    }
    vector<vector<int>> levelOrder(Node* root) {
        helper(root, 0);
        return res;
    }
};
