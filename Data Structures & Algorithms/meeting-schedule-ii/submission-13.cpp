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
        vector<int>stTime(n),endTime(n);
        for(int i=0;i<n;i++)
        {
            stTime[i]=intervals[i].start;
            endTime[i]=intervals[i].end;
        }
        sort(stTime.begin(),stTime.end());
        sort(endTime.begin(),endTime.end());
        int i=0,j=0,cnt=0,maxCnt=INT_MIN;
        while(i<n && j<n)
        {
            if(stTime[i]<endTime[j])
            {
                cnt++;
                cout<<cnt<<" "<<endl;
                maxCnt=max(maxCnt,cnt);
                i++;
            }else
            {
                cnt--;
                j++;
            }
        }
        return maxCnt==INT_MIN?0:maxCnt;
    }
};
