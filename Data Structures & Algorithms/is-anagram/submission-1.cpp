class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26]={0};
        for(auto ch: s)
        {
            int index=ch-'a';
            arr[index]++;
        }
        for(auto ch: t)
        {
            int index=ch-'a';
            arr[index]--;
            if(arr[index]<0) return false;
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]!=0) return false;
        }
        return true;
    }
};
