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
        int minEle=st.top().second;
        st.push({val,min(minEle,val)});
        return ;
    }
    
    void pop() {
        if(!st.empty())
        {
            st.pop();
            return ;
        }
        return ;
    }
    
    int top() {
        if(!st.empty())
        {
            int topEle=st.top().first;
            return topEle;
        }
        return -1;
    }
    
    int getMin() {
        if(!st.empty())
        {
            int minEle=st.top().second;
            return minEle;
        }
        return -1;
    }
};
