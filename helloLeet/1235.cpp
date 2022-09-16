// 规划兼职工作

/*
 *记得以前刷网易还是哪的题目还让我受过一次苦
 * */

//法一：暴力递归（超时）

/*
 *对于每一个工作，都选择做或者不做
 想法很朴素但给接下来的方法做铺垫
 * */
class Solution {
public:
    int helper(vector<tuple<int, int, int>>& jobs, int idx, int startTime) {
        if (idx >= jobs.size()) return 0; // 如果没有工作可做了，那么不赚钱
        int do_profit = get<0>(jobs[idx]) >= startTime ? get<2>(jobs[idx]) + helper(jobs, idx + 1, get<1>(jobs[idx])) : 0; // 如果做此工作，从下一个工作开始考虑，下一个工作流的开始时间是当前工作的结束时间，另外如果当前工作的开始时间比当前时点要早，那么不可以做，直接返回0
        int not_do_profit = helper(jobs, idx + 1, startTime); // 如果不做此工作，从下一个工作开始考虑，且不花费时间，工作流开始时间不变
        return max(do_profit, not_do_profit); // idx号工作做和不做哪个收益高
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<tuple<int, int, int>> jobs;
        for (int i = 0; i < startTime.size(); ++i) {
            jobs.push_back(make_tuple(startTime[i], endTime[i], profit[i]));
        }
        sort(jobs.begin(), jobs.end(), [](tuple<int, int ,int> a, tuple<int, int, int> b) {
            return get<0>(a) < get<0>(b);
        });
        return helper(jobs, 0, 1);
    }
};

//法二：记忆化搜索DP（超时，但能跑更多数据）

/*
 *如果某个状态的idx和startTime是确定的，那么它的profit就是确定的，也就是说递归树中的结点仅有这两个数据决定，所以可以将树中结点信息存起来避免重复计算
 另外C++里unordered_map要用pair做key得重写hash
 * */

class Solution {
private:
    struct pair_hash {
        template<class T1, class T2>
        size_t operator()(const pair<T1, T2>& pair) const {
            return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
        }
    };
    unordered_map<pair<int, int>, int, pair_hash> mp; // 若某个时点的当前可处理工作（idx）和开始时间（startTime）确定，则profit就是确定的，可使用记忆化搜索
public:
    int helper(vector<tuple<int, int, int>>& jobs, int idx, int startTime) {
        if (idx >= jobs.size()) return 0; // 如果没有工作可做了，那么不赚钱
        if (mp.find({idx, startTime}) != mp.end()) return mp[{idx, startTime}];
        int do_profit = get<0>(jobs[idx]) >= startTime ? get<2>(jobs[idx]) + helper(jobs, idx + 1, get<1>(jobs[idx])) : 0; // 如果做此工作，从下一个工作开始考虑，下一个工作流的开始时间是当前工作的结束时间，另外如果当前工作的开始时间比当前时点要早，那么不可以做，直接返回0
        int not_do_profit = helper(jobs, idx + 1, startTime); // 如果不做此工作，从下一个工作开始考虑，且不花费时间，工作流开始时间不变
        int cur_max = max(do_profit, not_do_profit);
        mp[{idx, startTime}] = cur_max;
        return cur_max; // idx号工作做和不做哪个收益高
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<tuple<int, int, int>> jobs;
        for (int i = 0; i < startTime.size(); ++i) {
            jobs.push_back(make_tuple(startTime[i], endTime[i], profit[i]));
        }
        sort(jobs.begin(), jobs.end(), [](tuple<int, int ,int> a, tuple<int, int, int> b) {
            return get<0>(a) < get<0>(b);
        });
        return helper(jobs, 0, 1);
    }
};

//法三：二分查找（超时，不懂为什么能跑的数据量比暴力少了）

/*
 *递归很大一部分是get<0>(jobs[idx]) < startTime即当前时间点已经超过了当前扫描到的工作的情况，此时将陷入无意义的无脑不做工作直到扫描到满足开始时间大于当前时间点的工作为止
 其实此时可以使用二分用logn的时间找下一个可以做的工作避免无意义的遍历
 * */

