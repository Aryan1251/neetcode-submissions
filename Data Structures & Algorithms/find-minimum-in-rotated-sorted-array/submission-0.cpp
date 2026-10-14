class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int s=0,e=nums.size()-1;
        while(s<e)
        {
            int mid=(s+e)>>1;
            if(mid-1>=0 && nums[mid]<nums[mid-1])
            {
                return nums[mid];
            }
            else if(mid+1<n && nums[mid]>nums[mid+1])
            {
                return nums[mid+1];
            }
            if(nums[mid]>nums[0])
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        if(s==n-1 && e==n-1) return nums[0];
        return nums[s];
    }
};
