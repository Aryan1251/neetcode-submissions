class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(ans.empty()) ans.push_back(nums[i]);
            else if(nums[i]>ans.back()) ans.push_back(nums[i]);
            else
            {
                int ind=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[ind]=nums[i];
            }
        }
        return ans.size();
    }
};
