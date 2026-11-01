class Solution {
    void Solve(vector<int>& nums,vector<int>& arr,vector<vector<int> >& ans,int ind,int target)
    {
        //base case
        if(target==0)
        {
            ans.push_back(arr);
            return ;
        }
        if(ind>=nums.size()) return ;

        if(nums[ind]<=target)
        {
            arr.push_back(nums[ind]);
            Solve(nums,arr,ans,ind,target-nums[ind]);
            arr.pop_back();
        }

        Solve(nums,arr,ans,ind+1,target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int> >ans;
        vector<int>arr;
        Solve(nums,arr,ans,0,target);
        return ans;
    }
};
