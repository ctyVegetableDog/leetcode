//search a 2D matrix

/*
	BST could work as well, but binary search is faster
	And it's l = mid + 1, r = mid - 1
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = matrix.size();
        if (x == 0) return false;
        int y = matrix[0].size();
        if (y == 0) return false;
        int l = 0, r = x * y - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int i = mid / y;
            int j = mid % y;
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};
