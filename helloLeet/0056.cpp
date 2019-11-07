//override sort rule

class Solution {
public:
    static bool cmp(const vector<int>& p, const vector<int>& q) {
        return p[0] < q[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > res;
        if (intervals.empty()) return res;
        sort(intervals.begin(), intervals.end(), cmp);
        int sz = intervals.size();
        int l = intervals[0][0], r = intervals[0][1];
        for (int i = 0; i < sz ; i++) {
            if (intervals[i][0] > r) {
                res.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            } else {
                r = max(intervals[i][1], r);
            }
        }
        res.push_back({l,r});
        return res;
    }
};
