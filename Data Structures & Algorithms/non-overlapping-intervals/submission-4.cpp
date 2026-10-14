class Solution {
    bool static myComp(vector<int>& a,vector<int>& b)
    {
        return a[1]<b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),myComp);
        int i=0,j=1,cnt=0,n=intervals.size();
        while(i<n && j<n)
        {
            if(intervals[i][1]<=intervals[j][0]) 
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
