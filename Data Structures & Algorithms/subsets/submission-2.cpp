class Solution {
    void Solve(vector<vector<int> >& ans,vector<int>& nums,vector<int>v,int index)
    {
        if(index>=nums.size())
        {
            ans.push_back(v);
            return ;
        }

        //include
        v.push_back(nums[index]);
        Solve(ans,nums,v,index+1);

        //exclude
        v.pop_back();
        Solve(ans,nums,v,index+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> >ans;
        vector<int>v;
        Solve(ans,nums,v,0);
        return ans;
    }
};
