class Solution {
    bool chkValid(vector<vector<int> >& grid,vector<vector<int> >& vis,int mid,int rInd,int cInd)
    {
        int n=grid.size();
        if(rInd>=0 && cInd>=0 && rInd<n && cInd<n && grid[rInd][cInd]<=mid && !vis[rInd][cInd]) return true;
        return false;
    }
    bool dfs(vector<vector<int> >& grid,int i,int j,int mid,vector<vector<int> >& vis)
    {
        vis[i][j]=1;
        int n=grid.size();
        if(i==n-1 && j==n-1) return true;

        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        for(int k=0;k<4;k++)
        {
            int rInd=row[k]+i;
            int cInd=col[k]+j;
            if(chkValid(grid,vis,mid,rInd,cInd))
            {
                if(dfs(grid,rInd,cInd,mid,vis)) return true;
            }
        }
        vis[i][j]=0;
        return false;
    }
    bool isPossible(vector<vector<int> >& grid,int mid)
    {
        if(grid[0][0]>mid) return false;
        int n=grid.size();
        vector<vector<int> >vis(n,vector<int>(n,0));
        return dfs(grid,0,0,mid,vis);
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int s=0,e=INT_MIN;
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                e=max(e,grid[i][j]);
            }
        }
        int ans=-1;
        while(s<=e)
        {
            int mid=(s+e)>>1;
            if(isPossible(grid,mid))
            {
                ans=mid;
                e=mid-1;
            }else
            s=mid+1;
        }
        return ans;
    }
};
