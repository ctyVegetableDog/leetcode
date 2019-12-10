//search a number in a 2D matrix
/*
	The matrix is defined as below:
	Integers in each row are sorted in ascending from left to right.
	Integers in each column are sorted in ascending from top to bottom.
	So, image we stand at the top-right corn, this matrix is just like a BST!(as every left neighbor is smaller and below neighbour is larger).It mean we can just search it as search a BST!
	The reason why we can only move left or down:
	Conside following situation:
	a	b
	c	d
	if now we stand at c, it means target<b(if target>b, we will already visit d), and if we visit d, it means we will go to a number which > b, but as we know target is < b, so in any cases, d could not be the answer
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int i = 0, j = matrix[0].size() - 1;
        while (i <= matrix.size() - 1 && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};
