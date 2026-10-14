class Solution {
    bool isValid(int i,int j,vector<vector<int> >& vis,vector<vector<int> >& grid)
    {
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]==1 && !vis[i][j])
        return 1;
        else
        return 0;
    }
    int dfs(vector<vector<int> >& grid,vector<vector<int> >& vis,int i,int j)
    {
        vis[i][j]=1;
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        int cnt=1;
        for(int k=0;k<4;k++)
        {
            int rInd=row[k]+i;
            int cInd=col[k]+j;
            if(isValid(rInd,cInd,vis,grid))
            {
                cnt+=dfs(grid,vis,rInd,cInd);
            }
        }
        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> >vis(n,vector<int>(m,0));
        int max_area=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    int area=dfs(grid,vis,i,j);
                    max_area=max(max_area,area);
                }
            }
        }
        cout<<endl;
        return max_area;
    }
};
