//nothing

class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = s.length(), res = 0;
        int j = l -1;
        while (j >= 0) {
            if (s[j] != ' ') break;
            else j--;
        }
        for (; j >= 0; j--) {
            if (s[j] == ' ') return res;
            else res++;
        }
        return res;
    }
};
