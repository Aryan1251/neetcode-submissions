class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            mp[s[i]]=i;
        }
        vector<int>ans;
        int i=0,j=0,maxInd=0;
        while(j<n)
        {
            maxInd=max(maxInd,mp[s[j]]);
            if(j==maxInd)
            {
                int len=j-i+1;
                ans.push_back(len);
                i=j+1;
                j++;
            }else
            {
                j++;
            }
        }
        return ans;
    }
};
