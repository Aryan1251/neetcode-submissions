class Solution {
    bool isValid(vector<vector<char> >& board,int i,int j,char ch,vector<vector<int> >& vis)
    {
        int n=board.size();
        int m=board[0].size();
        if(i>=0 && j>=0 && i<n && j<m && board[i][j]==ch && !vis[i][j]) return 1;
        return 0;
    }
    bool dfs(vector<vector<char> >& board,string word,int i,int j,int index,vector<vector<int> >& vis)
    {
        vis[i][j]=1;
        if(index>=word.size()) return true;
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        for(int k=0;k<4;k++)
        {
            int rowInd=row[k]+i;
            int colInd=col[k]+j;
            if(isValid(board,rowInd,colInd,word[index],vis))
            {
                bool ans=dfs(board,word,rowInd,colInd,index+1,vis);
                if(ans) return true;
            }
        }
        vis[i][j]=0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int> >vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    bool ans=dfs(board,word,i,j,1,vis);
                    if(ans) return true;
                }
            }
        }
        return false;
    }
};
