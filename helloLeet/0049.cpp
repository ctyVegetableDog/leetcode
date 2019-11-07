//hash_map(good ques) (hash_map, unordered_map for C++, collections for python)

//C++ unordered_map(hashmap in offical lib), don't know why it's so slow

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string, vector<string> > hm;
        for(string s: strs) {
            vector<int> v(26,0);
            for (char c:s)  v[c - 'a'] ++;
            string ss = "";
            for (int t : v) ss += (t + '0');
            if (hm.find(ss) == hm.end()) {
                vector<string> nv;
                hm[ss] = nv;
            }
            hm[ss].push_back(s);
        }
        for (auto& v : hm) res.push_back(vector<string>(v.second.begin(), v.second.end()));
        return res;
    }
};

//python version (collections!)

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = collections.defaultdict(list)
        for s in strs:
            v = [0] * 26
            for c in s:
                v[ord(c) - ord('a')] += 1
            res[tuple(v)].append(s)
        return res.values()
