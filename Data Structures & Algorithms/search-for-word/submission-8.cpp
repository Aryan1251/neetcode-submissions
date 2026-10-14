class Solution {
    bool isValid(vector<vector<char> >& board,vector<vector<int> >& vis,string word,int index,int i,int j)
    {
        int n=board.size();
        int m=board[0].size();
        if(i>=0 && j>=0 && i<n && j<m && board[i][j]==word[index] && !vis[i][j])
        return 1;
        return 0;
    }
    bool isPresent(vector<vector<char> >& board,vector<vector<int> >& vis,string word,int wordIndex,int i,int j)
    {
        if(wordIndex>=word.size()) return 1;
        vis[i][j]=1;
        int rowIndex[]={0,-1,0,1};
        int colIndex[]={-1,0,1,0};

        for(int k=0;k<4;k++)
        {
            int rInd=rowIndex[k]+i;
            int cInd=colIndex[k]+j;
            if(isValid(board,vis,word,wordIndex,rInd,cInd))
            {
                if(isPresent(board,vis,word,wordIndex+1,rInd,cInd))
                return true;
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
                    if(isPresent(board,vis,word,1,i,j)) return 1;
                }
            }
        }
        return 0;
    }
};
