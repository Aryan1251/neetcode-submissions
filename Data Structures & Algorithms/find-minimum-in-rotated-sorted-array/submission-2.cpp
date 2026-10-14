class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        if(nums[0]<nums[n-1]) return nums[0];

        int s=0,e=n-1;
        while(s<e)
        {
            int mid=(s+e)>>1;
            if(nums[0]<=nums[mid]) s=mid+1;
            else e=mid;
        }
        return nums[s];
    }
};
