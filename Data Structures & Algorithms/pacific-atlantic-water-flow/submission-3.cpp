class Solution {
    bool isValid(int i,int j,int rInd,int cInd,vector<vector<int> >& vis,vector<vector<int> >& heights)
    {
        int row=vis.size();
        int col=vis[0].size();
        if(rInd>=0 && cInd>=0 && rInd<row && cInd<col && !vis[rInd][cInd] && heights[i][j]<=heights[rInd][cInd])
        return true;
        return false;
    }
    void dfs1(vector<vector<int> >& pac,int i,int j,vector<vector<int> >& heights)
    {
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        for(int  k=0;k<4;k++)
        {
            int rInd=row[k]+i;
            int cInd=col[k]+j;
            if(isValid(i,j,rInd,cInd,pac,heights))
            {
                pac[rInd][cInd]=1;
                dfs1(pac,rInd,cInd,heights);
            }
        }
    }
    void dfs2(vector<vector<int> >& atlan,int i,int j,vector<vector<int> >& heights)
    {
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        for(int  k=0;k<4;k++)
        {
            int rInd=row[k]+i;
            int cInd=col[k]+j;
            if(isValid(i,j,rInd,cInd,atlan,heights))
            {
                atlan[rInd][cInd]=1;
                dfs2(atlan,rInd,cInd,heights);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row=heights.size();
        int col=heights[0].size();
        vector<vector<int> >pac(row,vector<int>(col,0));
        vector<vector<int> >atlan(row,vector<int>(col,0)); 
        for(int j=0;j<col;j++)
        {
            pac[0][j]=1;
            dfs1(pac,0,j,heights);
        }
        for(int i=0;i<row;i++)
        {
            pac[i][0]=1;
            dfs1(pac,i,0,heights);
        }
        for(int j=0;j<col;j++)
        {
            atlan[row-1][j]=1;
            dfs2(atlan,row-1,j,heights);
        }
        for(int i=0;i<row;i++)
        {
            atlan[i][col-1]=1;
            dfs2(atlan,i,col-1,heights);
        }
        vector<vector<int> >ans;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(atlan[i][j] && pac[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
