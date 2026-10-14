class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        if(n==1) return n;
        int len=0;
        int arr[26]={0};
        int l=0,r=0,maxFreq=INT_MIN;
        while(r<n)
        {
            arr[s[r]-'A']++;
            maxFreq=max(maxFreq,arr[s[r]-'A']);
            while((r-l+1)-maxFreq>k)
            {
                arr[s[l]-'A']--;
                l++;
                for(int i=0;i<26;i++)
                maxFreq=max(maxFreq,arr[i]);
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};
