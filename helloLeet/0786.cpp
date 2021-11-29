// KthSmallestPrimeFraction
// 1.优先队列
// 以arr[i] / arr[j]构成分数，其中必有arr[i] < arr[j]且单调递增。所以相当于是构成了
// arr[0] / arr[1]
// arr[0]/arr[1] arr[1]/arr[2]
// arr[0]/arr[1] arr[1]/arr[2] arr[2]/arr[3]
// 这样的arr.size() - 1个有序序列，问题转化成从n - 1个序列中，寻找第k大i的数。
// 可以维护一个小端堆，堆里每个序列的元素都放一个分子下标为0，分母为j，然后每次更新分子下表就行
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        auto cmp = [&] (const pair<int, int> &a, const pair<int, int> &b) {
            return arr[a.first] * arr[b.second] > arr[b.first] * arr[a.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (int j = 1; j < n; ++j) {
            q.emplace(0, j);
        }
        for (int _ = 1; _ < k; _++) {
            auto [i, j] = q.top();
            q.pop();
            if (i + 1 < j) {
                q.emplace(i + 1, j);
            }
        }
        return {arr[q.top().first], arr[q.top().second]};
    }
};

//2.双指针 + 二分查找
//该问题可以转换成从【0，1】之间找到一个数A，使恰好youK个素数分数小于A，此时这K个分数中最大的就是答案
//从【0，1】之间找A其实相当于从有序序列中找一个数（虽然是连续的），所以可以用二分查找
//当小于A的分数个数 == K 时，返回当前记录的最大的分数，若 < K则说明A选小了，更新左端点，否则更新右端点
//问题转换成如何找到小于A的素数分数的个数
//可以用一个指针扫描j，分别计算以arr[j]为分母且小于A的素数分数的个数，此时可以用另一个指针扫描i，不断比较A和arr[i] / arr[j]
//假设j为分母，分子到了i为止满足条件（arr[0]/arr[j] 到 arr[i] / arr[j] )的个数为cnt，此事arr[0]~arr[i]中的每一个元素，当arr[j + 1]时做为分子依然成立，所以i可以不用每次换j都从头开始，每次i都从上一轮的位置开始，并且加上上一轮的个数cnt
//class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0.0, right = 1.0;
        while (true) { // 每个数A
            double mid = (right + left) / 2;
            int i = -1, cnt = 0, x = 0, y = 1;
            for (int j = 1; j < n; ++j) {
                while ((double)arr[i + 1] / arr[j] < mid) {
                    ++i;
                    if (arr[i] * y > arr[j] * x) {
                        x = arr[i];
                        y = arr[j];
                    }
                }
                cnt += i + 1;
            }
            if (cnt == k) return {x, y};
            else if(cnt < k) left = mid;
            else right = mid;
        }
    }
};
