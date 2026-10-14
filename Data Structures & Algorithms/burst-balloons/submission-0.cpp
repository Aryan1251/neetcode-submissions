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
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        int n=nums.size();
        vector<vector<int> >dp(n+1,vector<int>(n+1,-1)); 
        int ans=Solve(nums,1,n-2,dp);
        return ans;
    }
};
