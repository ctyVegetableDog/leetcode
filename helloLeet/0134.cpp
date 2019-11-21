//greedy

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = gas.size() - 1;
        int end = 0;
        int cs = gas[start] - cost[start];
        while(start > end) {
            if (cs >= 0) {
                cs += (gas[end] - cost[end]);
                end++;
            } else {
                start--;
                cs += (gas[start] - cost[start]);
            }
        }
        return (cs >= 0) ? start : -1;
    }
};
