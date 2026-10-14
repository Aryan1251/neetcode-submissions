class Solution {
    bool chkSame(int arr1[26],int arr2[26])
    {
        for(int i=0;i<26;i++)
        {
            if(arr1[i]!=arr2[i]) return 0;
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int arr1[26]={0},arr2[26]={0};
        int n=s1.size();
        for(int i=0;i<n;i++)
        {
            int ind=s1[i]-'a';
            arr1[ind]++;
        }
        for(int i=0;i<s2.size() && i<s1.size();i++)
        {
            int ind=s2[i]-'a';
            arr2[ind]++;
        }
        if(chkSame(arr1,arr2)) return 1;
        int j=s1.size(),i=0;
        while(j<s2.size())
        {
            arr2[s2[i]-'a']--;
            i++;
            arr2[s2[j]-'a']++;
            if(chkSame(arr1,arr2)) return 1;
            j++;
        }
        return 0;
    }
};
