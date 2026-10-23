class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(mp.empty()) mp[nums[i]]=i;
            else
            {
                int val=target-nums[i];
                if(mp.find(val)!=mp.end())
                return {mp[val],i};
                mp[nums[i]]=i;
            }
        }
        return {-1,-1};
    }
};
