class Solution {
    private:
    void Solve(vector<int>& nums,int index,vector<int>& v,vector<vector<int> >& ans)
    {
        if(index>=nums.size())
        {
            ans.push_back(v);
            return ;
        }

        //include
        v.push_back(nums[index]);
        Solve(nums,index+1,v,ans);

        //exclude
        v.pop_back();
        Solve(nums,index+1,v,ans);
        return ;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        vector<vector<int> >ans;
        Solve(nums,0,v,ans);
        return ans;
    }
};
