class MinStack {
    stack<pair<int,int>> s;
    int minn;
public:
    MinStack() {
        minn=INT_MAX;
    }
    
    void push(int val) {
        minn=min(minn,val);
        s.push({val,minn});
    }
    
    void pop() {
        s.pop();
        if(!s.empty()) minn=s.top().second;
        else minn=INT_MAX;
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */