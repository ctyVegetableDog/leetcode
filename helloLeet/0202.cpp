//hash map

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> mp;
        while (n!= 1) {
            if (mp[n] == 0) mp[n] = 1;
            else return false;
            int k = 0;
            while (n) {
                k += pow(n%10, 2);
                n /= 10;
            }
            n = k;
        }
        return true;
    }
};
