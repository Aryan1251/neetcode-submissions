class Solution {
    int Solve(vector<int>& nums,vector<int>& dp,int ind)
    {
        //base case
        if(ind>=nums.size())
        {
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];

        int op1=nums[ind]+Solve(nums,dp,ind+2);
        int op2=0+Solve(nums,dp,ind+1);

        return dp[ind]=max(op1,op2);
    }

    int solveTab(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        dp[n]=0;
        for(int i=n;i>=0;i--)
        {
            if(i==n) continue;

            int op1=nums[i];
            if(i+2<n+1)
            op1+=dp[i+2]; //Solve(nums,dp,ind+2);

            int op2=dp[i+1]; //Solve(nums,dp,ind+1);
            dp[i]=max(op1,op2);
        }
        return dp[0];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==0) return 0;
        vector<int>num1;
        for(int i=0;i<n-1;i++)
        {
            num1.push_back(nums[i]);
        }

        vector<int>num2;
        for(int i=1;i<n;i++)
        {
            num2.push_back(nums[i]);
        }

        int ans1=solveTab(num1);
        int ans2=solveTab(num2);

        return max(ans1,ans2);
    }
};
