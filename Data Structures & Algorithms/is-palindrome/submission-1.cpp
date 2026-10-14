class Solution {
    private:
    bool isNum(char ch)
    {
        if(ch>='0' && ch<='9') return true;
        return false; 
    }
public:
    bool isPalindrome(string s) {
        for(auto &ch: s)
        {
            if(ch>='A' && ch<='Z')
            ch=ch+32;
        }
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(!isalpha(s[i]) && !isNum(s[i]))
            i++;
            else if(!isalpha(s[j]) && !isNum(s[j]))
            j--;
            else
            {
                if(s[i]==s[j])
                {
                    i++;
                    j--;
                }
                else return false;
            }
        }
        return true;
    }
};
