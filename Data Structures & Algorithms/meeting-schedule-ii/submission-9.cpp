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
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n=intervals.size();
        vector<int>startTime,endTime;
        for(auto it: intervals)
        {
            int st=it.start;
            int end=it.end;
            startTime.push_back(st);
            endTime.push_back(end);
        }
        sort(startTime.begin(),startTime.end());
        sort(endTime.begin(),endTime.end());
        int i=0,j=0,days=0,maxDays=0;
        while(i<n && j<n)
        {
            if(endTime[j]>startTime[i])
            {
                days++;
                maxDays=max(maxDays,days);
                i++;
            }else
            {
                days--;
                j++;
            }
        }
        return maxDays;
    }
};
