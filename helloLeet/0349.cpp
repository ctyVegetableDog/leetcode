//hash map

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums1.size(); i ++) mp[nums1[i]] = i;
        for (int i = 0; i < nums2.size(); i ++) if (mp.find(nums2[i]) != mp.end() && mp[nums2[i]] != -1) {
            res.push_back(nums2[i]);
            mp[nums2[i]] = -1;
        }
        return res;
    }
};
