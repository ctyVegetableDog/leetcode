class Solution {
public:
    // 假设扫描到了n的第i位，3种情况：
    // 1.digits中比n[i]小的数随便放，此时个数等于 pow(digits.size(), k * (n.size() - i));
    // 即n剩余的位每一位都可以随便选，其中k是digits中比n[i]小的数的个数

    // 2.digits中等于n[i]的数贴着放，此时个数等于1 * (第i + 1位贴着放 + 第i + 1位比n[i + 1]小的随便放)
    // 3.前导0，此时个数等于1 * (i + 1位随便放 + 第i + 1位前导0)

	// 因为前导0和贴着放均为单独计算，且随便放的情况O(1)便可返回，所以递归树呈链状，同时digits长度为常量，二分时间可以忽略，所以时间复杂度为O(logn)
    int helper(const vector<int>& digits, const vector<int>& n, int flag, int cur_pos) { // flag: 0随便放, 1贴着放, 2前导0. (指包含第cur_pos位)
        if (flag == 0) {// 随便放
            if (cur_pos < 0) return 1;
            return pow(digits.size(), cur_pos + 1);
        }
        else if (flag == 1) { // 贴着放， 只有这里需要二分查找
            if (cur_pos < 0) return 1;
            int res = 0;
            auto u_bound = lower_bound(digits.begin(), digits.end(), n[cur_pos]);
            if (u_bound == digits.end()) return helper(digits, n, 0, cur_pos); // 全都小于n[cur_pos]改为随便选
            if (*u_bound == n[cur_pos]) res += helper(digits, n, 1, cur_pos - 1); // 可以继续贴着放
            res += (u_bound - digits.begin()) * helper(digits, n, 0, cur_pos - 1); // 随便放
            return res;
        } else { // 前导0
            if (cur_pos < 0) return 0;
            return helper(digits, n, 0, cur_pos - 1) + helper(digits, n, 3, cur_pos - 1);
        }
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<int> n_vec;
        while (n > 0) {
            n_vec.push_back(n % 10);
            n /= 10;
        }
        vector<int> i_digits;
        for (auto& each : digits) i_digits.push_back(stoi(each));
        return helper(i_digits, n_vec, 1, n_vec.size() - 1) + helper(i_digits, n_vec, 2, n_vec.size() - 1) - 1;
    }
};
