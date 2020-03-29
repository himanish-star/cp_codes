#include<bits/stdc++.h>

using namespace std;

class MinStack {
private: 
    stack<int> st1;
    stack<int> st2;
public:
    /** initialize your data structure here. */
    MinStack() {
        while(st1.size())
            st1.pop();
        
        while(st2.size())
            st2.pop();
    }
    
    void push(int x) {
        st1.push(x);
        if(!st2.size() || x<=getMin())
            st2.push(x);
    }
    
    void pop() {
        if(st2.size() && st1.top()==getMin())
            st2.pop();
        if(st1.size()) st1.pop();
    }
    
    int top() {
        if(st1.size())
            return st1.top();
        return 0;
    }
    
    int getMin() {
        if(st2.size())
            return st2.top();
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */