class Solution {
    int Solve(vector<int>& nums,int index)
    {
        if(index>=nums.size()-1)
        return 0;

        if(nums[index]==0) return INT_MAX;

        int ans=INT_MAX;
        for(int i=1;i<=nums[index];i++)
        {
           int op=Solve(nums,index+i);
           if(op!=INT_MAX) op+=1;
           ans=min(ans,op);
        }
        return ans;
    }
public:
    int jump(vector<int>& nums) {
        int ans=Solve(nums,0);
        return ans;
    }
};
