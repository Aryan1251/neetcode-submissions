class Solution {
    void Solve(vector<int>& nums,int index,vector<vector<int> >& ans,vector<int>& v)
    {
        if(index>=nums.size())
        {
            ans.push_back(v);
            return ;
        }

        //include
        v.push_back(nums[index]);
        Solve(nums,index+1,ans,v);

        //exclude
        v.pop_back();
        Solve(nums,index+1,ans,v);

        return ;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> >ans;
        vector<int>v;
        Solve(nums,0,ans,v);
        return ans;
    }
};
