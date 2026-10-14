class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr;
        for(int i=0;i<n;i++)
        {
            if(arr.empty()) arr.push_back(nums[i]);
            else if(nums[i]>arr.back()) arr.push_back(nums[i]);
            else
            {
                auto index=lower_bound(arr.begin(),arr.end(),nums[i])-arr.begin();
                arr[index]=nums[i];
            }
        }
        return arr.size();
    }
};
