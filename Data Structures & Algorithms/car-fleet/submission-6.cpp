class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int> >vp;
        for(int i=0;i<position.size();i++)
        {
            vp.push_back({position[i],speed[i]});
        }
        sort(vp.begin(),vp.end());
        stack<float>st;
        int n=speed.size();
        for(int i=n-1;i>=0;i--)
        {
            float time=(target-vp[i].first)/(float)vp[i].second;
            //cout<<time<<" ";
            if(st.empty()) st.push(time);
            else if(st.top()<time)
            {
                st.push(time);
            }
        }
        
        return st.size();
    }
};
