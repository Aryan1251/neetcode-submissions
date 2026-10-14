class Solution {
    bool isValid(char ch)
    {
        if((ch>='a'&& ch<='z') || (ch>='0' && ch<='9')) return true;
        return false;
    }
public:
    bool isPalindrome(string s) {
        for(auto& ch:s)
        {
            if(ch>='A' && ch<='Z')
            ch=ch+32;
        }
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(isValid(s[i]) && isValid(s[j]))
            {
                if(s[i]==s[j]) 
                {
                    i++;
                    j--;
                }
                else return false;
            }else if(!isValid(s[i])) i++;
            else if(!isValid(s[j])) j--;
        }
        return true;
    }
};
