class Solution {
    bool isValid(int i,int j,vector<vector<char> >& board,vector<vector<int> >& vis)
    {
        int n=board.size();
        int m=board[0].size();
        if(i>=0 && j>=0 && i<n && j<m && !vis[i][j] && board[i][j]=='O')
        return 1;
        return 0;
    }
    void dfs(vector<vector<char> >& board,vector<vector<int> >& vis,int i,int j)
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
                dfs(board,vis,rInd,cInd);
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
        for(int j=0;j<n;j++)
        {
            if(board[0][j]=='O' && !vis[0][j])
            {
                dfs(board,vis,0,j);
            }
        }

        //last col
        for(int i=0;i<n;i++)
        {
            if(board[i][m-1]=='O' && !vis[i][m-1])
            {
                dfs(board,vis,i,m-1);
            }
        }

        //last row
        for(int j=m-1;j>=0;j--)
        {
            if(board[n-1][j]=='O' && !vis[n-1][j])
            {
                dfs(board,vis,n-1,j);
            }
        }

        //first col
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O' && !vis[i][0])
            {
                dfs(board,vis,i,0);
            }
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
