// 经典题目接雨水

// 法一，DP
/*
 * DP是最朴素的想法，一根柱子所在的位置可以接雨水的量由其左侧所有柱子中最高的那个和右侧所有柱子中最高的那个中的较短的柱子决定的，所以可以先从前往后从后往前遍历两遍所有柱子，记录每个柱子左侧所有柱子中的最大值和右侧所有柱子中的最大值
 * */
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size(), res = 0;
        if(len == 0) return 0;
        vector<int> leftmax(len), rightmax(len);
        leftmax[0] = height[0];
        for (int i = 1; i < len; ++i) leftmax[i] = max(leftmax[i - 1], height[i]);
        rightmax[len - 1] = height[len - 1];
        for (int i = len - 2; i >= 0; --i) rightmax[i] = max(rightmax[i + 1], height[i]);
        for (int i = 0; i < len; ++i) res += min(leftmax[i], rightmax[i]) - height[i];
        return res;
    }
};

//法二，单调栈
/*
 *对于每一个柱子，不仅将其看做端点也看做支点。维护一个单调递减栈，对于每一根柱子，如果其比栈顶柱子短则说明其目前无法作为右端点和栈中其他柱子形成积水，直接入栈。如果其比栈顶元素大，那么说明对于当前栈顶元素s，s比其（栈中）下方元素和当前扫描到的元素都小，将s看做支点则可以积水，该支点支撑一段区间，左端点和右端点分别是s下方元素和当前扫描到的元素，该段中每一小段的积水量都是s下方元素和当前扫描到的元素较小的那个减去s。也就是说，每个区间的水是一层一层积累的，不是每一小段一次积累完的， 比如4235，2那里可以即2格水，其中当用3作为支点时积一格，5做支点再积一格（另外栈中存的是柱子的下标）
 * */

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> st; // 存放柱子的下标
        for (int i = 0; i < height.size(); ++i) { //对于每一根柱子先看做右端点
            while (!st.empty() && height[st.top()] < height[i]) { //取每一个比当前右端点小的元素
                int idx = st.top(); st.pop();
                if (!st.empty()) //如果还有端点能作为左端点
                    ans += (min(height[st.top()], height[i]) - height[idx]) * (i - st.top() - 1); // 积水的长是左右端点的距离，高是支点和端点中矮的那个的差值。
            }
            st.push(i); //放入栈中，下次作为支点
        }
        return ans;
    }
};

//法三，双指针
/*
 *O(1)空间的解法，根据DP解法，leftmax数组必然是从左往右递增的而rightmax必然是从左往右递减的（越往左访问其左侧被访问过的柱子越多，即最高的柱子也越高，从右往左更新rightmax同理）。根据此，设置从左往右和从右往左两个指针left和right，而因为left永远小于等于right，所以必然有left_leftmax <= right_leftmax，且left_rightmax >= right_rightmax，所以每次只要比较left_leftmax和right_rightmax就可以更新left或是right
 * */

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1; //同时更新两个位置可以储存的雨水
        int leftMax = 0, rightMax = 0; // leftMax是left左侧（包括left）柱子高度的最大值，rightMax是right右侧（包括right）柱子高度的最大值
        while (left < right) { //直到两个指针碰面
            leftMax = max(leftMax, height[left]); //更新left
            rightMax = max(rightMax, height[right]); //更新right
            if (leftMax < rightMax) { //重点就在这里，其实同时有left_leftMax, left_rightMax, right_leftMax, right_rightMax，如果想要计算left位置能接的水量，需要取left_leftMax和left_rightMax中较小的那个，但是根据DP解法，leftMax从左往右递增而rightMax从左往右递减，即无论何时必然有left_rightMax >= right_rightMax且left_leftMax <= right_leftMax。如果已知right_rightMax > left_leftMax，那么必有left_rightMax > left_leftMax，即可以用left_leftMax计算left处的积水量，而不用实际知道left_rightMax是多少。所以只需要保存left_leftMax和right_rightMax就行
                ans += leftMax - height[left];
                ++left;
            } else {
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};
