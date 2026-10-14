class Solution {
    private:
    bool isValid(int i,int j,vector<vector<int> >& vis,vector<vector<char> >& grid)
    {
        if(i>=0 && j>=0 && i<vis.size() && j<vis[0].size() && !vis[i][j] && grid[i][j]=='1')
        return true;
        return false;
    }
    void dfs(int i,int j,vector<vector<int> >& vis,vector<vector<char> >& grid)
    {
        vis[i][j]=1;
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        for(int k=0;k<4;k++)
        {
            int rowIndex=row[k]+i;
            int colIndex=col[k]+j;
            if(isValid(rowIndex,colIndex,vis,grid))
            {
                dfs(rowIndex,colIndex,vis,grid);
            }
        }
        return ;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int> >vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};
