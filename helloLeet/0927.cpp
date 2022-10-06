// 三等分

/*
 *如果能3等分，则arr中1的数量必然能被3整除，且每个数必然含有num_one / 3个1
 依次找到第1,1 + num_one, 1 + 2 * num_one个1，作为开始位置，记为first,second和third
 此时无法确定third前面的0是属于第三个数的前导零还是第二个数的末尾，但可以确定的是，从third到arr结尾就是第三个数的值
 所以依次从first, second, third开始走，当third到arr结尾时second就在第三个数的开头，first在第二个数的开头
 * */

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n_ones = 0, fisrt = -1, second = -1, third = -1, len = arr.size();
        for (int i = 0; i < len; ++i) if (arr[i] == 1) ++n_ones;
        if (n_ones == 0) return {0, 2};
        if (n_ones % 3 != 0) return {-1, -1};
        int inter = n_ones / 3;
        for (int i = 0;i < len; ++i) {
            if (arr[i] == 1) { // 扫描到1
                if (fisrt == -1) fisrt = i;
                else if (inter == 0) {
                    if (second == -1) {
                        second = i;
                        inter = n_ones / 3;
                    } else {
                        third = i;
                        break;
                    }
                }
                --inter;
            }
        }
        while (third < len) {
            if (!(arr[fisrt] == arr[second] && arr[fisrt] == arr[third])) return {-1,-1};
            ++fisrt;
            ++second;
            ++third;
        }
        return {fisrt - 1, second};
    }
};
