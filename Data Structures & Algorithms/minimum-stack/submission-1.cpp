class MinStack {
public:
    stack<pair<int, int> >minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        if (minStack.empty() || minStack.top().second > val) {
            minStack.push({val, val});
        }
        else {
            minStack.push({val, minStack.top().second});
        }
    }
    
    void pop() {
        minStack.pop();
    }
    
    int top() {
        return minStack.top().first;
    }
    
    int getMin() {
        return minStack.top().second;
    }
};
