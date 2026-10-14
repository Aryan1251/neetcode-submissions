class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int> >st;
        vector<int>ans;
        int n=temperatures.size();
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                st.push({temperatures[i],0});
                ans.push_back(0);
            }else if(st.top().first>temperatures[i])
            {
                st.push({temperatures[i],1});
                ans.push_back(1);
            }else
            {
                int cnt=0;
                while(!st.empty() && st.top().first<=temperatures[i])
                {
                    cnt+=st.top().second;
                    st.pop();
                }
                if(st.empty())
                {
                    st.push({temperatures[i],0});
                    ans.push_back(0);
                }else
                {
                    st.push({temperatures[i],cnt+1});
                    ans.push_back(cnt+1);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
