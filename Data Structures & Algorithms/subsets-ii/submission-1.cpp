class Solution {
    void Solve(vector<int>& nums,int index,set<vector<int> >& st,vector<int>& v)
    {
        if(index>=nums.size())
        {
            st.insert(v);
            return ;
        }

        //include
        v.push_back(nums[index]);
        Solve(nums,index+1,st,v);

        //exclude
        v.pop_back();
        Solve(nums,index+1,st,v);

        return ;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> >ans;
        vector<int>v;
        sort(nums.begin(),nums.end());
        set<vector<int> >st;
        Solve(nums,0,st,v);
        ans.insert(ans.begin(),st.begin(),st.end());
        return ans;
    }
};
