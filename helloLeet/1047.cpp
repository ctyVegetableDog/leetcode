//Remove repeat in string
class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        for(char ch : S) {
            if(!res.empty() && res.back() == ch) res.pop_back();
            else res.push_back(ch);
        }
        return res;
    }
};
