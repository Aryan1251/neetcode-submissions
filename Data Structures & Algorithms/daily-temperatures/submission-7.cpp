class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int> >st;
        vector<int>ans;
        int n=temp.size();
        for(int i=n-1;i>=0;i--)
        {
            int cnt=0;
            while(!st.empty() && st.top().first<=temp[i])
            {
                cnt+=st.top().second;
                st.pop();
            }
            if(st.empty()) st.push({temp[i],0});
            else
            st.push({temp[i],cnt+1});
            ans.push_back(st.top().second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
