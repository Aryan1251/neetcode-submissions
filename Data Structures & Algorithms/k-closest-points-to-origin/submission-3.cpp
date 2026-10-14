class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,pair<int,int>>,vector<pair<float,pair<int,int>>>,greater<pair<float,pair<int,int>>> >pq;
        vector<vector<int> >ans;
        for(auto& it: points)
        {
            int x=it[0];
            int y=it[1];
            float dis=(float)sqrt(x*x + y*y);
            pq.push({dis,{x,y}});
        }
        int cnt=k;
        while(!pq.empty() && cnt--)
        {
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            ans.push_back({x,y});
        }
        return ans;
        
    }
};
