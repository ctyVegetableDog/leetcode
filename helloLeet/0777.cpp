// 在LR字符串中交换相邻字符(7777777)

class Solution {
public:
    /*
    将"X"看做空位
    "LX"替换"XL"，看做将"L"左移了一格
    “XR”替换"RX"，看做将"R"右移了一格
    问题转化为所有L和R的顺序固定，中间有多个空格，L可以左移，R可以右移问能不能移动成end的样子
    即所有序号相同的L，在start中需要比end中后出现，序号相同的R，在start中需要先出现
    */
    bool canTransform(string start, string end) {
        int lens = start.size(), lene = end.size();
        if (lens != lene) return false;
        int i = 0, j = 0;
        while (i < lens) {
            if (start[i] == 'R') {
                while (j < lene && end[j] == 'X') ++j;
                if (j == lene || end[j] == 'L' || j < i) return false;
                else ++j;
            } else if (start[i] == 'L') {
                while (j < lene && end[j] == 'X') ++j;
                if (j == lene || end[j] == 'R' || i < j) return false;
                else ++j;
            }
            ++i;
        }
        while (j < lene) {
            if (end[j] != 'X') return false;
            ++j;
        }
        return true;
    }
};
