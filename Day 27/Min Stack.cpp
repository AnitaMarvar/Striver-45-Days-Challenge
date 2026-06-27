class MinStack {
public:
    stack<int>st1, st2;
    MinStack() { 
    }
    
    void push(int value) {
        if(st2.empty() || st2.top() >= value)
        {
            st2.push(value);
        }
        st1.push(value);
    }
    
    void pop() {
        if(!st1.empty())
        {
            if(!st2.empty() && st1.top() == st2.top())
            {
                st2.pop();
            }
            st1.pop();
        }
    }
    
    int top() {
        if(!st1.empty())
        {
            return st1.top();
        }
        return -1;
    }
    
    int getMin() {
        if(!st2.empty())
        {
            return st2.top();
        }
        return 0;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
