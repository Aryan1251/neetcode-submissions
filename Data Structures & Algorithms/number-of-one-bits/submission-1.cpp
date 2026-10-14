class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n)
        {
            int last_bit=n&1;
            if(last_bit) cnt++;
            n=n>>1;
        }
        return cnt;
    }
};
