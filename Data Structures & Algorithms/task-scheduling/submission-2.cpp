class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        unordered_map<char,int>mp;
        for(auto it: tasks)
        {
            mp[it]++;
        }
        for(auto it: mp)
        {
            pq.push(it.second);
        }
        int cycle=0;
        while(!pq.empty())
        {
            int cnt=pq.top();
            vector<int>v;
            pq.pop();
            cycle++;
            cnt--;
            if(cnt!=0) v.push_back(cnt);
            int coolTime=n;
            while(!pq.empty() && coolTime--)
            {
                int currCnt=pq.top();
                pq.pop();
                currCnt--;
                cycle++;
                if(currCnt!=0) v.push_back(currCnt);
            }
            if(coolTime>0)
            {
                if(!v.empty()) cycle+=coolTime; 
            }
            for(auto it: v)
            {
                pq.push(it);
            }
        }
        return cycle;
    }
};
