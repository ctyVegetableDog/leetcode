//two stacks

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        return;
    }
    
    void push(int x) {
        if (nums.empty() || x <= mins.top()) mins.push(x);
        nums.push(x);
        return;
    }
    
    void pop() {
        if (mins.top() == nums.top()) mins.pop();
        nums.pop();
        return;
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return mins.top();
    }
    
private:
    stack<int> nums;
    stack<int> mins;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
