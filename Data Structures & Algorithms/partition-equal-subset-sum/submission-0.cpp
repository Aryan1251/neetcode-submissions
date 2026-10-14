class Solution {
    bool Solve(vector<int>& nums,int ind,int target)
    {
        if(target==0) return 1;
        if(ind>=nums.size()) return 0;

        bool op1=false;
        if(nums[ind]<=target)
        op1=Solve(nums,ind+1,target-nums[ind]);

        bool op2=Solve(nums,ind+1,target);

        return op1||op2;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum&1) return 0;
        
        int target=sum/2;
        bool ans=Solve(nums,0,target);
        return ans;
    }
};
