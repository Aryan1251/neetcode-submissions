class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int>ans;
        int n=intervals.size();
        for(auto q: queries)
        {
            int minLen=INT_MAX;
            for(auto it: intervals)
            {
                if(q>=it[0] && q<=it[1])
                minLen=min(minLen,it[1]-it[0]+1);
            }
            minLen=minLen==INT_MAX?-1:minLen;
            ans.push_back(minLen);
        }
        return ans;
    }
};
