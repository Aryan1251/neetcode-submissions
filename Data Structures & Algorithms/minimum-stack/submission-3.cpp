class MinStack {
public:
    vector<pair<int,int> >vp;
    int min_element=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(vp.empty())
        {
            vp.push_back({val,val});
            return ;
        }
        int prev_min=vp.back().second;
        vp.push_back({val,min(prev_min,val)});
        return ;
    }
    
    void pop() {
        if(vp.empty()) return ;
        vp.pop_back();
    }
    
    int top() {
        if(vp.empty()) return -1;
        return vp.back().first;
    }
    
    int getMin() {
        if(vp.empty()) return -1;
        return vp.back().second;
    }
};
