class Solution {
    void Solve(vector<int>& nums,int index,vector<vector<int> >& ans)
    {
        if(index>=nums.size())
        {
            ans.push_back(nums);
            return ;
        }
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[i],nums[index]);
            Solve(nums,index+1,ans);
            swap(nums[i],nums[index]);
        }
        return ;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> >ans;
        Solve(nums,0,ans);
        return ans;
    }
};
