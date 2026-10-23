class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<j)
        {
            int val=nums[i]+nums[j];
            if(val==target)
            {
                return {i+1,j+1};
            }else if(val<target)
            i++;
            else 
            j--;
        }
        return {-1,-1};
    }
};
