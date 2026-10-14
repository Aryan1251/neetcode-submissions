class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it: nums)
        {
            if(mp[it]==1) return 1;
            mp[it]=1;
        }
        return 0;
    }
};