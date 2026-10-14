class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double>st;
        vector<pair<int,int> >v;
        int n=speed.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end());
        for(int i=n-1;i>=0;i--)
        {
            int pos=v[i].first;
            int s=v[i].second;
            double t=(double)(target-pos)/s;
            //cout<<t<<" ";
            if(st.empty()) st.push(t);
            else if(t>st.top()) st.push(t);
        }
        return st.size();
    }
};
