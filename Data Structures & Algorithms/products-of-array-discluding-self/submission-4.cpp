class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n+1,1),right(n+1,1);
        vector<int>ans;
        left[1]=nums[0];
        for(int i=2;i<n;i++)
        {
            left[i]=left[i-1]*nums[i-1];
        }
        right[n-2]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i]=right[i+1]*nums[i+1];
        }

        for(int i=0;i<n;i++)
        {
            int vals=left[i]*right[i];
            ans.push_back(vals);
        }
        return ans;
    }
};
