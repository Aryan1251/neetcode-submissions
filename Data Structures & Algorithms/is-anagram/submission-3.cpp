class Solution {
    bool Solve(string s,string t)
    {
        int arr[26]={0};
        for(int i=0;i<s.size();i++)
        {
            int ind=s[i]-'a';
            arr[ind]++;
        }

        for(int i=0;i<t.size();i++)
        {
            int ind=t[i]-'a';
            arr[ind]--;
        }

        for(int i=0;i<26;i++)
        {
            if(arr[i]!=0) return false;
        }
        return true;
    }
public:
    bool isAnagram(string s, string t) {
        return Solve(s,t);
    }
};
