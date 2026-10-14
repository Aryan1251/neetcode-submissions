class Solution {
    private:
    int solveTab(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>dp(n+1,0);
        for(int i=n;i>=0;i--)
        {
            if(i==n) continue;
            int op1=dp[i+1]; //Solve(nums,index+1);

            int op2=nums[i];
            if(i+2<n+1)
            op2+=dp[i+2]; //Solve(nums,index+2);
    
            dp[i]= max(op1,op2);
        }
        return dp[0];
    }
public:
    int rob(vector<int>& nums) {
        int ans=solveTab(nums);
        return ans;
    }
};
