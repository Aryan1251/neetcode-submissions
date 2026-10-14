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
        }else
        {
            int latMinimum=st.top().second;
            st.push({val,min(latMinimum,val)});
            return ;
        }
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
            int element=st.top().first;
            return element;
        }
        return -1;
    }
    
    int getMin() {
        if(!st.empty())
        {
            int minimumEle=st.top().second;
            return minimumEle;
        }
        return -1;
    }
};
