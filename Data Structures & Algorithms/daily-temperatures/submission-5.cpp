class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int> >st;
        vector<int>ans;
        int cnt=0,n=temperatures.size();
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                st.push({temperatures[i],0});
                ans.push_back(0);
            }
            else
            {
                int cnt=1;
                while(!st.empty() && st.top().first<=temperatures[i])
                {
                    cnt+=st.top().second;
                    st.pop();
                }
                if(st.empty())
                {
                    st.push({temperatures[i],0});
                    ans.push_back(0);
                }else{
                    st.push({temperatures[i],cnt});
                    ans.push_back(cnt);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
