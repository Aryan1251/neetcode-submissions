class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,pair<int,int> > ,vector<pair<float,pair<int,int> >>,greater<pair<float,pair<int,int> >> >pq;
        for(auto it: points)
        {
            int x=it[0];
            int y=it[1];
            pq.push({(float)(sqrt(x*x + y*y)),{x,y}});
        }
        vector<vector<int> >ans;
        while(!pq.empty() && k--)
        {
            vector<int>v;
            v.push_back(pq.top().second.first);
            v.push_back(pq.top().second.second);
            ans.push_back(v);
            pq.pop();
        }
        return ans;
    }
};
