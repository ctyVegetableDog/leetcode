// display talbe
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> food;
        unordered_map<int, unordered_map<string, int>> mp;
        for (auto& e : orders) {
            food.insert(e[2]);
            mp[stoi(e[1])][e[2]]++;
        }
        vector<vector<string>> ans;
        vector<string> title;
        title.emplace_back("Table");
        vector<string> temp(food.begin(), food.end());
        sort(temp.begin(), temp.end());
        title.insert(title.end(), temp.begin(), temp.end());
        ans.push_back(title);
        vector<int> table;
        for (auto& [id,_] : mp) table.push_back(id);
        sort(table.begin(), table.end());
        int len = table.size(), title_len = temp.size();
        for (int i = 0; i < len; ++i) {
            vector<string> t;
            t.emplace_back(to_string(table[i]));
            for (int j = 0; j < title_len; ++j) t.emplace_back(to_string(mp[table[i]][temp[j]]));
            ans.push_back(t);
        }
        return ans;
    }
};
