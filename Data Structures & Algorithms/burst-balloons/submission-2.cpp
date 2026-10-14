class Solution {
    int Solve(vector<int>& nums,int s,int e)
    {
        if(s>e) return 0;

        int ans=0;
        for(int i=s;i<=e;i++)
        {
            ans=max(ans,nums[s-1]*nums[i]*nums[e+1]+Solve(nums,s,i-1)+Solve(nums,i+1,e));
        }
        return ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        int ans=Solve(nums,1,n-2);
        return ans;
    }
};
