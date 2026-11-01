class Solution {
    void Solve(vector<int>& nums,int ind,vector<vector<int> >& ans,vector<int>arr)
    {
        if(ind>=nums.size()) 
        {
            ans.push_back(arr);
            return ;
        }

        //inlcude
        arr.push_back(nums[ind]);
        Solve(nums,ind+1,ans,arr);

        //exclude
        arr.pop_back();
        Solve(nums,ind+1,ans,arr);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> >ans;
        vector<int>arr;
        Solve(nums,0,ans,arr);
        return ans;
    }
};
