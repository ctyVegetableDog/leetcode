//简单的模拟题（调了老子大半小时，wrng）

class Solution {
public:
    string reorderSpaces(string text) {
        int blankCnt = 0, len = text.size();
        vector<string> v;
        string temp;
        for (auto& c : text) {
            if (c == ' ') {
                if (!temp.empty()) {
                    v.push_back(temp);
                    temp.clear();
                }
                ++blankCnt;
            } else {
                temp.push_back(c);
            }
        }
        if (!temp.empty()) {
            v.push_back(temp);
        }
        if (blankCnt == 0) return text;
        int vlen = v.size(), n = vlen == 1 ? 0 : blankCnt / (vlen - 1); //相邻单词空格数
        int t = 0;
        for (int i = 0; i < vlen - 1; ++i) {
            for (int j = 0; j < v[i].size(); ++j) {
                text[t] = v[i][j];
                ++t;
            }
            for (int m = 0; m < n; ++m) {
                text[t] = ' ';
                ++t;
            }
        }
        for (int j = 0; j < v[vlen - 1].size(); ++j) {
                text[t] = v[vlen - 1][j];
                ++t;
            }
        for (;t < len; ++t) text[t] = ' ';
        return text;
    }
};
