class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,pair<int,int>>,vector<pair<float,pair<int,int>>>,greater<pair<float,pair<int,int>>> >pq;
        vector<vector<int> >ans; 
        for(auto it: points)
        {
            int p1=it[0];
            int p2=it[1];
            float dis=(float)sqrt(p1*p1 + p2*p2);
            pq.push({dis,{p1,p2}});
        }
        while(!pq.empty() && k--)
        {
            int p1=pq.top().second.first;
            int p2=pq.top().second.second;
            pq.pop();
            ans.push_back({p1,p2});
        }
        return ans;
    }
};
