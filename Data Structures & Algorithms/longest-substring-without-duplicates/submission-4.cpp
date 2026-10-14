class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int maxLen=0,i=0,j=0,n=s.size();
        while(j<n)
        {
            mp[s[j]]++;

            while(i<j && mp[s[j]]>1)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};
