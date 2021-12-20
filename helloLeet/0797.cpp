class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    void dfs(vector<vector<int>>& graph, int x, int tar) {
        if(x == tar) {
            ans.push_back(cur);
            return;
        }
        for (auto& e : graph[x]) {
            cur.push_back(e);
            dfs(graph, e, tar);
            cur.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        cur.push_back(0);
        dfs(graph, 0, graph.size() - 1);
        return ans;
    }
};
