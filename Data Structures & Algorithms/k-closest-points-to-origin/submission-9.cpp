class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,pair<int,int>>,vector<pair<float,pair<int,int> >>,greater<pair<float,pair<int,int> > >>pq;

        vector<vector<int> >ans;
        for(auto &point: points)
        {
            int x=point[0];
            int y=point[1];
            float dis=sqrt((x*x) + (y*y));
            pq.push({dis,{x,y}});
        }
        // while(!pq.empty())
        // {
        //     cout<<pq.top().first<<endl;
        //     pq.pop();
        // }

        while(!pq.empty() && k--)
        {
            auto p=pq.top();
            pq.pop();
            auto coordinates=p.second;
            ans.push_back({coordinates.first,coordinates.second});
        }
        return ans;
    }
};
