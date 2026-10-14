class Solution {
    private:
    void Solve(vector<int>& nums,int index,vector<int> v,set<vector<int> >& ans)
    {
        if(index>=nums.size())
        {
            sort(v.begin(),v.end());
            ans.insert(v);
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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>v;
        set<vector<int> > st;
        vector<vector<int> >ans;
        Solve(nums,0,v,st);
        for(auto it: st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};
