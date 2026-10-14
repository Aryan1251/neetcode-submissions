class Solution {
    bool chk_valid(int arr1[],int arr2[])
    {
        for(int i=0;i<26;i++)
        {
            if(arr1[i]!=arr2[i]) return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int arr1[26]={0},arr2[26]={0};
        for(auto ch:s1)
        {
            int index=ch-'a';
            arr1[index]++;
        }
        for(int i=0;i<s1.size() && i<s2.size();i++)
        {
            int index=s2[i]-'a';
            arr2[index]++;
        }
        if(chk_valid(arr1,arr2)) return true;
        int window_size=s1.size();

        for(int i=window_size;i<s2.size();i++)
        {
            //remove previous index mark
            int prev_index=s2[i-window_size]-'a';
            arr2[prev_index]--;

            //mark new_index
            arr2[s2[i]-'a']++;

            if(chk_valid(arr1,arr2)) return true;
        }
        return false;
    }
};
