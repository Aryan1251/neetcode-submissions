class MinStack {
public:
    stack<pair<int,int> >st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push({val,val});
            return ;
        }
        int currMin=st.top().second;
        st.push({val,min(currMin,val)});
        return ;
    }
    
    void pop() {
        if(!st.empty()) st.pop();
        return ;
    }
    
    int top() {
        if(st.empty()) return -1;
        int element=st.top().first;
        return element;
    }
    
    int getMin() {
        if(st.empty()) return -1;
        int minEle=st.top().second;
        return minEle;
    }
};
