//for each number in an array, find the first number bigger than it(stack)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> temp_ix;
        int i = T.size();
        vector<int> res(i, 0);
        for (int x = i - 1; x >= 0; x--) {
            while (!temp_ix.empty() && T[x] >= T[temp_ix.top()]) temp_ix.pop();
            res[x] = temp_ix.empty() ? 0 : temp_ix.top() - x;
            temp_ix.push(x);
        }
        return res;
    }
};
