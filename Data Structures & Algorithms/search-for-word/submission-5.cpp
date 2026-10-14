class Solution {
    bool isValid(int i,int j,vector<vector<int> >& vis,vector<vector<char> >& board,char ch)
    {
        int row=board.size();
        int col=board[0].size();
        if(i>=0 && i<row && j>=0 && j<col && !vis[i][j] && board[i][j]==ch) return true;
        return false;
    }
    bool dfs(vector<vector<char> >& board,int i,int j,vector<vector<int> >& vis,string word,int ind)
    {
        if(ind>=word.size()) return true;

        vis[i][j]=1;
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        for(int k=0;k<4;k++)
        {
            int rInd=row[k]+i;
            int cInd=col[k]+j;
            if(isValid(rInd,cInd,vis,board,word[ind]))
            {
                if(dfs(board,rInd,cInd,vis,word,ind+1)) return true;
            }
        }
        vis[i][j]=0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]==word[0])
                {
                    vector<vector<int> >vis(row,vector<int>(col,0));
                    if(dfs(board,i,j,vis,word,1)) return true;
                }
            }
        }
        return false;
    }
};
