class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto num: nums)
        {
            mp[num]++;
        }
        vector<vector<int> >v(n+1);
        for(auto it: mp)
        {
            v[it.second].push_back(it.first);
        }
        vector<int>ans;
        for(int i=n;i>=0;i--)
        {
            for(auto it: v[i])
            {
                ans.push_back(it);
                if(ans.size()==k)return ans;
            }
        }
        return {};
    }
};
