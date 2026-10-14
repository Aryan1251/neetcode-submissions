class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int> >ans;
        ans.push_back(intervals[0]);
        int n=intervals.size();

        for(int i=1;i<n;i++)
        {
            auto prev_vec=ans.back();
            if(prev_vec[1]>=intervals[i][0])
            {
                int val1=prev_vec[0];
                int val2=max(prev_vec[1],intervals[i][1]);
                ans.pop_back();
                ans.push_back({val1,val2});
            }else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;

    }
};
