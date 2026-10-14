class Solution {
    bool isValid(int i,int j,vector<vector<char> >& board,vector<vector<int> >& vis)
    {
        int n=board.size();
        int m=board[0].size();
        if(i>=0 && j>=0 && i<n && j<m && board[i][j]=='O' && !vis[i][j])
        return true;
        return false;
    }
    void dfs(int i,int j,vector<vector<char> >& board,vector<vector<int> >& vis)
    {
        vis[i][j]=1;
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        for(int k=0;k<4;k++)
        {
            int rInd=row[k]+i;
            int cInd=col[k]+j;
            if(isValid(rInd,cInd,board,vis))
            {
                dfs(rInd,cInd,board,vis);
            }
        }
        return ;
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        //1st row and last row
        vector<vector<int> >vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && board[0][j]=='O')
            dfs(0,j,board,vis);
            if(!vis[n-1][j] && board[n-1][j]=='O')
            dfs(n-1,j,board,vis);
        }
        //last col and last col
        for(int i=0;i<n;i++)
        {
            if(!vis[i][m-1] && board[i][m-1]=='O')
            dfs(i,m-1,board,vis);
            if(!vis[i][0] && board[i][0]=='O')
            dfs(i,0,board,vis);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && board[i][j]=='O')
                board[i][j]='X';
            }
        }
        return ;
    }
};
