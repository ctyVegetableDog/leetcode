// check string similar
iclass Solution {
public:
    bool halvesAreAlike(string s) {
        int res = 0;
        for (int l = 0,  r = s.size() / 2; r < s.size(); ++l, ++r) {
            if (s[l] == 'a' || s[l] == 'A' || s[l] == 'e' || s[l] == 'E' || s[l] == 'i' || s[l] == 'I' || s[l] == 'o' || s[l] == 'O' || s[l] == 'u' || s[l] == 'U') ++res;
            if (s[r] == 'a' || s[r] == 'A' || s[r] == 'e' || s[r] == 'E' || s[r] == 'i' || s[r] == 'I' || s[r] == 'o' || s[r] == 'O' || s[r] == 'u' || s[r] == 'U') --res;
        }
        return !res;
    }
};
