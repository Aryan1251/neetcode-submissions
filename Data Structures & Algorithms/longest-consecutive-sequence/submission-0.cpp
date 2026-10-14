class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>arr(n,1);
        for(int i=0;i<n;i++)
        {
            int maxi=1;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]==nums[i]-1)
                {
                    maxi=max(maxi,arr[j]+1);
                }
            }
            arr[i]=maxi;
        }
        int len=0;
        for(int i=0;i<n;i++)
        {
            len=max(len,arr[i]);
        }
        return len;
    }
};
