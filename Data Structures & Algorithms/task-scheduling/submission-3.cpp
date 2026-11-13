class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char> >pq;
        unordered_map<int,int>mp;

        for(auto task:tasks)
        {
            mp[task]++;
        }
        for(auto it: mp)
        {
            pq.push({it.second,it.first});
        }
        int cycle=0;
        vector<pair<int,int> >ans;
        while(!pq.empty())
        {
            char ch=pq.top().second;
            int cnt=pq.top().first;
            pq.pop();

            cycle+=1;
            cnt-=1;
            int i=0;
            for(i=0;i<n && !pq.empty();i++)
            {
                ans.push_back({pq.top().second,pq.top().first});
                pq.pop();
                cycle++;
            }
            if(i<n && cnt>0)
            {
                cycle+=(n-i);
            }

            for(auto it: ans)
            {
                if(it.second-1>0) pq.push({it.second-1,it.first});
            }

            if(cnt>0)
            pq.push({cnt,ch});
            
            ans.clear();
        }
        return cycle;
    }
};
