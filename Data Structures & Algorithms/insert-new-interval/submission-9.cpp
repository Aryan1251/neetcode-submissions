class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        if(n==0 && newInterval.size()==0) return {};
        vector<vector<int> >ans;
        bool flag=0;
        for(int i=0;i<n;i++)
        {
            if(i!=n-1 && flag==0 && newInterval[0]>intervals[i][0] && newInterval[0]<intervals[i+1][0])
            {
                ans.push_back(intervals[i]);
                ans.push_back(newInterval);
                flag=1;
            }else
            ans.push_back(intervals[i]);
        }
        if(flag==0)
        {
            if(n-1>=0 && newInterval[0]<intervals[n-1][0])
            ans.insert(ans.begin(),newInterval);
            else
            ans.push_back(newInterval);

        }
        vector<vector<int> >v;
        for(int i=0;i<ans.size();i++)
        {
            if(v.empty()) v.push_back(ans[i]);
            else
            {
                if(v.back()[1]>=ans[i][0])
                {
                    int val1=v.back()[0];
                    int val2=max(v.back()[1],ans[i][1]);
                    v.pop_back();
                    v.push_back({val1,val2});
                }else
                v.push_back(ans[i]);
            }
        }
        return v;

    }
};
