class Solution {
    unordered_map<int,int>rowChk;
    unordered_map<int,int>colChk;
    unordered_map<int,int>blockChk;
    bool Valid(vector<vector<char> >& board,int i,int j)
    {
        for(int col=0;col<9;col++)
        {
            if(col!=j && board[i][j]==board[i][col]) return false;
        }
        for(int row=0;row<9;row++)
        {
            if(row!=i && board[i][j]==board[row][j]) return false;
        }
        //3*3 chk
        for(int k=0;k<9;k++)
        {
            int rInd=3*(i/3)+k/3;
            int cInd=3*(j/3)+k%3;
            if(rInd!=i && cInd!=j && board[rInd][cInd]==board[i][j]) return false;
        }

        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(!Valid(board,i,j)) return false;
                }
            }
        }
        return true;
    }
};
