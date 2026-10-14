class Solution {
public:
    int characterReplacement(string s, int k) {
        int arr[26]={0};
        int l=0,r=0,n=s.size();
        int maxFreq=0,len=0;
        while(r<n)
        {
            arr[s[r]-'A']++;
            maxFreq=max(maxFreq,arr[s[r]-'A']);
            while(r-l+1-maxFreq>k)
            {
                arr[s[l]-'A']--;
                for(int i=0;i<26;i++)
                maxFreq=max(maxFreq,arr[i]);
                l++;
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};
