class MinStack {
public:
    stack<long long>st;
    long long mini = LLONG_MAX;
    MinStack() {
        
    }
    
    void push(int val) {    
        if(st.empty()){
            st.push(val);
            mini = val;
        }else if(val < mini){
            long long updated = 2LL * val - mini;
            st.push(updated);
            mini = val;
        }else{
            st.push(val);
        }
    }
    
    void pop() {
        if(st.top() < mini){
            mini = 2LL * mini - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < mini){
            return (int)mini;
        }
        return (int)st.top();
    }
    
    int getMin() {
        return (int)mini;
    }
};
