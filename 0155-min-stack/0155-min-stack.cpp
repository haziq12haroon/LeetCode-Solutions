class MinStack {
private:
    stack<int> s1, hs1;
    
public:
    MinStack() {
        
    }
    
    void push(int value) {
        s1.push(value);
        if (hs1.empty() || hs1.top() >= value) {
            hs1.push(value);
        }
    }
    
    void pop() {
        if (s1.top() == hs1.top()) {
            hs1.pop();
        }
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return hs1.top();
    }
};