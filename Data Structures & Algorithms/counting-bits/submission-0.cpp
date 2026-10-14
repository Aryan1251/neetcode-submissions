class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            int cnt=0,num=i;
            while(num)
            {
                int bit=num&1;
                if(bit) cnt++;
                num=num>>1;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
