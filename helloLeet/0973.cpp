//K Cloest Points to Origin (priority_queue)

class Solution {
public:
    struct cmp {
      bool operator () (const vector<int> &p1, const vector<int> &p2) {
          return p1[0] * p1[0] + p1[1] * p1[1] > p2[0] * p2[0] + p2[1] * p2[1];
      }  
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int> >, cmp> pq= { points.begin(), points.end() };
        vector<vector<int> > res;
        while (K--) res.push_back(pq.top()), pq.pop();
        return res;
    }
};
