// 卡车上的最大单元数

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int ans = 0;
        for (int i = 0; i < boxTypes.size(); ++i) {
            if (truckSize < boxTypes[i][0]) {
                ans += truckSize * boxTypes[i][1];
                return ans;
            }
            ans += boxTypes[i][0] * boxTypes[i][1];
            truckSize -= boxTypes[i][0];
        }
        return ans;
    }
};
