class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(auto num: nums)
        {
            mp[num]++;
        }
        priority_queue<pair<int,int> >pq;
        for(auto it: mp)
        {
            pq.push({it.second,it.first});
        }

        while(!pq.empty() && k--)
        {
            int freq=pq.top().first;
            int element=pq.top().second;

            pq.pop();
            ans.push_back(element);
        }
        return ans;
    }
};
