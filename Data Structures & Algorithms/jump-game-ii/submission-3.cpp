class Solution {
    int Solve(vector<int>& nums,int index)
    {
        if(index>=nums.size()-1) return 0;

        int ans=INT_MAX;
        for(int i=1;i<=nums[index];i++)
        {
            int op1=Solve(nums,i+index);
            if(op1!=INT_MAX) op1+=1;
            ans=min(ans,op1);
        }
        return ans;
    }
public:
    int jump(vector<int>& nums) {
        return Solve(nums,0);
    }
};
