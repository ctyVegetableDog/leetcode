//寻找重复的子树

/*
 *对每棵子树进行序列化。如果使用中序遍历序列化会导致序列化结果不唯一（先序和后序遍历都可以唯一，因为在加入空结点的情况下，先序和后序都确定唯一一棵子树而中序不行因为无法确定根结点位置）
 * */


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
private:
    unordered_map<string, int> mp;
    vector<TreeNode*> ans;
public:
    string dfs(TreeNode* root) {
        if (!root) return " ";
        string s = to_string(root->val) + "_" + dfs(root->left) + "_" + dfs(root->right);
        mp[s]++;
        if (mp[s] == 2) ans.push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
