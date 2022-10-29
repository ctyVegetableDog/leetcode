// 统计匹配检索规则的物品数量

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0;
        for (auto& each : items) {
            if ((ruleKey == "type" && ruleValue == each[0]) || (ruleKey == "color" && ruleValue == each[1]) || (ruleKey == "name" && ruleValue == each[2])) ++ans;
        }
        return ans;
    }
};
