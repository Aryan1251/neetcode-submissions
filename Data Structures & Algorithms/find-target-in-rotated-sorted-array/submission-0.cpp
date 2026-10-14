class Solution {
    int BS(vector<int>& nums,int s,int e,int target)
    {
        while(s<=e)
        {
            int mid=(s+e)>>1;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) e=mid-1;
            else s=mid+1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivotIndex=-1;
        int s=0,e=n-1;
        while(s<e)
        {
            int mid=(s+e)>>1;
            if(nums[mid]>nums[mid+1])
            {
                pivotIndex=mid+1;
                break;
            }else if(nums[mid]<nums[mid-1])
            {
                pivotIndex=mid;
                break;
            }
            if(nums[mid]>nums[0])
            {
                s=mid+1;
            }else
            e=mid-1;
        }
        if(pivotIndex==-1)
        {
            if(s==n-1 && e==n-1) pivotIndex=0;
            else pivotIndex=s;
        }
        cout<<pivotIndex<<" ";
        if(pivotIndex-1>=0 && target>=nums[0] && target<=nums[pivotIndex-1]) return BS(nums,0,pivotIndex-1,target);
        return BS(nums,pivotIndex,n-1,target);
    }
};
