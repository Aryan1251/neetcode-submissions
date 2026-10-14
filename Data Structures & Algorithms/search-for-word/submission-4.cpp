class Solution {
    bool isValid(int i,int j,vector<vector<char> >& board,vector<vector<int> >& vis,char ch)
    {
        int n=board.size();
        int m=board[0].size();
        if(i>=0 && j>=0 && i<n && j<m && !vis[i][j] && board[i][j]==ch) return true;
        return false;
    }
    bool dfs(vector<vector<char> >& board,vector<vector<int> >& vis,string word,int index,int i,int j)
    {
        if(index>=word.size()-1) return true;
        vis[i][j]=1;
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        bool ans=false;
        for(int k=0;k<4;k++)
        {
            int rInd=row[k]+i;
            int cInd=col[k]+j;
            char ch=word[index+1];
            if(isValid(rInd,cInd,board,vis,ch))
            {
                ans=ans|dfs(board,vis,word,index+1,rInd,cInd);
            }
        }
        vis[i][j]=0;
        return ans;
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
                    vis[i][j]=1;
                    if(dfs(board,vis,word,0,i,j)) return true;
                }
            }
        }
        return false;
    }
};
