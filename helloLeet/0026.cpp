//useless question

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for (int n:nums) s.insert(n);
        nums.clear();
        for (int n:s) nums.push_back(n);
        return s.size();
    }
};
