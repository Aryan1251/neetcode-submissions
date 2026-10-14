class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int> >ans;
        for(int i=0;i<n;i++)
        {
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int st=i+1;
            int end=n-1;
            while(st<end && st<n && end<n)
            {
                int sum=nums[i]+nums[st]+nums[end];
                if(st-1>=0 && end+1<n && nums[st]==nums[st-1] && nums[end]==nums[end+1])
                {
                    st++;
                    end--;
                }
                else if(sum==0)
                {
                    ans.push_back({nums[i],nums[st],nums[end]});
                    st++;
                    end--;
                }
                else if(sum>0) end--;
                else st++;
            }
        }
        return ans;
    }
};
