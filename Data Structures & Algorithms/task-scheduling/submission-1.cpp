class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char> >pq;
        unordered_map<char,int >mp;
        for(auto ch: tasks)
        {
            mp[ch]++;
        }
        for(auto it: mp)
        {
            pq.push({it.second,it.first});
        }
        int cycle=0;
        while(!pq.empty())
        {
            auto ch=pq.top().second;
            int cnt=pq.top().first;
            int rest=n;
            pq.pop();
            if(cnt<=1)
            {
                cycle++;
                continue;
            }
            vector<pair<char,int> >vp;
            cycle++;
            while(!pq.empty() && rest)
            {
                char ch2=pq.top().second;
                int chCnt=pq.top().first;

                pq.pop();
                if(chCnt<=1)
                cycle++;
                else
                {
                    cycle++;
                    vp.push_back({ch2,chCnt-1});
                }
                rest--;
            }
            if(rest!=0) cycle+=rest;
            if(cnt>1)
            {
                pq.push({cnt-1,ch});
            }
            for(auto it: vp)
            {
                pq.push({it.second,it.first});
            }
        }
        return cycle;
    }
};
