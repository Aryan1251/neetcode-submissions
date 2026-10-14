class Solution {
    void Solve(vector<int>& nums,vector<vector<int> >& ans,int index)
    {
        if(index>=nums.size())
        {
            ans.push_back(nums);
            return ;
        }

        for(int i=index;i<nums.size();i++)
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
