// 无法吃午餐的学生

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int like_1 = accumulate(students.begin(), students.end(), 0);
        int like_0 = students.size() - like_1;
        for (int i = 0; i < sandwiches.size(); ++i) {
            if (sandwiches[i] == 1 && like_1 > 0) --like_1;
            else if (sandwiches[i] == 0 && like_0 > 0) --like_0;
            else break;
        }
        return like_0 + like_1;
    }
};
