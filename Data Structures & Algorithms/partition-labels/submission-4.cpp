class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]=i;
        }
        int i=0,n=s.size();
        vector<int>v;
        while(i<n)
        {
            int j=i,k=mp[s[i]];
            while(j<k)
            {
                k=max(mp[s[j]],k);
                j++;
            }
            int len=j-i+1;
            v.push_back(len);
            i=j+1;
        }
        return v;
    }
};
