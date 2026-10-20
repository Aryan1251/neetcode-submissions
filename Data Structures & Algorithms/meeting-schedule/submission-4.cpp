/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
    bool static myComp(Interval a,Interval b)
    {
        return a.start<b.start;
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.empty()) return 1;
        sort(intervals.begin(),intervals.end(),myComp);
        if(intervals.size()==1) return 1;
        int i=0,j=1,n=intervals.size(),cnt=0;

        while(i<n && j<n)
        {
            if(intervals[j].start>=intervals[i].end)
            {
                cnt++;
                i=j;
                j++;
            }else
            {
                j++;
            }
        }
        return cnt==n-1;
    }
};
