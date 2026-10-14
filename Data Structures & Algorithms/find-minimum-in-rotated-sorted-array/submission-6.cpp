class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        int s=0,e=n-1,ans=-1;
        if(nums[0]<nums[n-1]) return nums[0];

        while(s<=e)
        {
            int mid=(s+e)>>1;

            if(mid-1>=0 && nums[mid]<nums[mid-1]) return nums[mid];
            else if(mid+1<n && nums[mid]>nums[mid+1]) return nums[mid+1];
            else if(nums[mid]>nums[0]) s=mid+1;
            else
            {
                ans=mid;
                e=mid-1;
            }
        }
        return nums[ans];
    }
};
