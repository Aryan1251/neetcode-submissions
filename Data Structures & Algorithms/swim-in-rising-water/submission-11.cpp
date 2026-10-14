class Solution {
    bool isValid(int i,int j,int mid,vector<vector<int> >& grid,vector<vector<int> >& vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]<=mid && !vis[i][j]) return 1;
        return 0;
    }
    bool dfs(vector<vector<int> >& grid,int mid,vector<vector<int> >& vis,int i,int j)
    {
        if(grid[0][0]>mid) return false;
        int n=grid.size();
        int m=grid[0].size();
        if(i==n-1 && j==m-1) return true;
        vis[i][j]=1;

        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        bool ans=false;
        for(int k=0;k<4;k++)
        {
            int rInd=row[k]+i;
            int cInd=col[k]+j;
            if(isValid(rInd,cInd,mid,grid,vis))
            {
                bool op=dfs(grid,mid,vis,rInd,cInd);
                ans=ans|op;
            }
        }
        vis[i][j]=0;
        return ans;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int s=0,e=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                e=max(e,grid[i][j]);
            }
        }
        int ans=-1;
        vector<vector<int> >vis(n,vector<int>(m,0));
        while(s<=e)
        {
            int mid=(s+e)>>1;
            if(dfs(grid,mid,vis,0,0))
            {
                ans=mid;
                e=mid-1;
            }else
            s=mid+1;
        }
        return ans;
    }
};
