// find LHS

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int n : nums) {
            cnt[n]++;
        }
        for (int n : nums) {
            if (cnt.find(n + 1) != cnt.end()) {
                ans = max(ans, cnt[n] + cnt[n + 1]);
            } 
        }
        return ans;
    }
};
