class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int i=0,j=0,maxLen=0,maxFreq=0,n=s.size();
        while(j<n)
        {
            mp[s[j]]++;
            if(mp.size()>1)
            {
                for(auto it: mp)
                maxFreq=max(maxFreq,it.second);
                
                while(i<j && (j-i+1)-maxFreq>k)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                    for(auto it: mp)
                    maxFreq=max(maxFreq,it.second);
                }
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};
