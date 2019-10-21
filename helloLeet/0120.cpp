//dp without extra space

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int l = triangle.size();
        int z = 2;
        int res = INT_MAX;
        for (int i = 1; i < l; i ++){
            for (int j = 0; j < z; j++){
                if (j == 0) triangle[i][j] += triangle[i - 1][j];
                else if (j == z - 1) triangle[i][j] += triangle[i - 1][z - 2];
                else triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
            z++;
        }
        for (int n:triangle[l - 1]) 
            res = min(res, n);
        return res;
    }
};
