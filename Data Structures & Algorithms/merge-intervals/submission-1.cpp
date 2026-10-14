class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int> >ans;
        ans.push_back(intervals[0]);
        int n=intervals.size();
        for(int i=1;i<n;i++)
        {
            auto prevInterval=ans.back();
            int x=prevInterval[0];
            int y=prevInterval[1];
            if(intervals[i][0]>y) ans.push_back(intervals[i]);
            else
            {
                if(!ans.empty()) ans.pop_back();
                y=max(y,intervals[i][1]);
                ans.push_back({x,y});
            }
        }
        return ans;
    }
};
