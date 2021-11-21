// max depth
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
    int ans = 0;
    void dfs(Node* root, int temp) {
        if (root->children.empty()) {
            ans = max(ans, temp);
            return;
        }
        for (auto& each : root->children) {
            dfs(each, temp + 1);
        }
    }
    int maxDepth(Node* root) {
        if (!root) return 0;
        dfs(root, 1);
        return ans;
    }
};
