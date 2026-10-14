#define INF 2147483647
bool isValid(int i,int j,vector<vector<int> >& grid,vector<vector<int> >& dist,int D)
{
    if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]!=-1 && dist[i][j]>D+1)
    return true;
    return false; 
}
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> >dist(n,vector<int>(m,INF));

        queue<pair<int,pair<int,int>> >q;
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
            auto D=q.front().first;
            auto curr_row=q.front().second.first;
            auto curr_col=q.front().second.second;
            if(dist[curr_row][curr_col]>D) dist[curr_row][curr_col]=D;

            q.pop();
            int row[]={0,-1,0,1};
            int col[]={-1,0,1,0};

            for(int i=0;i<4;i++)
            {
                int rr=row[i]+curr_row;
                int cc=col[i]+curr_col;
                if(isValid(rr,cc,grid,dist,D))
                {
                    q.push({D+1,{rr,cc}});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==-1) continue;
                grid[i][j]=dist[i][j];
            }
        }
        return ;
    }
};
