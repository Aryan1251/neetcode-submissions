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
        if(intervals.size()==0) return 0;
        vector<int>startTime;
        vector<int>endTime;
        int n=intervals.size();
        for(auto it: intervals)
        {
            int st=it.start;
            int endT=it.end;
            startTime.push_back(st);
            endTime.push_back(endT);
        }
        sort(startTime.begin(),startTime.end());
        sort(endTime.begin(),endTime.end());
        int i=0,j=0,maxCnt=0,cnt=0;
        while(i<n && j<n)
        {
            if(startTime[i]<endTime[j])
            {
                cnt++;
                maxCnt=max(maxCnt,cnt);
                i++;
            }else
            {
                cnt--;
                maxCnt=max(maxCnt,cnt);
                j++;
            }
        }
        maxCnt=max(maxCnt,cnt);
        return maxCnt;
    }
};
