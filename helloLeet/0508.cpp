//hash map with recursion

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
    unordered_map<int, int> mp;
    int getAllSum(TreeNode* root) {
        if (!root) return 0;
        int res = root->val + getAllSum(root->left) + getAllSum(root->right);
        mp[res]++;
        return res;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        int mx = 0;
        if (!root) return res;
        int n = getAllSum(root);
        for (auto& it : mp) mx = max(mx, it.second);
        for (auto& it : mp) if (it.second == mx) res.push_back(it.first);
        return res;
    }
};
