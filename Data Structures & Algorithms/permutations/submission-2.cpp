class Solution {
    void Solve(vector<int>nums,vector<vector<int> >& ans,int index)
    {
        if(index>=nums.size())
        {
            ans.push_back(nums);
            return ;
        }
        int n=nums.size();
        for(int i=index;i<n;i++)
        {
            swap(nums[i],nums[index]);
            Solve(nums,ans,index+1);
            swap(nums[i],nums[index]);
        }
        return ;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> >ans;
        Solve(nums,ans,0);
        return ans;
    }
};
