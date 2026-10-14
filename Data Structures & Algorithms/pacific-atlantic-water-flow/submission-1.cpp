class Solution {
    private:
    bool isValid(int i,int j,int curri,int currj,vector<vector<int> >& vis,vector<vector<int> >& heights)
    {
        int n=heights.size();
        int m=heights[0].size();
        if(curri>=0 && currj>=0 && curri<n && currj<m && !vis[curri][currj] && heights[curri][currj]>=heights[i][j])
        return true;
        return false;
    }
    void dfs(int i,int j,vector<vector<int> >& vis,vector<vector<int> >& heights)
    {
        vis[i][j]=1;
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        for(int k=0;k<4;k++)
        {
            int rInd=row[k]+i;
            int cInd=col[k]+j;
            if(isValid(i,j,rInd,cInd,vis,heights))
            dfs(rInd,cInd,vis,heights);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int> >vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j])
            dfs(0,j,vis,heights);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0])
            dfs(i,0,vis,heights);
        }
        vector<vector<int> >vis2(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(!vis2[i][m-1])
            dfs(i,m-1,vis2,heights);
        }
        for(int j=m-1;j>=0;j--)
        {
            if(!vis2[n-1][j])
            dfs(n-1,j,vis2,heights);
        }
        vector<vector<int> >ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j] && vis2[i][j])
                ans.push_back({i,j});
            }
        }
        return ans;
    }
};
