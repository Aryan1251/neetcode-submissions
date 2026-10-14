class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(v.empty()) v.push_back(nums[i]);
            else if(v.back()<nums[i]) v.push_back(nums[i]);
            else
            {
                auto ind=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
                v[ind]=nums[i];
            }
        }
        return v.size();
    }
};
