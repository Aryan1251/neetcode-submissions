class Solution {
    private:
    bool isValid(int i,int j,vector<vector<int> >& vis,vector<vector<char> > &board,char ch)
    {
        int n=board.size();
        int m=board[0].size();
        if(i>=0 && j>=0 && i<n && j<m && !vis[i][j] && board[i][j]==ch) return true;
        return false;
    }
    bool dfs(vector<vector<char> >&board,int i,int j,vector<vector<int> >& vis,string& word,int wordInd)
    {
        if(wordInd>=word.size()) return true;

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
                op1=op1 | dfs(board,rInd,cInd,vis,word,wordInd+1);
                if(op1==true) break;
            }
        }
        vis[i][j]=0;

        return op1;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=board.size();
        int m=board[0].size();
        vector<string>ans;

        for(auto &str: words)
        {
            int ind=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(board[i][j]==str[0])
                    {
                        vector<vector<int> >vis(n,vector<int>(m,0));
                        if(dfs(board,i,j,vis,str,1)){
                            ind=1;
                            ans.push_back(str);
                            break;
                        }
                    }
                }
                if(ind) break;
            }
        }
        return ans;
    }
};
