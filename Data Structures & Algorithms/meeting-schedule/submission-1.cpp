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
    bool static myComp(Interval &a,Interval &b)
    {
        return a.end<b.end;
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),myComp);
        int i=0,j=1,n=intervals.size();
        while(i<n && j<n)
        {
            if(intervals[i].end<=intervals[j].start)
            {
                i=j;
                j++;
            }else
            {
                return false;
            }
        }
        return true;
    }
};
