// Longest subsequence (dp + hash)
// 1.2D dp
// v[i][j](j will be 0 or 1) ----- consider the first i numbers with the case of the i-th number is j
// v[i][0] ----- not  choose arr[i]
// in this case, sizeof the longest subsequence will be max(v[i - 1][0], v[i - 1][1])
// v[i][1] ----- choose arr[i]
// in this case, arr[i] could start a new subsequence ----- v[i][1] = 1
// or, arr[i] could follow another number, which means prev = arr[i] - different could be found in the previous subsequnce
// use a hashmap mp to save the last position i of number arr[i]
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int len = arr.size();
        vector<vector<int>> v(len, vector(2, 0));
        unordered_map<int, int> mp;
        //v[0][0] = 0;
        v[0][1] = 1;
        mp[arr[0]] = 0;
        for (int i = 1;i < len; ++i) {
            v[i][0] = max(v[i - 1][0], v[i - 1][1]);
            v[i][1] = 1;
            int tar = arr[i] - difference;
            if (mp.find(tar) != mp.end()) v[i][1] = max(v[i][1], v[mp[tar]][1] + 1);
            mp[arr[i]] = i;
        }
        return max(v[len - 1][0], v[len - 1][1]);
    }
};

//2.optimization
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 1;
        unordered_map<int, int> mp;
        for (int i : arr) {
            if (mp.find(i - difference) == mp.end()) mp[i] = 1;
            else mp[i] = mp[i - difference] + 1;
            // mp[i] = mp.find(arr[i] - difference) == mp.end() ? 1 : mp[arr[i] - difference] + 1;
            ans =  max(ans, mp[i]);
        }
        return ans;
    }
};
