//合并区间

/*
 *区间问题的基础吧可以说是，区间扫描的思想
 将待合并区间按左端点大小排序，然后维护一个当前区间，每当扫描到一个新的区间，只有两种情况，要么新扫描到的区间左端点大于当前维护区间的右端点，此时无法合并，当前维护的区间变为现在扫描到的区间，原区间加入答案。要么新扫面到区间的左端点落于当前维护的区间内，此时只要更新右端点为当前维护的区间和新扫描到区间右端点的最大值就行
 * */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] <  b[0];
        });
        int l = intervals[0][0], r = intervals[0][1];
        for (auto& each : intervals) {
            if (each[0] > r) { // 扫描到的区间和当前维护的区间没有交集，说明当前维护的区间要形成新的区间了
                ans.push_back({l, r});
                l = each[0]; r = each[1];
            } else { // 有交集，更新当前维护的区间，左端点肯定不需要维护，因为当前扫描到的区间左端点必然比当前维护的区间的左端点大（因为排过序）
                r = max(r, each[1]); //更新右端点
            }
        }
        ans.push_back({l ,r}); // 别忘了最后还有一个区间
        return ans;
    }
};

// 法二：插旗法（挺慢）

/*
 *插旗法的核心在于将某个区间分解为左右两个端点（在两端点插旗），从此只考虑端点的性质而和区间无关了
 *本题中将端点排序后设置一个cnt记录当前左端点的个数，如果在扫面时遇到的是左端点，有两种情况，如果当前cnt == 0，说明刚生成一个区间，这是一个新区间的左端点，记录它的值++cnt，否则直接++cnt
如果是右端点则--cnt，之后右两种情况，cnt == 0的话说明当前是区间的右端点了（对于[2,3], [3,4]这样的，因为先入左再入右，不会有问题），生成新区间，否则单纯的--cnt
 * */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> points; //端点{坐标，左/右}
        for (auto& interval : intervals) { //保存端点
            points.push_back({interval[0], -1});
            points.push_back({interval[1], 1});
        }
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]); //坐标从小到大，先左后右
        });
        int l = -1, cnt = 0;
        vector<vector<int>> ans;
        for (auto& each : points) {
            if (each[1] == -1) { //左端点
                if (cnt == 0) { //新区间的左端点
                    l = each[0];
                }
                ++cnt;
            } else {
                --cnt;
                if (cnt == 0) { //右端点
                    ans.push_back({l ,each[0]});
                }
            }
        }
        return ans;
    }
};
