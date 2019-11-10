//O(n) just logic
/*
tranverse intervals,do:
1. if iter[1] < newInterval[0] res.push_back(iter);
2. else if iter[0] > newInterval[1] push(newInterval) and push all iter after
3. else newInterval[0] = min(newInterval[0], iter[0])	newInterval[1] = max(newInterval[1], iter[1])

if never do 3 push newInterval directly
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int> > res;
        bool ok = false;
        for (auto iter = intervals.begin(); iter != intervals.end(); iter ++) {
            if (ok) {
                res.push_back(*iter);
                continue;
            }
            if ((*iter)[1] < newInterval[0]) res.push_back(*iter);
            else if ((*iter)[0] > newInterval[1]) {
                res.push_back(newInterval);
                res.push_back(*iter);
                ok = true;
            } else {
                if ((*iter)[0] < newInterval[0]) newInterval[0] = (*iter)[0];
                if ((*iter)[1] > newInterval[1]) newInterval[1] = (*iter)[1];
            }
        }
        if (!ok) res.push_back(newInterval);
        return res;
    }
};
