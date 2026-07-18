class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int island=0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(i,j,visited,n,m,grid);
                    island++;
                }
            }
        }
        return island;

        
    }
    void dfs(int i,int j,vector<vector<bool>>&visited,int n,int m,vector<vector<char>> &grid){
        if(i<0 || j<0 || i>=n || j>=m|| visited[i][j] || grid[i][j]!='1'){
            return;
        }
        visited[i][j]=true;
        dfs(i-1,j,visited,n,m,grid);
        dfs(i,j-1,visited,n,m,grid);
        dfs(i,j+1,visited,n,m,grid);
        dfs(i+1,j,visited,n,m,grid);
    }
};
