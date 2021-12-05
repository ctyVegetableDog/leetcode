// flood fill dfs
class Solution {
public:
    void dfs(int i, int j, int newColor, vector<vector<int>>& image, vector<vector<bool>>& vis) {
        vis[i][j] = true;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = i + dx, ny = j + dy;
                if (abs(dx) != abs(dy) && !(nx < 0 || nx >= image.size() || ny < 0 || ny >= image[0].size() || vis[nx][ny]) && image[nx][ny] == image[i][j]) {
                    dfs(nx, ny, newColor, image, vis);
                }
            }
        }
        image[i][j] = newColor;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>> vis(image.size(), vector(image[0].size(), false));
        dfs(sr, sc, newColor, image, vis);
        return image;
    }
};