class Solution {
private:
    vector<int> bs_v; // 保存排序后的开始时间，用于二分查找下一个能做的工作
public:
    int helper(vector<tuple<int, int, int>>& jobs, int idx, int startTime) {
        if (idx >= jobs.size()) return 0; // 如果没有工作可做了，那么不赚钱

        auto nxt = lower_bound(bs_v.begin() + idx, bs_v.end(), startTime); //用二分查找寻找下一个可以做的工作
        if (nxt == bs_v.end()) return 0; //如果没有工作可以做了（所有剩余工作的开始时间都大于startTime）则接下来获利为0
        int job_can_do = nxt - bs_v.begin(); //下一个可做工作的idx
        int do_profit = get<2>(jobs[job_can_do]) + helper(jobs, job_can_do + 1, get<1>(jobs[job_can_do])); // 做找到的可以做的工作
        int not_do_profit = helper(jobs, job_can_do + 1, startTime); // 不做
        int cur_max = max(do_profit, not_do_profit);
        return cur_max;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<tuple<int, int, int>> jobs;
        for (int i = 0; i < startTime.size(); ++i) {
            jobs.push_back(make_tuple(startTime[i], endTime[i], profit[i]));
        }
        sort(jobs.begin(), jobs.end(), [](tuple<int, int ,int> a, tuple<int, int, int> b) {
            return get<0>(a) < get<0>(b);
        });
        for (auto& job : jobs) { //将排序后的工作的开始时间保存，用于查找
            bs_v.push_back(get<0>(job));
        }
        return helper(jobs, 0, 1);
    }
};

//法四：递推DP

/*
 以上几个方法的核心思想都是考虑某个工作做或是不做，那么就不可避免使用递归的思想。现在换一个思路，将工作按照结束时间排序，然后将整个从第一个工作开始到最后一个工作结束的时间按一个工作一个工作分割成多个时间段jobs，考虑在每个工作jobs[i]结束的那个时间点时job.endTime，可以获得的利润的最大值。而该利润的最大值只可能在两种时候取到，第一种是jobs[i-1]的利润时保存的利润最大值，此时意味着不做第i号工作，该值可以直接取到，不用递归。另一种是做第i号工作，此时的利润是第i号工作的利润 + jobs[i]的开始时间前（或等于开始时间时）结束的那些工作（即意味着完成这些工作后可以开始做第i号工作）的利润最大值，而因为利润最大值具有和结束时间相同的单调性，所以等价于，从第i号之前的那些（按结束时间排序的）工作中，找到第一个结束时间小于等于第i号工作开始时间的工作。可以用二分查找直接找到，也不用递归。
 */

 class Solution {
private:
    vector<int> et_v; // 保存排序后的结束时间，用于二分查找
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int, int, int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back(make_tuple(startTime[i], endTime[i], profit[i]));
        }
        /*
        按照结束时间排序
        */
        sort(jobs.begin(), jobs.end(), [](tuple<int, int ,int> a, tuple<int, int, int> b) {
            return get<1>(a) < get<1>(b);
        });

        for (int i = 0; i < n; ++i) et_v.push_back(get<1>(jobs[i])); //将排好序的结束时间保存，用于二分

        vector<int> dp(startTime.size() + 1, 0); //dp[i + 1]表示第i号工作结束那个时点，所能获得的利润的最大值
        for (int i = 1; i <= n; ++i) {
            int idx = upper_bound(et_v.begin(), et_v.begin() + (i - 1), get<0>(jobs[i - 1])) - et_v.begin();// 查找之前的工作中，第一个结束时间大于第i号工作开始时间的工作
            int do_profit = get<2>(jobs[i - 1]) + dp[idx]; //做该工作（因为idx比最后一个小雨等于第i号工作开始时间的工作的编号大1，而dp[i]的编号又正好比et_v的编号大1，可以直接使用，比如如果idx = 0，说明第0号工作的结束时间就比当前工作的开始时间晚，如果做当前工作则不能做之前任何工作，即dp[idx] = 0，而正好dp[0]确实等于0）
            dp[i] = max(dp[i - 1], do_profit); //最大利润是做第i-1号工作（这里工作从1开始编号，这里第i号工作对应jobs里的第i-1号工作）和不做该工作中更大的那个，不做就是dp[i-1]（这个i是dp里的i）
        }
        return dp[n];
    }
};
