class Solution {
    private:
    bool isValid(int i,int j,int currI,int currJ,vector<vector<int> >& vis,vector<vector<int> >& grid,int mid)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(currI>=0 && currJ>=0 && currI<n && currJ<m && !vis[currI][currJ] && grid[currI][currJ]<=mid)
        return true;
        return false;
    }
    bool isPossible(vector<vector<int> >& grid,int mid)
    {
        if(grid[0][0]>mid) return false;
        queue<pair<int,int> >q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> >vis(n,vector<int>(m,0));
        q.push({0,0});
        vis[0][0]=1;
        while(!q.empty())
        {
            int rInd=q.front().first;
            int cInd=q.front().second;
            if(rInd==n-1 && cInd==m-1) return true;
            q.pop();
            int row[]={0,-1,0,1};
            int col[]={-1,0,1,0};
            for(int i=0;i<4;i++)
            {
                int rowInd=row[i]+rInd;
                int colInd=col[i]+cInd;
                if(isValid(rInd,cInd,rowInd,colInd,vis,grid,mid))
                {
                    vis[rowInd][colInd]=1;
                    q.push({rowInd,colInd});
                }
            }
        }
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int s=0,e=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
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
