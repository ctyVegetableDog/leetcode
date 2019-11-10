//permutatiom

//brute force
class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        for (int i = 1; i <= n; i ++) s += (i + '0');
        k--;
        while (k--) next_permutation(s.begin(), s.end());
        return s;
    }
};

//caculation number for each index, logic
class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        vector<int> v;
        int num = 1;
        int size = 0;
        for (int i = 1; i <= n; i++) {
            v.push_back(i);
            num *= i;
        }
        while (n--) {
            num /= (n + 1);
            int t = ((k - 1)/num) % (n + 1);
            s += (v[t] + '0');
            v.erase(v.begin() + t);
        }
        return s;
    }
};
