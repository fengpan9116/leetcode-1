class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        vst.push(x);
        if (mst.empty() || x <= mst.top())
            mst.push(x);
    }
    
    void pop() {
        if (vst.empty()) throw runtime_error("dumbass");
        if (!mst.empty() && vst.top() == mst.top())
            mst.pop();
        vst.pop();
    }
    
    int top() {
        if (vst.empty()) throw runtime_error("buffoon");
        return vst.top();
    }
    
    int getMin() {
        if (mst.empty()) throw runtime_error("imbecile");
        return mst.top();
    }
private:
    stack<int> vst;
    stack<int> mst;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */