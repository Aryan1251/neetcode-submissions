class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int> >ans;
        for(int i=0;i<n-1;i++)
        {
            int s=i+1,e=n-1;
            if(i!=0 && nums[i]==nums[i-1]) continue;
            while(s<e)
            {
                int val=nums[i]+nums[s]+nums[e];
                if(s-1>i && nums[s]==nums[s-1] && nums[e]==nums[e+1] && e+1<n)
                {
                    s++;
                    e--;
                    continue;
                }
                if(val>0) e--;
                else if(val<0) s++;
                else
                {
                    ans.push_back({nums[i],nums[s],nums[e]});
                    s++;
                    e--;
                }
            }
        }
        return ans;
    }
};
