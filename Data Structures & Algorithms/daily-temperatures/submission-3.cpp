class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int> >st;
        vector<int>v;
        int n=temp.size();
        for(int i=n-1;i>=0;i--)
        {
            int cnt=0;
            while(!st.empty() && st.top().first<=temp[i])
            {
                cnt+=st.top().second;
                st.pop();
            }
            if(st.empty())
            {
                st.push({temp[i],0});
                v.push_back(0);
            }else
            {
                st.push({temp[i],cnt+1});
                v.push_back(cnt+1);
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
