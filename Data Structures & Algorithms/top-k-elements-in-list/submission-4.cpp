class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>arr;
        for(int i=0;i<n;i++)
        {
            arr[nums[i]]++;
        }
        unordered_map<int,vector<int> >mp;
        for(auto it: arr)
        {
            mp[it.second].push_back(it.first);
        }
        int maxFreq=n;
        vector<int>ans;
        for(int i=maxFreq;i>=0;i--)
        {
            if(mp.find(i)!=mp.end())
            {
                for(auto it: mp[i])
                {
                    ans.push_back(it);
                    if(ans.size()==k) return ans;
                }
            }
        }
        return {};
    }
};
