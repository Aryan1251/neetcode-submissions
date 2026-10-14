class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int ind=abs(nums[i]);
            if(nums[ind]<0) return ind;
            nums[ind]=-1*nums[ind];
        }
        return -1;
    }
};
