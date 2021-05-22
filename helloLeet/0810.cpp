// xor Game (Math)
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        if (nums.size() % 2 == 0) return true;
        int cnt = 0;
        for (int n : nums) cnt ^= n;
        return cnt == 0;
    }
};
