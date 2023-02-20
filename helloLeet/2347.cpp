// 最好的扑克手牌

class Solution {
public:
    bool checkFlush(const vector<char>& suits) {
        for(char c : suits) {
            if (c != suits[0]) return false;
        }
        return true;
    }

    bool checkThree(const vector<int>& ranks) {
        vector<int> rk(14, 0);
        for(int i : ranks) {
            if (++rk[i] >= 3) return true;
        }
        return false;
    }

    bool checkTwo(const vector<int>& ranks) {
        vector<int> rk(14, 0);
        for(int i : ranks) {
            if (++rk[i] >= 2) return true;
        }
        return false;
    }
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if (checkFlush(suits)) return "Flush";
        if (checkThree(ranks)) return "Three of a Kind";
        if (checkTwo(ranks)) return "Pair";
        return "High Card";
    }
};
