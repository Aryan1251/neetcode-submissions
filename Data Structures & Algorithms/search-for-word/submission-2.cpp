class Solution {
    bool isValid(int i,int j,vector<vector<int> >& vis,vector<vector<char> >& board,char ch)
    {
        int n=board.size();
        int m=board[0].size();

        if(i>=0 && j>=0 && i<n && j<m && !vis[i][j] && board[i][j]==ch)
        return true;
        return false;
    }
    bool dfs(vector<vector<char> >& board,vector<vector<int> >& vis,int i,int j,string word, int wordInd)
    {
        if(wordInd>=word.size())
        return true;

        vis[i][j]=1;
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        bool op1=false;
        for(int k=0;k<4;k++)
        {
            int rInd=row[k]+i;
            int cInd=col[k]+j;
            if(isValid(rInd,cInd,vis,board,word[wordInd]))
            {
                op1=op1 | dfs(board,vis,rInd,cInd,word,wordInd+1);
            }
        }
        vis[i][j]=0;
        return op1;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    vector<vector<int> >vis(n,vector<int>(m,0));
                    if(dfs(board,vis,i,j,word,1)) return true;
                }
            }
        }
        return false;
    }
};
