class Solution {
public:

    void dfs(int r , int c , vector<vector<int>> &vis , vector<vector<char>>& grid){

        int m = grid.size();
        int n = grid[0].size();

        vis[r][c]=1;
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};

        for(int i=0 ; i<4 ; i++){
            int nr = drow[i]+r;
            int nc = dcol[i]+c;
            if( nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]=='1' && vis[nr][nc]==0){
                dfs(nr,nc,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        int islands=0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    islands++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return islands;
    }
};