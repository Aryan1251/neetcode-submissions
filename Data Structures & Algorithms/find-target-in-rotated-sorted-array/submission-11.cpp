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
        int s=0,e=n-1,pivotIndex=-1;
        if(nums[0]<nums[n-1]) return Bs(nums,target,0,n-1);

        while(s<=e)
        {
            int mid=(s+e)>>1;

            if(mid-1>=0 && nums[mid]<nums[mid-1])
            {
                pivotIndex=mid;
                break;
            }
            else if(mid+1<n && nums[mid]>nums[mid+1])
            {
                pivotIndex=mid+1;
                break;
            }
            else if(nums[mid]>nums[0]) s=mid+1;
            else
            {
                pivotIndex=mid;
                e=mid-1;
            }
        }
        if(pivotIndex>=1 && target>=nums[0] && target<=nums[pivotIndex-1]) return Bs(nums,target,0,pivotIndex-1);

        return Bs(nums,target,pivotIndex,n-1);
    }
};
