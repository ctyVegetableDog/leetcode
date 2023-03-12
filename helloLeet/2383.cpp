// 赢得比赛需要的最少训练时长

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans = 0, n = energy.size();
        for (int i = 0; i < n; ++i) {
            if (initialExperience <= experience[i]) {
                ans += (experience[i] - initialExperience + 1);
                initialExperience = experience[i] + 1;
            }
            initialExperience += experience[i];
            initialEnergy -= energy[i];
            if (initialEnergy <= 0) {
                ans -= (initialEnergy - 1);
                initialEnergy = 1;
            }
        }
        return ans;
    }
};
