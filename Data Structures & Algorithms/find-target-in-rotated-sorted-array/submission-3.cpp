class Solution {
    int BS(vector<int>& nums,int s,int e,int target)
    {
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) s=mid+1;
            else e=mid-1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1) return nums[0]==target?0:-1;
        int s=0,e=n-1;
        int pivotIndex=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(mid+1<n && nums[mid]>nums[mid+1])
            {
                pivotIndex=mid+1;
                break;
            }else if(mid-1>=0 && nums[mid]<nums[mid-1])
            {
                pivotIndex=mid;
                break;
            }else if(nums[0]<nums[mid])
            {
                s=mid+1;
            }else
            e=mid-1;
        }
        if(pivotIndex==-1) return BS(nums,0,n-1,target);
        if(pivotIndex>=1 && target>=nums[0] && target<=nums[pivotIndex-1]) return BS(nums,0,pivotIndex-1,target);
        return BS(nums,pivotIndex,n-1,target);
    }
};
