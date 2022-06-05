class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        if(s2.empty() ||  <= getMin()) s2.push(x);
    }
    
    void pop() {
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
private:
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
