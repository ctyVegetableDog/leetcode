// 不同的子序列2

class Solution {
public:
    /*
    dp[i]表示前i个字符可以组成不同子序列的个数
    扫描到第i个字符时 dp[i] = dp[i - 1] + new - repeat
    其中如果不选第i个字符，有dp[i - 1]种
    选第i个字符，在dp[i - 1]个字符后每个填上字符i，有dp[i - 1]种
    但其中有些会导致重复，需要减去
    比如a b c b， 假装维护一个当前添加的所有子串的数组
    扫描前 : ""
    a : "", a
    b : "", a, "" + b = b, a + b = ab
    c : "", a, b, ab, "" + c = c, ac, bc, abc
    b : "", a, b, ab, c ,ac ,bc, abc, ["" + b], [a + b], bb, abb, cb, acb, bcb, abcb
    可以看出，"" + b和 a + b都已经在第一个b的时候被添加过了，再假设有一个存放了前缀的数组prefix[26][]，该数组保存每个字符作为结尾的所有前缀
    当扫描完第一个b时 前缀将记录""和a，表示字符串""b和ab都计算过了
    同理当扫描完第二个b时，前缀将变为 "", a, b, ab, c, ac, bc, abc，表示这些字符串加上字符b都计算过了
    可以看出更新后prefix[b]的个数 = dp[i - 1]
    所以dp[i] = dp[i - 1] + new - repeat;
    更新repeat
    */
    int distinctSubseqII(string s) {
        int mod = (int) 1e9 + 7;
        int len = s.size();
        vector<int> pre_count(26, 0);
        int dp_pre = 1, new_ans = 0; // 空串
        for (int i = 0; i < len; ++i) {
            new_ans = dp_pre; // 新增
            dp_pre =((dp_pre + new_ans) % mod - pre_count[s[i] - 'a'] % mod + mod) % mod; // 妈个鸡，这个+mod卡死老子，可能(dp_pre + new_ans)取完mod之后比pre_count[s[i] - 'a']小
            pre_count[s[i] - 'a'] = new_ans;
        }
        return dp_pre - 1;
    }
};
