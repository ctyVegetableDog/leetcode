//check line

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dx = coordinates[1][0] - coordinates[0][0], dy = coordinates[1][1] - coordinates[0][1];
        for (int i = 1; i < coordinates.size(); i++) {
            if (dy * (coordinates[i][0] - coordinates[i - 1][0]) != dx * (coordinates[i][1] - coordinates[i - 1][1])) return false;
        }
        return true;
    }
};
