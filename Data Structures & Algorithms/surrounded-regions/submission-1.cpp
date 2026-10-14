class Solution {
    bool isValid(vector<vector<char> >& board,int i,int j,vector<vector<int> >& vis)
    {
        int n=board.size();
        int m=board[0].size();
        if(i>=0 && i<n && j>=0 && j<m && board[i][j]=='O' && !vis[i][j]) return true;
        return false;
    }
    void dfs(vector<vector<char> >& board,int i,int j,vector<vector<int> >& vis)
    {
        vis[i][j]=1;
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        for(int k=0;k<4;k++)
        {
            int curr_row=row[k]+i;
            int curr_col=col[k]+j;
            if(isValid(board,curr_row,curr_col,vis))
            {
                dfs(board,curr_row,curr_col,vis);
            }
        }
        return ;
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int> >vis(n,vector<int>(m,0));

        //1st row
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O')
            dfs(board,0,j,vis);
        }

        //last col
        for(int i=0;i<n;i++)
        {
            if(board[i][m-1]=='O')
            dfs(board,i,m-1,vis);
        }

        //last row
        for(int j=m-1;j>=0;j--)
        {
            if(board[n-1][j]=='O')
            dfs(board,n-1,j,vis);
        }

        //first col
        for(int i=n-1;i>=0;i--)
        {
            if(board[i][0]=='O')
            dfs(board,i,0,vis);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && !vis[i][j])
                board[i][j]='X';
            }
        }
        return ;
    }
};
