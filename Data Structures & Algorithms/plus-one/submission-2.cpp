class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=1;
        vector<int>v;
        for(int i=n-1;i>=0;i--)
        {
            int val=carry+digits[i];
            int value=val%10;
            carry=val/10;
            v.push_back(value);
        }
        while(carry)
        {
            v.push_back(carry);
            carry/=10;
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
