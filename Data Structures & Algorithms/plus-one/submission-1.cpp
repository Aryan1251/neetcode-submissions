class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans;
        int n=digits.size();
        int i=n-1,carry=1;
        while(i>=0)
        {
            int sum=carry+digits[i];
            carry=sum/10;
            int val=sum%10;
            ans.push_back(val);
            i--;
        }
        while(carry)
        {
            ans.push_back(carry%10);
            carry/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
