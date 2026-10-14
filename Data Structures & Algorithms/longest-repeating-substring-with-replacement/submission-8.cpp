class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int i=0,j=0,maxLen=0,n=s.size();
        while(j<n)
        {
            mp[s[j]]++;
            int maxCnt=0;
            for(auto it:mp)
            maxCnt=max(maxCnt,it.second);
            while(mp.size()>1 && (j-i+1-maxCnt)>k)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
                
                for(auto it:mp)
                maxCnt=max(maxCnt,it.second);
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};
