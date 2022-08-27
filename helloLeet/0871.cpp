
// 法一：DP
// 另dp[i]表示经过i次加油可以到达的最远距离。每经过一个加油站都考虑在此处加油，假设经过了j次加油到达了加油站i，如果在此处加油，能到达的最远距离变为dp[j] + stations[i][1]，若不在此处加油则为dp[j + 1]


class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int station_num = stations.size();
        vector<long> dp(station_num + 1, 0); // dp[i] : 经过i次加油可以到达的最远距离
        dp[0] = startFuel; // 一次油不加最远可以到的距离就是开始的油量
        for (int i = 0; i < station_num; ++i) { //对于每一个加油站
            for (int j = i; j >= 0; --j) { //到达i号加油站前最多加油i次（加油站从0开始编号）
                if (dp[j] >= stations[i][0]) { //如果该加油站通过j次加油可达
                    dp[j + 1] = max(dp[j + 1], dp[j] + (long)stations[i][1]); //那么考虑使用此加油站是否能走的更远，使用此加油站能到达的距离为dp[j] + station[i][1]。因为要和dp[j + 1]比较，所以j要从后往前遍历
                }
            }
        }
        for (int i = 0; i <= station_num; ++i) {
            if (dp[i] >= target) return i;
        }
        return -1;
    }
};

//法二：贪心
//每当经过一个加油站先不加油而是记录它的储油量，当油不够到下一个加油站时，从当前经过的所有加油站中选出油量最多的一个加油
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int, vector<int>, less<int>> pq;
        int dis = startFuel, len = stations.size(), cnt = 0;
        for (int i = 0; i < len; ++i) {
            if (dis >= target) return cnt;
            while (stations[i][0] > dis) {
                if (pq.empty()) return -1;
                dis += pq.top(); pq.pop();
                ++cnt;
            }
            pq.push(stations[i][1]);
        }
        while (!pq.empty()){
            if(dis >= target) return cnt;
            dis += pq.top(); pq.pop();
            ++cnt;
        }
        return dis >= target ? cnt : -1;
    }
};
