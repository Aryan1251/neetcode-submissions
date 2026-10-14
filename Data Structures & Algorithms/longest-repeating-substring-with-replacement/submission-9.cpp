class Solution {
public:
    int characterReplacement(string s, int k) {
        int arr[26]={0};
        int i=0,j=0,maxFreq=0,maxLen=0,n=s.size();

        while(j<n)
        {
            arr[s[j]-'A']++;
            maxFreq=max(maxFreq,arr[s[j]-'A']);

            while((j-i+1-maxFreq)>k)
            {
                arr[s[i]-'A']--;
                maxFreq=0;
                for(int k=0;k<26;k++)
                maxFreq=max(maxFreq,arr[k]);
                i++;
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};
