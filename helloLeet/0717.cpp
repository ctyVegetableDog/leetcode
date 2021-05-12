//1-bit and 2-bit Characters

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int cnt = 0;
        for (int i = bits.size() - 2; i >= 0 && bits[i] == 1; --i) cnt ++;
        return !(cnt % 2);
    }
};
