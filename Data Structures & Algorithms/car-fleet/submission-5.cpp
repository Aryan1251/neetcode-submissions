class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        if(n==1) return 1;
        vector<pair<int,int> >vp;
        for(int i=0;i<n;i++)
        {
            vp.push_back({position[i],speed[i]});
        }
        sort(vp.begin(),vp.end());
        stack<float>st;
        for(int i=0;i<n;i++)
        {
            int pos=vp[i].first;
            int v=vp[i].second;
            float time=(float)(target-pos)/(float)v;
            while(!st.empty() && time>=st.top())
            {
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};
