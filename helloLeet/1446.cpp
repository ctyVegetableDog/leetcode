// max power
class Solution {
public:
    int maxPower(string s) {
        int len = s.size(), mx = 0;
        for (int i = 0, j = 0; i < len;) {
            int cnt = 0;
            while (j < len && s[i] == s[j]) {
                j++;
                cnt++;
            }
            mx = max(mx, cnt);
            i = j;
        }
        return mx;
    }
};
