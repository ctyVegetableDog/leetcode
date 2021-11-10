class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = duration, len = timeSeries.size();
        if (len == 1) return duration;
        for (int i = len - 1; i > 0; --i) {
            int temp = timeSeries[i] - timeSeries[i - 1];
            ans += (temp >= duration) ? duration : temp;
        }
        return ans;
    }
};
