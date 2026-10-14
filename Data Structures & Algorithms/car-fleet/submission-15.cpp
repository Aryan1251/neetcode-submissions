class Solution {
    bool static myComp(pair<int,int>& a,pair<int,int>& b)
    {
        return a.first>b.first;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float>st;
        vector<pair<int,int> >vp;
        int n=speed.size();
        for(int i=0;i<n;i++)
        {
            int pos=position[i];
            int v=speed[i];
            vp.push_back({pos,v});
        }
        sort(vp.begin(),vp.end(),myComp);
        for(int i=0;i<n;i++)
        {
            float T=(target-vp[i].first)/(float)(vp[i].second);
            if(st.empty()) st.push(T);
            else
            {
                if(st.top()<T) st.push(T);
            }
        }
        return st.size();

    }
};
