class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cost = 0, left = 0, right = 0;
        while (right < s.size()) {
            cost += abs(s[right] - t[right]);
            right++;
            if (cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                left++;
            }
        }
        return right - left;
    }
};
