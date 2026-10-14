class Solution {
    int solveTab(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>dp(n+1,0);
        for(int i=n;i>=0;i--)
        {
            if(i==n) continue;
            
            int op1=nums[i];
            if(i+2<n)
            op1+=dp[i+2]; //Solve(nums,ind+2);

            int op2=0+ dp[i+1]; //Solve(nums,ind+1);

            dp[i]= max(op1,op2);
        }
        return dp[0];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>nums1,nums2;
        for(int i=0;i<nums.size()-1;i++)
        {
            nums1.push_back(nums[i]);
        }
        for(int i=1;i<nums.size();i++)
        {
            nums2.push_back(nums[i]);
        }
        return max(solveTab(nums1),solveTab(nums2));
    }
};
