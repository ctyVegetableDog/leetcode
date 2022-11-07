// 模糊坐标

class Solution {
public:
    // 给s添加小数点成为一个合法数
    // s要么是一个整数，此时s开头不能为0
    // 要么是一个小数，整数部分若不为0开头不能为0，小数部分结尾不能为0
    vector<string> addPoint(const string& s) {
        vector<string> numbers;
        if (s == "0" || s[0] != '0') numbers.push_back(s); // s为整数
        for (int p = 1; p < s.size(); ++p) {
            if (p != 1 && s[0] == '0' || s.back() == '0') continue; // 跳过非法的
            numbers.push_back(s.substr(0, p) + '.' + s.substr(p));
        }
        return numbers;
    }
    vector<string> ambiguousCoordinates(string s) {
        s.pop_back();
        s.erase(s.begin());
        int len = s.size();
        vector<string> ans;
        for (int i = 1; i < len; ++i) {
            vector<string> lp = addPoint(s.substr(0,i));
            if (lp.empty()) continue; // 如果分割后有任意一边无法生成合法坐标，那么就跳过
            vector<string> rp = addPoint(s.substr(i));
            if (rp.empty()) continue;
            for (auto& l_each : lp) {
                for (auto& r_each : rp) {
                    ans.push_back("(" + l_each + ", " + r_each + ")");
                }
            }
        }
        return ans;
    }
};
