// shuffle
class Solution {
private:
    vector<int> v;
public:
    Solution(vector<int>& nums) {
        v = nums;
    }
    
    vector<int> reset() {
        return v;
    }
    
    vector<int> shuffle() {
        vector copy_nums(v.begin(), v.end());
        int len = v.size();
        for (int i = len - 1; i >= 0; --i) {
            swap(copy_nums[rand()%(i + 1)], copy_nums[i]);
        }
        return copy_nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
