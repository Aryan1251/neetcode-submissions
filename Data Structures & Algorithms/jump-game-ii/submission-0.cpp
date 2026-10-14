class Solution {
    int solveTab(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1) continue;
            int jumps=INT_MAX;
            for(int j=1;j<=nums[i];j++)
            {
                int op=dp[i+j]; //Solve(nums,i+index);
                if(op!=INT_MAX)
                op+=1;
                jumps=min(jumps,op);
            }
            dp[i]= jumps;
        }
        return dp[0];
    }
public:
    int jump(vector<int>& nums) {
        int ans=solveTab(nums);
        return ans;
    }
};
