class Solution {
public:
    int func(int r , int c , vector<vector<int>>& grid , vector<vector<vector<int>>>& dp , int k ){
        int m = grid.size();
        int n = grid[0].size();

        if(r==m-1 && c==n-1){
            return 0;
        }

        if(dp[r][c][k]!=-1) return dp[r][c][k];
        

        int right=-1e9;
    
        if(c!=n-1){
            int cellCost=grid[r][c+1];
            if(cellCost!=0) cellCost=1;
            
            if(cellCost<=k){
                right = grid[r][c+1] +  func(r,c+1,grid,dp,k-cellCost);
            }
            

        }
        int down = -1e9;
        if(r!=m-1){
            int cellCost=grid[r+1][c];
            if(cellCost!=0) cellCost=1;
            if(k>=cellCost){
                down = grid[r+1][c] +  func(r+1,c,grid,dp,k-cellCost);
            }
            
            

        }

        return dp[r][c][k] = max(right,down);
         
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m , vector<vector<int>>(n,vector<int>(k+1,-1)));

        int a = func(0,0,grid , dp , k);
        if(a<0 ) return -1;
        else return a;
        


    }
};