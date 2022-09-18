// 天际线问题

/*
 *插旗法的进阶题
 题目的本质是要找出所有高度产生变化的点，这样的点可能出现在两种地方
 一是扫描到了比当前最大高度更高的左端点
 二是扫描到了当前最大高度线段的右端点
 需要用一个堆保存当前最大高度，每扫面到一个端点，就将其入堆，如果该点是左端点且比堆顶更大，则是目标点，如果该点是右端点且等于当前堆顶的值，则也是目标点
 * */

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<vector<int>> points; // 端点{坐标，高度，左/右}
        for (auto& building : buildings) {
            points.push_back({building[0], building[2], -1}); //左端点
            points.push_back({building[1], building[2], 1}); //右端点
        }
        /*
        按坐标由小到大排序（扫面线的常规预处理），如果坐标一样则先扫左端点（假设某坐标同时入3出4，如果先处理出4，那么出4，最大高度变化为0，0加入，然后入3，最大高度边为3，3加入，这显然不对，正确的应该是入3，最大高度不变，出4，最大高度变为3，3加入），如果都是左端点则按从大到小，都是右端点则从小到大（不然会同一坐标多次加入）
        */
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return (a[0] < b[0]) || (a[0] == b[0] && a[2] < b[2]) || (a[0] == b[0] && a[2] == -1 && b[2] == -1 && a[1] > b[1]) || (a[0] == b[0] && a[2] == 1 && b[2] == 1 && a[1] < b[1]);
        });
        unordered_map<int, int> mp; //记录当前栈顶的元素已经被弹出多少次，这样扫描到右端点需要从优先队列里弹出的时候，可以先不用nlogn的时间弹出，而是先记着，当栈顶变为那个本该弹出的元素时，将它弹出就行
        priority_queue<int, vector<int>, less<int>> pq;
        pq.push(0); //地面，永远不弹出
        for(auto& point : points) {
            if (point[2] == -1) { //如果当前扫描到的是左端点
                if (pq.empty() || point[1] > pq.top()) { //若当前队中没有元素或当前扫描到的端点比队顶更大
                    ans.push_back({point[0], point[1]});
                }
                pq.push(point[1]); //入队
            } else { //如果是右端点
                mp[point[1]]++; //欠一次删除
                int cur_top = pq.top();
                while (mp[pq.top()] > 0) { //弹出之前应该弹出的那些
                    mp[pq.top()]--;
                    pq.pop();
                }
                if (point[1] == cur_top && point[1] > pq.top()) { //产生新的端点，只有当当前扫描到的是堆顶的右端点，并且比弹出后的新堆顶高（要是一样高就应该连成一起）
                    ans.push_back({point[0], pq.top()});
                }
            }
        }
        return ans;
    }
};
