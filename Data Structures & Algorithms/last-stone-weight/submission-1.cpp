class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto &stone: stones)
        {
            pq.push(stone);
        }
        while(!pq.empty() && pq.size()>1)
        {
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            //cout<<a<<" "<<b<<endl;
            if(a==b) continue;
            else if(a<b) pq.push(b-a);
            else if(a>b) pq.push(a-b);
            cout<<pq.size()<<" ";
        }
        return pq.empty()?0:pq.top();
    }
};
