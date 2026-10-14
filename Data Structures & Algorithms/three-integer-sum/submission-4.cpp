class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int> >st;
        vector<vector<int> >ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int j=i+1;
            int k=n-1;
            while(j<n && j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0)
                {
                    st.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }else if(sum>0) k--;
                else j++;
            }
        }
        ans.insert(ans.begin(),st.begin(),st.end());
        return ans;
    }
};
