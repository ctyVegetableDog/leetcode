// 可能的二分法

/*
 *二分图判定（2-可色图判定）
 * */

class Solution {
public:
    // idx号结点是否满足条件：该结点和所有已经访问的相邻结点颜色都不同，且其所有未访问的相邻结点均满足条件
    bool dfs(int idx, int cur_color, vector<int>& color, const vector<vector<int>>& graph) {
        color[idx] = cur_color;
        for (int each : graph[idx]) {
            if (color[each] && color[each] == cur_color) return false;
            if (!color[each] && !dfs(each, 3 ^ cur_color, color, graph)) return false;
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n + 1, 0); // 0未上色, 1,2两种颜色
        vector<vector<int>> graph(n + 1); // 邻接表
        for (auto& each : dislikes) { // 构建邻接表
            graph[each[0]].push_back(each[1]);
            graph[each[1]].push_back(each[0]);
        }

        for (int i = 1; i <= n; ++i) {
            if (color[i] == 0 && !dfs(i, 1, color, graph)) return false;
        }
        return true;
    }
};
