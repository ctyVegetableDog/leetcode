//Top K Frequent Words

/*
use unordered_map initialize a priority_queue
*/

class Solution {
public:
    struct cmp {
        bool operator () (const pair<string, int> &p1, const pair<string, int> &p2) {
            return p1.second != p2.second ? p1.second < p2.second : p1.first > p2.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto& s : words) ++mp[s];
        priority_queue<pair<string, int>, vector<pair<string, int> >, cmp> pq = {mp.begin(), mp.end()};
        vector<string> res;
        while (k--) res.push_back(pq.top().first), pq.pop();
        return res;
    }
};
