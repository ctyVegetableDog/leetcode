//Top K frequent elements

/*
	bucket sort version O(n)
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<vector<int> > fre_list(sz + 1, vector<int>());
        vector<int> res;
        unordered_map<int, int> mp;
        for (int n : nums) {
            mp[n]++;
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            fre_list[it->second].push_back(it->first);
        }
        for (int i = sz; i >= 0 && k > 0; i--) {
            for (int j = 0; j < fre_list[i].size() && k > 0; j++) {
                res.push_back(fre_list[i][j]);
                k--;
            }
        }
        return res;
    }
};

/*
	priority_queue version O(nlog(n))
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        unordered_map<int, int> mp;
        vector<int> res;
        for (int n : nums) mp[n]++;
        for (auto & it : mp) {
            pq.push(it.second);
            while (pq.size() > k) pq.pop();
        }
        for (auto & it : mp) {
            if (it.second >= pq.top()) res.push_back(it.first);
        }
        return res;
    }
};
