class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int> >vp;
        int n=speed.size();
        for(int i=0;i<n;i++)
        {
            vp.push_back({position[i],speed[i]});
        }
        sort(vp.begin(),vp.end());
        stack<double>st;
        for(int i=n-1;i>=0;i--)
        {
            double val=((target-vp[i].first)/(double)vp[i].second);
            if(st.empty())
            {
                st.push(val);
            }else
            {
                if(val>st.top()) st.push(val);
            }
        }
        return st.size();
    }
};
