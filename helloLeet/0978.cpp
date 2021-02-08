//Turrent vector

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int dp0 = 1, dp1 = 1, res = 1;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > arr[i - 1]) {
                dp0 = dp1 + 1;
                dp1 = 1;
            } else if (arr[i] < arr[i - 1]) {
                dp1 = dp0 + 1;
                dp0 = 1;
            } else {
                dp0 = 1;
                dp1 = 1;
            }
            res = max(res, max(dp0, dp1));
        }
        return res;
    }
};
