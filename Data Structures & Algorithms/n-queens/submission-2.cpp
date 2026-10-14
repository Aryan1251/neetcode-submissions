class Solution {
    unordered_map<int,int>rowChk,upperChk,lowerChk;
    bool isValid(int i,int j,vector<vector<char> >& grid,int n)
    {
        if(rowChk[i]==1) return false;
        if(upperChk[n+(i-j)]==1) return false;
        if(lowerChk[i+j]==1) return false;
        return true;
    }
    void storeAns(vector<vector<string> >& ans,vector<vector<char> >& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<string>v;
        for(int i=0;i<n;i++)
        {
            string str;
            for(int j=0;j<m;j++)
            {
                str+=grid[i][j];
            }
            v.push_back(str);
        }
        ans.push_back(v);
        return ;
    }
    void Solve(vector<vector<char> >& grid,int col,vector<vector<string> >& ans,int n)
    {
        if(col>=n) 
        {
            storeAns(ans,grid);
            return ;
        }

        for(int i=0;i<n;i++)
        {
            if(isValid(i,col,grid,n))
            {
                grid[i][col]='Q';
                rowChk[i]=1;
                upperChk[n+(i-col)]=1;
                lowerChk[i+col]=1;
                Solve(grid,col+1,ans,n);
                grid[i][col]='.';
                rowChk[i]=0;
                upperChk[n+(i-col)]=0;
                lowerChk[i+col]=0;
            }
        }
        return ;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> >ans;
        vector<vector<char> >grid(n,vector<char>(n,'.'));
        Solve(grid,0,ans,n);
        return ans;
    }
};
