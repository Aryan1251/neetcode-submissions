class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(newInterval.empty()) return intervals;
        if(intervals.empty())
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int> >v;
        bool flag=1;
        int n=intervals.size();
        for(int i=0;i<n;i++)
        {
            if(v.empty())
            {
                v.push_back(intervals[i]);
            }else if(flag && v.back()[0]<newInterval[0] && newInterval[0]<intervals[i][0])
            {
                v.push_back(newInterval);
                v.push_back(intervals[i]);
                flag=0;
            }else
            {
                v.push_back(intervals[i]);
            }
        }
        if(flag)
        {
            if(v[n-1][0]<newInterval[0])
            {
                v.push_back(newInterval);
            }else
            {
                v.insert(v.begin(),newInterval);
            }
        }
        vector<vector<int> >ans;
        n=v.size();
        for(int i=0;i<n;i++)
        {
            if(ans.empty()) ans.push_back(v[i]);
            else if(ans.back()[1]>=v[i][0])
            {
                int val=max(ans.back()[1],v[i][1]);
                ans.back()[1]=val;
            }else
            ans.push_back(v[i]);
        }
        return ans;
    }
};
