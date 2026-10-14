class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto stone: stones)
        {
            pq.push(stone);
        }

        while(!pq.empty() && pq.size()>1)
        {
            auto st1=pq.top();
            pq.pop();
            auto st2=pq.top();
            pq.pop();

            if(st1>st2) pq.push(st1-st2);
            else if(st2>st1) pq.push(st2-st1);
        }
        return pq.empty()?0:pq.top();

    }
};
