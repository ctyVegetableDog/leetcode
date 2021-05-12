// xorQueries (prefix sum)
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int len = arr.size();
        vector<int> res;
        for (int i = 1; i < len; ++i) arr[i] ^= arr[i - 1];
        for (auto& q : queries) {
            if (q[0] == 0) res.push_back(arr[q[1]]);
            else res.push_back(arr[q[1]] ^ arr[q[0] - 1]);
        }
        return res;
    }
};
