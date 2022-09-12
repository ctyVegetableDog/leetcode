// 特殊数组的特征值

/*
 *若数组中恰好有x个比x大大元素则称x为特征值
 没什么说的，数据范围是1000，可以用数组做哈希然后统计每个数字出现的个数，然后从后往前找并累加出现的数字的个数cnt，如果cnt == 当前扫描的数说明该数是x
 另外之所以有x的话只有一个是因为cnt是递减的（cnt表示数组中比该数字大的元素的个数）而当前扫面的数是递增的
 * */
class Solution {
public:
    int specialArray(vector<int>& nums) {
        vector<int> v(1005, 0);
        for (int i = 0; i < nums.size(); ++i) {
            ++v[nums[i]];
        }
        int cnt = 0;
        for (int i = 1004; i >= 0; --i) {
            cnt += v[i];
            if (cnt == i) return cnt;
        }
        return -1;
    }
};
