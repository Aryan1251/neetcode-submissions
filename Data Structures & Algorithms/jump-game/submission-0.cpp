class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int maxIndex=0,n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            maxIndex=max(maxIndex,i+nums[i]);
            if(nums[i]==0) 
            {
                if(maxIndex<=i) return false;
            }
        }
        return true;
    }
};
