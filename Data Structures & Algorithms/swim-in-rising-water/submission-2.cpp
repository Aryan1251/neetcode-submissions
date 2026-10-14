class Solution {
    private:
    bool chkValid(int i,int j,vector<vector<int> >& grid,int mid,vector<vector<int> >& vis)
    {
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]<=mid && !vis[i][j]) 
        return true;
        return false;
    }
    bool isPossible(int mid,vector<vector<int> >& grid)
    {
        if(grid[0][0]>mid) return false;
        queue<pair<int,int> >q;
        int n=grid.size();
        q.push({0,0});
        vector<vector<int> >vis(n,vector<int>(n,0));
        vis[0][0]=1;
        while(!q.empty())
        {
            int rowIndex=q.front().first;
            int colIndex=q.front().second;
            if(rowIndex==n-1 && colIndex==n-1) return true;
            q.pop();
            int row[]={0,-1,0,1};
            int col[]={-1,0,1,0};
            for(int i=0;i<4;i++)
            {
                int rIndex=row[i]+rowIndex;
                int cIndex=col[i]+colIndex;
                if(chkValid(rIndex,cIndex,grid,mid,vis))
                {
                    vis[rIndex][cIndex]=1;
                    q.push({rIndex,cIndex});
                }
            }
        }
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int maxEle=0;
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                maxEle=max(maxEle,grid[i][j]);
            }
        }
        int s=0,e=maxEle,ans=-1;
        //cout<<s<<" "<<e<<endl;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            //cout<<mid<<" ";
            if(isPossible(mid,grid))
            {
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return ans;
    }
};
