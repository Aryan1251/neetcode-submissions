class Solution {
    int BS(vector<int>& nums,int s,int e,int target)
    {
        while(s<=e)
        {
            int mid=(s+e)>>1;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) s=mid+1;
            else e=mid-1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(nums[0]<nums[n-1])
        return BS(nums,0,n-1,target);

        int s=0,e=n-1;
        while(s<e)
        {
            int mid=(s+e)>>1;
            if(nums[0]<=nums[mid]) s=mid+1;
            else e=mid;
        }
        if(target>=nums[0] && target<=nums[s-1]) return BS(nums,0,s-1,target);
        return BS(nums,s,n-1,target);
    }
};
