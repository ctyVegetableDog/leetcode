// filp 2D vector
class Solution {
private:
    int max_num;
    unordered_map<int, int> mp;
    int m;
    int n;
public:
    Solution(int n_rows, int n_cols) {
        max_num = n_cols * n_rows;
        m = n_rows;
        n = n_cols;
    }
    
    vector<int> flip() {
        int key = rand() % (max_num--);
        int val = (mp.find(key) == mp.end()) ? key : mp[key];
        mp[key] = (mp.find(max_num) == mp.end()) ? max_num : mp[max_num];
        return {val / n, val % n};
    }
    
    void reset() {
        mp.clear();
        max_num = m * n;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
