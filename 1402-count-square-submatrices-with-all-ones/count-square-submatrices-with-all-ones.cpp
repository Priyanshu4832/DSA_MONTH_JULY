class Solution {
public:

    int cnt(int r , int c , vector<vector<int>>& matrix,vector<vector<int>> &dp){
        if(r>=matrix.size() || c>=matrix[0].size()) return 0;

        if(matrix[r][c]==0) return 0;

        if(dp[r][c]!=-1) return dp[r][c];

        return dp[r][c] = 1 + min( cnt(r,c+1,matrix,dp)  , min( cnt(r+1,c+1,matrix,dp) , cnt(r+1,c,matrix , dp)  ) );
    }
    int countSquares(vector<vector<int>>& matrix) {
        
        int n = matrix[0].size();
        int m = matrix.size();
        vector<vector<int>> dp(m , vector<int>(n,-1));

        int res=0;
        for(int i = 0 ; i<m ; i++){
            for(int j =0 ; j<n ; j++){
                if(matrix[i][j]==1){
                    res+=cnt(i,j,matrix , dp);
                }
            }
        }
        return res;
    }
};