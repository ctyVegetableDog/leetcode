//Reverse Vowels of a String

class Solution {
public:
    inline bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? true : false;
    }
    string reverseVowels(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i) {
            if (isVowel(s[i])) {
                while (i < j && !isVowel(s[j])) --j;
                swap(s[i], s[j]);
                --j;
            }
        }
        return s;
    }
};
