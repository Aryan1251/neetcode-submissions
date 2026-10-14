class Solution {
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
            char ch=s[i];
            int index=mp[ch];
            int maxIndex=index;
            int j=i;
            while(j<=maxIndex)
            {
                maxIndex=max(maxIndex,mp[s[j]]);
                j++;
            }
            // for(int j=i;j<=maxIndex;j++)
            // {
            //     maxIndex=max(maxIndex,mp[s[j]]);
            // }
            ans.push_back(maxIndex-i+1);
            i=maxIndex+1;
        }
        return ans;
    }
};
