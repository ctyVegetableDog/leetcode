//简单模拟

class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int sum = accumulate(arr.begin() + n / 20, arr.end() - n / 20, 0);
        return sum / (n * 0.9);
    }
};
