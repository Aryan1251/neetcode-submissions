class Solution {
    unordered_map<int,int>rowCheck,upDiag,downDiag;
    bool isPossible(int row,int col,int n)
    {
        if(rowCheck[row]) return false;
        else if(upDiag[n+1+row-col]) return false;
        else if(downDiag[row+col]) return false;
        return true;
    }
    void storeSol(vector<vector<char> >& v,vector<vector<string> >& ans)
    {
        vector<string>s;
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            string str;
            for(int j=0;j<n;j++)
            {
                str+=v[i][j];
            }
            s.push_back(str);
        }
        ans.push_back(s);
        return ;
    }
    void Solve(vector<vector<char> >& v,int col,vector<vector<string> >& ans)
    {
        if(col>=v.size())
        {
            storeSol(v,ans);
            return ;
        }

        int n=v.size();
        for(int row=0;row<v.size();row++)
        {
            if(isPossible(row,col,n))
            {
                v[row][col]='Q';
                rowCheck[row]=1;
                upDiag[n+1+row-col]=1;
                downDiag[row+col]=1;
                Solve(v,col+1,ans);
                v[row][col]='.';
                rowCheck[row]=0;
                upDiag[n+1+row-col]=0;
                downDiag[row+col]=0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> >ans;
        vector<vector<char> >v(n,vector<char>(n,'.'));
        Solve(v,0,ans);
        return ans;
    }
};
