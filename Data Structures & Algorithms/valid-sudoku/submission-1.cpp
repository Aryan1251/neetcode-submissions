class Solution {
    bool chk(vector<vector<char>>& board,int i,int j)
    {
        char ch=board[i][j];
        //rowChk
        for(int col=0;col<9;col++)
        {
            if(col!=j && board[i][col]==ch) return false;
        }
        for(int row=0;row<9;row++)
        {
            if(row!=i && board[row][j]==ch) return false;
        }
        for(int row=0;row<9;row++)
        {
            int rInd=3*(i/3)+row/3;
            int cInd=3*(j/3)+row%3;
            if(rInd!=i && cInd!=j && board[rInd][cInd]==ch) return false;
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
                else if(!chk(board,i,j)) return false;
            }
        }
        return true;
    }
};
