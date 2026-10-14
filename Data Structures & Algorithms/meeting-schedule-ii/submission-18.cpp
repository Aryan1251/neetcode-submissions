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
        if(intervals.empty()) return 0;
        vector<int>startTime,endTime;
        for(auto it:intervals)
        {
            int st=it.start;
            int en=it.end;
            startTime.push_back(st);
            endTime.push_back(en);
        }
        sort(startTime.begin(),startTime.end());
        sort(endTime.begin(),endTime.end());
        int i=0,j=0,cnt=0,maxCnt=1,n=intervals.size();

        while(i<n && j<n)
        {
            if(startTime[i]<endTime[j])
            {
                cnt++;
                i++;
            }else
            {
                maxCnt=max(maxCnt,cnt);
                cnt--;
                j++;
            }
        }
        maxCnt=max(maxCnt,cnt);
        return maxCnt;
    }
};
