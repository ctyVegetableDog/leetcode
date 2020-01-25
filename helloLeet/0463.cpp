//Island perimeter (math)

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int is = 0, con = 0, x = grid.size(), y = grid[0].size();
        for (int i = 0; i < x; i ++) {
            for (int j = 0; j < y; j ++) {
                if (grid[i][j] == 1) {
                    is++;
                    if (i + 1 < x && grid[i + 1][j] == 1) con++;
                    if (j + 1 < y && grid[i][j + 1] == 1) con++;
                }
            }
        }
        return is * 4 - con * 2;
    }
};
