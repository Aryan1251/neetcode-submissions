class Solution {
    private:
    bool static myComp(vector<int>& a,vector<int>& b)
    {
        return a[1]<b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),myComp);
        int i=0,j=1,n=intervals.size();
        int cnt=0;
        while(j<n)
        {
            if(intervals[j][0]>=intervals[i][1])
            {
                i=j;
                j++;
            }else
            {
                cnt++;
                j++;
            }
        }
        return cnt;
    }
};
