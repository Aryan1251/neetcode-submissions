class Solution {
    // wrong ans 
    //because logic wrong h
    //qiejxqfnqceocmy
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]=i;
        }
        int i=0;
        vector<int>ans;
        while(i<s.size())
        {
            int maxIndex=mp[s[i]];
            int j=i;
            while(j<s.size() && j<=maxIndex)
            {
                maxIndex=max(maxIndex,mp[s[j]]);
                j++;
            }
            int len=maxIndex-i+1;
            i=maxIndex+1;
            ans.push_back(len);
        }
        return ans;
    }
};

