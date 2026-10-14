class Solution {
    bool isValid(int i,int j,vector<vector<int> >& grid,vector<vector<int> >& vis,int mid)
    {
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]<=mid && !vis[i][j]) return true;
        return false;
    }
    bool isPossible(int mid,vector<vector<int> >& grid)
    {
        if(mid<grid[0][0]) return false;
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> >vis(n,vector<int>(m,0));
        queue<pair<int,int> >q;
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
                int rr=row[i]+rInd;
                int cc=col[i]+cInd;
                if(isValid(rr,cc,grid,vis,mid))
                {
                    q.push({rr,cc});
                    vis[rr][cc]=1;
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
            e=max(e,grid[i][j]);
        }
        int ans=-1;
        while(s<=e)
        {
            int mid=(s+e)>>1;
            if(isPossible(mid,grid))
            {
                ans=mid;
                e=mid-1;
            }else
            s=mid+1;
        }
        return ans;
    }
};
