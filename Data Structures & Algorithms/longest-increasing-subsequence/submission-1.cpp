class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n,1);
        for(int i=1;i<n;i++)
        {
            int maxi=0;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]<nums[i])
                {
                    maxi=max(arr[j],maxi);
                }
            }
            arr[i]=maxi+1;
        }
        // for(int i=0;i<n;i++)
        // cout<<arr[i]<<" ";
        // cout<<endl;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }
};
