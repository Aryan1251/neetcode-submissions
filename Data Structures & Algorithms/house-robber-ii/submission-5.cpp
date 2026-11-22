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
        
        vector<int>dp(n+1,-1);
        int ans1=Solve(num1,dp,0);
        dp.clear();
        for(int i=0;i<n+1;i++) dp[i]=-1;
        int ans2=Solve(num2,dp,0);

        return max(ans1,ans2);
    }
};
