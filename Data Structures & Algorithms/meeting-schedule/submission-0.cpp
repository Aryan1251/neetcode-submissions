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
    bool static myComp(Interval &a,Interval& b)
    {
        return a.start<b.start;
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size()==0 || intervals.size()==1) return 1;
        sort(intervals.begin(),intervals.end(),myComp);
        int i=0,j=1,n=intervals.size();
        while(j<n)
        {
            if(intervals[i].end>intervals[j].start) return false;
            else
            {
                i++;
                j++;
            }
        }
        return true;
    }
};
