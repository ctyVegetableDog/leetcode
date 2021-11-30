// rotate vector

//1
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        for (int i = 0, cnt = 0; cnt < len; ++i) {
            int st_pos = i, st_val = nums[i];
            do {
                int nxt_pos = (st_pos + k) % len;
                swap(nums[nxt_pos], st_val);
                st_pos = nxt_pos;
                cnt++;
            } while (st_pos != i);
        }
    }
};

//2
//1 2 3 4 5 6 7 with k = 3
//->7 6 5 4 3 2 1
//->5 6 7 1 2 3 4
//class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};
