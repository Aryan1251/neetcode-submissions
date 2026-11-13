class Solution {
    private:
    bool isValid(int i,int j,vector<vector<char>>& board,vector<vector<int> >& vis,string &word,int wordInd)
    {
        int n=board.size();
        int m=board[0].size();

        if(i>=0 && i<n && j>=0 && j<m && !vis[i][j] && board[i][j]==word[wordInd])
        return true;
        return false;
    }
    bool findWord(vector<vector<char>>& board,vector<vector<int> >& vis,string &word,int rowInd,int colInd,int wordInd)
    {
        if(wordInd>=word.size()) return true;

        vis[rowInd][colInd]=1;
        int row[]={-1,0,1,0};
        int col[]={0,-1,0,1};

        for(int i=0;i<4;i++)
        {
            int rInd=row[i]+rowInd;
            int cInd=col[i]+colInd;
            if(isValid(rInd,cInd,board,vis,word,wordInd))
            {
                bool ans=findWord(board,vis,word,rInd,cInd,wordInd+1);
                if(ans) return true;
            }
        }
        vis[rowInd][colInd]=0;
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
                    if(findWord(board,vis,word,i,j,1)) return true;
                }
            }
        }
        return false;
    }
};
