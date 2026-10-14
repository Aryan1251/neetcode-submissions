class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int> >freq(n+1);
        unordered_map<int,int>mp;
        vector<int>ans;
        for(auto num: nums)
        {
            mp[num]++;
        }
        for(auto it: mp)
        {
            freq[it.second].push_back(it.first);
        }
        for(int i=n;i>=0;i--)
        {
            for(auto it: freq[i])
            {
                ans.push_back(it);
                if(ans.size()==k) return ans;
            }
        }
        return {};
    }
};
