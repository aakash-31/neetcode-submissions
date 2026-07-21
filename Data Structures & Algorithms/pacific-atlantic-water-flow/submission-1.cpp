class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        vector<vector<bool>>pacific(m,vector<bool>(n,false));
        vector<vector<bool>>atlantic(m,vector<bool>(n,false));
        vector<vector<int>>res;
        for(int j=0;j<n;j++){
            dfs(v,0,j,INT_MIN,pacific);
            dfs(v,m-1,j,INT_MIN,atlantic);
        }
        for(int i=0;i<m;i++){
            dfs(v,i,0,INT_MIN,pacific);
            dfs(v,i,n-1,INT_MIN,atlantic);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j])
                    res.push_back({i,j});
            }
        }
        return res;

        
    }
    void dfs(vector<vector<int>>& v,int i,int j,int prev,vector<vector<bool>>&visited){
        if(i<0 || i>=v.size() || j<0 || j>=v[0].size())
            return;
        if(v[i][j]<prev || visited[i][j])
            return;
        visited[i][j]=true;
        dfs(v,i-1,j,v[i][j],visited);
        dfs(v,i+1,j,v[i][j],visited);
        dfs(v,i,j-1,v[i][j],visited);
        dfs(v,i,j+1,v[i][j],visited);
    }
};