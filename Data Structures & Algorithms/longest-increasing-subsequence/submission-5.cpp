class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(ans.empty()) ans.push_back(nums[i]);
            else
            {
                if(ans.back()<nums[i]) ans.push_back(nums[i]);
                else
                {
                    int ind=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                    ans[ind]=nums[i];
                }
            }
        }
        return ans.size();
    }
};
