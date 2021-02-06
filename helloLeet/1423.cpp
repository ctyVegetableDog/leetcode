class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = cardPoints.size();
        if (k >= l) return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        auto right = cardPoints.end() - 1, left = right - k + 1;
        int sum = accumulate(left, right + 1, 0), res = sum;
        while (k--) {
            sum -= *left;
            left++;
            right++;
            if (left == cardPoints.end()) left = cardPoints.begin();
            if (right == cardPoints.end()) right = cardPoints.begin();
            sum += *right;
            res = max(res, sum);
        }
        return res;
    }
};
