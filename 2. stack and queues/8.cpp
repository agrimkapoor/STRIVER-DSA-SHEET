// implement min stack : leetcode 155 

class MinStack {
public:
    stack<int>s1;
    stack<int>s2;
    MinStack() {
        
    }
    
    void push(int value) {
        s1.push(value);

        if(s2.empty() or s2.top() >= value)s2.push(value);
    }
    
    void pop() {
        if(s1.top() == s2.top())s2.pop();
        s1.pop();

    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

