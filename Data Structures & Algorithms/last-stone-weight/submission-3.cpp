class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int n=stones.size();
        for(int i=0;i<n;i++)
        {
            pq.push(stones[i]);
        }

        while(!pq.empty() && pq.size()>1)
        {
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();

            if(a==b) continue;
            else if(a>b)
            {
                a-=b;
                pq.push(a);
            }
            else
            {
                b-=a;
                pq.push(b);
            }
        }
        return pq.empty()?0:pq.top();
    }
};
