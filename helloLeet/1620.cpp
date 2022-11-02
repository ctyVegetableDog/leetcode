// 网络信号最好的坐标（傻逼题）

class Solution {
public:
    double getDistance(int i, int j, int x, int y) {
        i = (double)i;
        j = (double)j;
        x = (double)x;
        y = (double)y;
        return sqrt((x - i) * (x - i) + (y - j) * (y - j));
    }
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int max_score = 0;
        int ans_x = 0, ans_y = 0;
        for (int i = 0; i <= 50; ++i) {
            for (int j = 0; j <= 50; ++j) { // 每一个坐标
                int score = 0;
                for (auto& tower : towers) {
                    double dis = getDistance(i, j, tower[0], tower[1]);
                    if (dis <= (double)radius) {
                        score += floor((double)tower[2] / (1 + dis));
                    }
                }
                if (score > max_score) {
                    max_score = score;
                    ans_x = i;
                    ans_y = j;
                }
            }
        }
        return {ans_x, ans_y};
    }
};
