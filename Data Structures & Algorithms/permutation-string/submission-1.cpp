class Solution {
    bool chk(int arr[26],int brr[26])
    {
        for(int i=0;i<26;i++)
        {
            if(arr[i]!=brr[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int arr[26]={0};
        int brr[26]={0};
        int n=s1.size();
        for(int i=0;i<n;i++)
        {
            arr[s1[i]-'a']++;
        }
        for(int i=0;i<n && i<s2.size();i++)
        {
            brr[s2[i]-'a']++;
        }
        if(chk(arr,brr)) return true;
        int i=n;
        while(i<s2.size())
        {
            char ch=s2[i-n];
            brr[ch-'a']--;
            brr[s2[i]-'a']++;
            if(chk(arr,brr)) return true;
            i++;
        }
        return false;
    }
};
