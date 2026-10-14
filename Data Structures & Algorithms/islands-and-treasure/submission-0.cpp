class Solution {
    private:
    bool isValid(int i,int j,vector<vector<int> >& grid,int n,int m,int INF)
    {
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]!=-1 && grid[i][j]==INF) return true;
        return false;
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int> >>q;
        int INF=2147483647;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                q.push({0,{i,j}});
            }
        }
        while(!q.empty())
        {
            int cnt=q.front().first;
            int rowIndex=q.front().second.first;
            int colIndex=q.front().second.second;
            q.pop();
            int row[]={0,-1,0,1};
            int col[]={-1,0,1,0};
            for(int i=0;i<4;i++)
            {
                int rInd=row[i]+rowIndex;
                int cInd=col[i]+colIndex;
                if(isValid(rInd,cInd,grid,n,m,INF))
                {
                    grid[rInd][cInd]=cnt+1;
                    q.push({cnt+1,{rInd,cInd}});
                }
            }
        }
        return ;
    }
};
