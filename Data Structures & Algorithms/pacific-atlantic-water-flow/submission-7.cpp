class Solution {
    bool isValid(int nbr_i,int nbr_j,int i,int j,vector<vector<int> >& vis,vector<vector<int> >& heights)
    {
        int row=heights.size();
        int col=heights[0].size();
        if(i>=0 && j>=0 && i<row && j<col && heights[i][j]>=heights[nbr_i][nbr_j] && !vis[i][j]) return 1;
        return 0;
    }
    void dfs(vector<vector<int>>& heights,vector<vector<int>>& vis,int rInd,int cInd)
    {
        vis[rInd][cInd]=1;
        int row[]={0,1,0,-1};
        int col[]={-1,0,1,0};

        for(int i=0;i<4;i++)
        {
            int rowInd=row[i]+rInd;
            int colInd=col[i]+cInd;
            if(isValid(rInd,cInd,rowInd,colInd,vis,heights))
            dfs(heights,vis,rowInd,colInd);
        }
        return ;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row=heights.size();
        int col=heights[0].size();
        vector<vector<int> >ans;
        vector<vector<int> >pac(row,vector<int>(col,0));
        vector<vector<int> >atlan(row,vector<int>(col,0));
        //pacific
        for(int j=0;j<col;j++)
        {
            if(!pac[0][j]) 
            dfs(heights,pac,0,j);

            if(!atlan[row-1][j])
            dfs(heights,atlan,row-1,j);
        }

        for(int i=0;i<row;i++)
        {
            if(!pac[i][0])
            dfs(heights,pac,i,0);

            if(!atlan[i][col-1])
            dfs(heights,atlan,i,col-1);
        }

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(pac[i][j] && atlan[i][j])
                ans.push_back({i,j});
            }
        }
        return ans;
    }
};
