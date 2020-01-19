//rubbish ques

class Solution {
private:
    vector<int> w;
public:
    Solution(vector<int>& w) {
        this->w = w;
        for (int i = 1; i < w.size(); i ++) {
            this->w[i] += this->w[i - 1];
        }
    }
    
    int pickIndex() {
        int r = rand() % w[w.size() - 1] + 1;
        return lower_bound(w.begin(), w.end(), r) - w.begin();
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
