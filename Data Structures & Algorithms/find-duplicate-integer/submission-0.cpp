class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int neg_no=abs(nums[i]);
            if(nums[neg_no]<0) return abs(nums[i]);
            nums[neg_no]=-1*nums[neg_no];
        }
        return -1;
    }
};
