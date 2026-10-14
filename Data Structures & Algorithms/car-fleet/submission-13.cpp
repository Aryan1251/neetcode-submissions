class Solution {
    bool static myComp(pair<int,int>& a,pair<int,int>& b)
    {
        return a.first>b.first;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int> >vp;
        int n=speed.size();
        for(int i=0;i<n;i++)
        {
            vp.push_back({position[i],speed[i]});
        }
        sort(vp.begin(),vp.end(),myComp);
        stack<float>st;
        for(auto it: vp)
        {
            int dis=target-it.first;
            int sp=it.second;
            float T=(float)dis/sp;
            if(st.empty()) st.push(T);
            else
            {
                if(st.top()<T) st.push(T); 
            }
        }
        return st.size();
    }
};
