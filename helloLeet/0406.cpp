//Queue Reconstruction by height(good question in all aspect)

class Solution {
public:
    static bool cmp(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] > v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int> > res;
        for (auto& each:people) {
            res.insert(res.begin() + each[1], each);
        }
        return res;
    }
};
