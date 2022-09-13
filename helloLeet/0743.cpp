// 单源最短路

// 法一：Dijkstra（堆 + 邻接表）
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        /*
        存储图的邻接表，其中pair<int1, int2>表示一条边，长度int1，终点int2。vector<pair<int, int>>表示某个点为起点的所有边的集合，vector<vector<pair<int, int>>>表示所有点的所有边的集合，如:
        v[0][2] is {3, 6}表示0号点的第2条边（可以类比传统链表存储的0号表头的第2个节点）长度为3，终点是6
        */ 
        vector<vector<pair<int, int>>> table(n + 1);
        int vsize = times.size(); // 边数
        for (int i = 0; i < vsize; ++i) { //构造邻接表
            int from = times[i][0], to = times[i][1], w = times[i][2]; //注意这里点的编号从1开始
            table[from].emplace_back(w, to);
        }
        /*
        pq中存放的pair表示{点到起始点的估计值，点的编号}，即pq表示当前的候选结点
        需要注意的是，对于某个结点如果找到了一条比当前最短路径更短的路径，那么不是更新堆中的数据，而是直接新建一个pair入堆，该pair会比原来那个更早被访问，而当访问到原来那个的时候，可以比较当前该点的dist和pair中存的估计值，如果dist更小，说明该点已经被用更短的路径访问过了，这样就不用再开空间存vis信息了
        */
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n + 1, INT_MAX); // 当前起始点到每个结点距离的估计值
        dist[k] = 0;
        dist[0] = 0;
        pq.emplace(0, k);
        while (!pq.empty()) {
            auto e = pq.top(); pq.pop(); // 拿到当前离起始点距离最短的点
            if (e.first > dist[e.second]) continue; // 如果该点已经被访问，则不管
            for (auto& each : table[e.second]) { //对每一条与该点相连的边
                int to = each.second, w = each.first;
                if (e.first + w < dist[to]) { // 如果经过点e.first有更短的到达to的路径
                    dist[to] = e.first + w;
                    pq.emplace(dist[to], to);
                }
            }
        }
        int ans = *max_element(dist.begin(), dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};

// 法二：Floyd
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> v(n + 1, vector<int>(n + 1, INT_MAX / 2));
        for (int i = 1; i <= n; ++i) {
            v[i][i] = 0;
            v[i][0] = 0;
        }
        for (auto& each : times) { // 初始化邻接矩阵
            v[each[0]][each[1]] = each[2];
        }

        /*
        Floyd算法的核心是DP，考虑任意两点之间的距离，开始是连接它们边的长度（没有则是正无穷），每次考虑使用其他结点作为中转，开始不能中转，到可以使用1号结点中转，到可以使用1号和2号结点中转，直到可以使用所有结点中转，此时的邻接表被更新为任意结点到任意结点的距离，即整个图的信息都可以知道，时间复杂度O(n^3)
        */

        for (int availableNode = 1; availableNode <= n; ++availableNode) { // 每次多一个可选结点
            for (int i = 1; i <= n; ++i) { // 更新整个邻接表
                for (int j = 1; j <= n; ++j) { // 考察i到j是否走availableNode号结点中转更短
                    v[i][j] = min(v[i][j], v[i][availableNode] + v[availableNode][j]);
                }
            }
        }
        int ans = *max_element(v[k].begin(), v[k].end());
        return ans == INT_MAX / 2 ? -1 : ans;
    }
};
