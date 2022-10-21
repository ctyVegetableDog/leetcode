// 股票价格跨度

/*
 *单调栈
 使用额外weight来保存信息的方法确实学到了
 * */

class StockSpanner {
private:
    stack<pair<int, int>> st; // 单调递减栈 pair<price, weight>表示{价格，离上一个比它大的元素的距离}，如{11, 3, 5, 7}当入5弹3的时候，希望继续保留3作为一个位置的信息，即入{5,3}，同理当入7的时候入{7, 3}
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int w = 1;
        while (!st.empty() && price >= st.top().first) {
            w += st.top().second;
            st.pop();
        }
        st.push({price, w});
        return w;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
