// 简单的模拟题

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level = 0;
        for (auto& s : logs) {
            if (s == "../") level -= (level > 0) ? 1 : 0;
            else if (s == "./") level += 0;
            else ++level;
        }
        return level;
    }
};
