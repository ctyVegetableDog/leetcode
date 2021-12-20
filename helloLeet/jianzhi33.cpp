// 判断某个序列是否是二叉树的后序遍历
class Solution {
public:
    bool helper(const vector<int>& postorder, int i, int j) {
        if(i >= j) return true; // 区间只有一个元素可以返回
        int start_idx = i;
        while (postorder[start_idx] < postorder[j]) ++start_idx; // 从区间[i, j)之间找到第一个大于pos[j]的元素，此时是左右子树的分界线
        int board = start_idx; // 分界线，从boarder开始全是右子树
        while (postorder[start_idx] > postorder[j]) ++ start_idx; // 此时全是右子树，应该全部大于pos[j]，直到start_idx == j结束
        return start_idx == j && helper(postorder, i, board - 1) && helper(postorder, board, j - 1); // 此时j为root的子树处理结束，向右递归进root为j-1的
        
    }
    bool verifyPostorder(vector<int>& postorder) {
        int n = postorder.size();
        return helper(postorder, 0, n - 1);
    }
};
