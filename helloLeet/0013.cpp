//map, maybe not the best solution

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int l = s.length(), i = 0, res = 0;
        for (i = 0; i < l - 1; i ++){
            if (mp[s[i]] >= mp[s[i+1]]) res += mp[s[i]];
            else {
                res +=(mp[s[i+1]] - mp[s[i]]);
                i++;
            }
        }
        if (i == l) return res;
        else return res + mp[s[l-1]];
    }
};
