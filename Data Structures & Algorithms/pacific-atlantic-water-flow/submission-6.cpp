class Solution {
    bool isValid(int i,int j,int prev_i,int prev_j,vector<vector<int> >& vis,vector<vector<int> >& heights)
    {
        int n=heights.size();
        int m=heights[0].size();
        if(i>=0 && j>=0 && i<n && j<m && !vis[i][j] && heights[i][j]>=heights[prev_i][prev_j])
        return 1;
        return 0;
    }
    void dfs(vector<vector<int> >& vis,vector<vector<int> >& heights,int i,int j)
    {
        vis[i][j]=1;
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        for(int k=0;k<4;k++)
        {
            int rInd=row[k]+i;
            int cInd=col[k]+j;
            if(isValid(rInd,cInd,i,j,vis,heights))
            dfs(vis,heights,rInd,cInd);
        }
        return ;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int> >pac(n,vector<int>(m,0));
        vector<vector<int> >atlan(n,vector<int>(m,0));

        //pac
        for(int j=0;j<m;j++) dfs(pac,heights,0,j);
        for(int i=0;i<n;i++) dfs(pac,heights,i,0);

        //atlan
        for(int j=0;j<m;j++) dfs(atlan,heights,n-1,j);
        for(int i=0;i<n;i++) dfs(atlan,heights,i,m-1);

        vector<vector<int> >ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pac[i][j]==1 && atlan[i][j]==1)
                ans.push_back({i,j});
            }
        }
        return ans;
    }
};
