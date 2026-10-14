class Solution {
    int Bs(vector<int>& nums,int target,int s,int e)
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
        if(nums[0]<nums[n-1]) Bs(nums,target,0,n-1);
        int s=0,e=n-1;
        while(s<e)
        {
            int mid=(s+e)>>1;
            if(nums[0]<=nums[mid]) s=mid+1;
            else e=mid;
        }
        if(target>=nums[0] && target<=nums[s-1]) return Bs(nums,target,0,s-1);
        else if(target>=nums[s] && target<=nums[n-1]) return Bs(nums,target,s,n-1);
        return -1;
    }
};
