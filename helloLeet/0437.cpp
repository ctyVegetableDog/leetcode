//Path Sum 3

/*
	find the number of paths sum to a given value int a binary tree
	use hash map
	similar to two sum
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
    int res = 0;
    unordered_map<int, int> mp;
    void getRes(TreeNode* root, int cur, int tar, unordered_map<int, int>& mp) {
        if (!root) return;
        cur += root->val;
        if (mp.find(cur-tar) != mp.end()) res += mp[cur-tar];
        mp[cur]++;
        getRes(root->left, cur, tar);
        getRes(root->right, cur, tar);
        mp[cur]--;
    }
    int pathSum(TreeNode* root, int sum) {
        mp[0] = 1;
        getRes(root, 0, sum);
        return res;
    }
};
