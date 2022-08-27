// dfs + 节点重新编号

/*
 使用hash记录每一行第一个非空节点的编号，然后每次访问到该行的节点时，就判断当前节点和本行第一个非空节点的距离，并更新最大距离。
 （使用递归最大的好处就是，不用管该节点是什么时候被访问到的，或者说当访问到某个节点时，不用手动判断当前是第几层）
 难点是对每层节点的重编号
 */

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
    unordered_map<int, int> mp;
    int ans = 0;
public:
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0, 1);
        return ans;
    }

    void dfs(TreeNode* root, int depth, int idx) {
        if (!root) return;
        if (mp.find(depth) == mp.end()) mp[depth] = idx;
        ans = max(ans, idx - mp[depth] + 1);
        idx = idx - mp[depth] + 1; // 对每一层重新从1开始编号，不然每加一层编号都*2用不了多久就超int了。此时将每层第一个不为空的结点编为1号，其他结点根据与该结点的相对位置进行调整。比如，某层第一个非空节点node是3号节点左孩子，那么此时该节点重编号之前是6号，此时mp[depth] = 6，此时以6为基准，对所有本层节点的编号进行调整，将该节点重新编为1号，对于5号孩子的又节点，重新编号前是11号，和node（原6号）的差距是5。而重新编号后11 - 6 + 1是6，和node（新1号）的差距还是5，相对位置不变。
        dfs(root->left, depth + 1, idx << 1);
        dfs(root->right, depth + 1, idx << 1 | 1);
    }
};
