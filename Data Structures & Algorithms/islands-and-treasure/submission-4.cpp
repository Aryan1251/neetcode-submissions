class Solution {
    bool isValid(int i,int j,int dis,vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();   
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]!=0 && grid[i][j]!=-1 && grid[i][j]>dis+1)
        return 1;
        return 0;
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>> >q;
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
            int dis=q.front().first;
            int rInd=q.front().second.first;
            int cInd=q.front().second.second;
            q.pop();

            int row[]={0,1,0,-1};
            int col[]={-1,0,1,0};

            for(int i=0;i<4;i++)
            {
                int rowInd=row[i]+rInd;
                int colInd=col[i]+cInd;
                if(isValid(rowInd,colInd,dis,grid))
                {
                    q.push({dis+1,{rowInd,colInd}});
                    grid[rowInd][colInd]=dis+1;
                }
            }
        }
        return ;
    }
};
