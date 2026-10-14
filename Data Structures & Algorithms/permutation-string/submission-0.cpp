class Solution {
    private:
    bool chkValid(int arr1[],int arr2[])
    {
        for(int i=0;i<26;i++)
        {
            if(arr1[i]!=arr2[i]) return 0;
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int arr1[26]={0};
        for(int i=0;i<s1.size();i++)
        {
            int index=s1[i]-'a';
            arr1[index]++;
        }
        int arr2[26]={0};
        for(int i=0;i<s1.size() && i<s2.size();i++)
        {
            int index=s2[i]-'a';
            arr2[index]++;
        }
        if(chkValid(arr1,arr2)) return true;
        for(int i=s1.size();i<s2.size();i++)
        {
            int index=s2[i-s1.size()]-'a';
            arr2[index]--;
            int newIndex=s2[i]-'a';
            arr2[newIndex]++;
            if(chkValid(arr1,arr2)) return true;
        }
        return false;
    }
};
