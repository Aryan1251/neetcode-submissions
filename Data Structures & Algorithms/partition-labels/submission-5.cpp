class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]=i;
        }
        int i=0,n=s.size();
        vector<int>ans;
        while(i<n)
        {
            int maxD=mp[s[i]],j=0;
            while(j<maxD)
            {
                maxD=max(maxD,mp[s[j]]);
                j++;
            }
            ans.push_back(maxD-i+1);
            i=maxD+1;
        }
        return ans;
    }
};
