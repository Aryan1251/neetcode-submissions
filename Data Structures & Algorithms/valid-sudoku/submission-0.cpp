class Solution {
    private:
    bool chkValid(vector<vector<char> >& board,int i,int j)
    {
        char val=board[i][j];
        //rowcheck
        for(int col=0;col<9;col++)
        {
            if(col!=j && board[i][col]==val) return false;
        }

        //col check
        for(int row=0;row<9;row++)
        {
            if(row!=i && board[row][j]==val) return false;
        }
        //3x3 box
        
        for(int row=0;row<9;row++)
        {
            int currI=3*(i/3)+(row/3);
            int currJ=3*(j/3)+(row%3);
            //cout<<currI<<" "<<currJ<<" "<<endl;
            if(currI==i && currJ==j) continue;
            if(board[currI][currJ]==val)return false;
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.') continue;
                if(!chkValid(board,i,j)) return false;
            }
        }
        return true;
    }
};
