//String permutation

class Solution {

public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> visit(26, 0);
        for (char c : s1) {
            visit[c - 'a']++;
        }
        int left = 0, right = 0;
        while (right < s2.size()) {
            visit[s2[right] - 'a']--;
            while (visit[s2[right] - 'a'] < 0) {
                visit[s2[left] - 'a']++;
                left++;
            }
            if (right -left + 1 == s1.size()) return true;
            right++;
        }
        return false;
    }
};
