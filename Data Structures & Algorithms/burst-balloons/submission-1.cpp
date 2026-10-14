class Solution {
    private:
    int Solve(vector<int>& nums,int s,int e,vector<vector<int> >& dp)
    {
        if(s>e) return 0;
        if(dp[s][e]!=-1) return dp[s][e];

        int ans=INT_MIN;
        for(int i=s;i<=e;i++)
        {
            ans=max(ans,nums[s-1]*nums[i]*nums[e+1]+Solve(nums,s,i-1,dp)+Solve(nums,i+1,e,dp));
        }
        return dp[s][e]=ans;
    }
    int solveTab(vector<int>& nums)
    {
        int n=nums.size();
        vector<vector<int> >dp(n+1,vector<int>(n+1,0)); 
        for(int i=n-2;i>=1;i--)
        {
            for(int j=0;j<=n-2;j++)
            {
                if(i>j) continue;
                int ans=INT_MIN;
                for(int k=i;k<=j;k++)
                {
                    ans=max(ans,nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j]); //Solve(nums,k+1,e,dp));
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][n-2];
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        int ans=solveTab(nums);
        return ans;
    }
};
