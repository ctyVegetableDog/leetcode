//just logic, but very impressive ques, still can't totally understand it

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int mp[26] = { 0 };
        for (char c : tasks) mp[c - 'A']++;
        sort(mp, mp + 26);
        int vals = mp[25] - 1, slots = vals * n;
        for (int i = 24; i >=0, mp[i] > 0; i --) slots -= min(mp[i], vals);//if mp[i] == mp[25], there will be 1 char left, as there are only (vals) vals
        return slots >= 0 ? slots + tasks.size() : tasks.size();
    }
};
