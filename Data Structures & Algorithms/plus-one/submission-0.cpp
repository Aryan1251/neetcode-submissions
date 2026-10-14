class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1,n=digits.size();
        vector<int>v;
        int index=n;
        for(int i=n-1;i>=0;i--)
        {
            int sum=digits[i]+carry;
            carry=sum/10;
            sum=sum%10;
            v.push_back(sum);
        }
        if(carry)
        {
            v.push_back(carry);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
