class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int island=0;
        int max_area=0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int res=dfs(i,j,visited,n,m,grid);
                    max_area=max(res,max_area);
                }
            }
        }
        return max_area;

        
    }
    int dfs(int i,int j,vector<vector<bool>>&visited,int n,int m,vector<vector<int>> &grid){
        if(i<0 || j<0 || i>=n || j>=m|| visited[i][j] || grid[i][j]!=1){
            return 0;
        }
        visited[i][j]=true;
        int area=1;
        area+=dfs(i-1,j,visited,n,m,grid);
        area+=dfs(i,j-1,visited,n,m,grid);
        area+=dfs(i,j+1,visited,n,m,grid);
        area+=dfs(i+1,j,visited,n,m,grid);
        return area;

    }
};

