//boyer-moore voting
/*
	find the majority element in a unsorted array (appear more than n/2 times)
	we choose a number arbitarily called candidate, and traverse the array, if n == candidate, then count ++, else count --.
	The principle is we use minority numbers counteract majority number(and minority number will counteract each other), but as majority number is more than the sum of all other numbers, so the final candidate will always be the majority number
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, cand;
        for (int n : nums) {
            if (cnt == 0) cand = n;
            if (cand == n) cnt++;
            else cnt--;
        }
        return cand;
    }
};
