class Solution {
public:


    int dfs(int r , int c , int curr , vector<vector<int>>& matrix, vector<vector<int>> &dp ){


        int n = matrix[0].size();
        int m = matrix.size();
        if(dp[r][c]!=-1) return dp[r][c];



        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        int maxi=0;
        for(int i = 0 ; i<4 ; i++){
            int nr = r+ drow[i];
            int nc = c + dcol[i];


            if(nr>=0 && nc>=0 && nr<m && nc<n && matrix[nr][nc]>curr){
                maxi = max(maxi , 1+dfs(nr,nc,matrix[nr][nc] ,matrix , dp));
            }
        }


        return dp[r][c]=maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix[0].size();
        int m = matrix.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));

        int res=0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(dp[i][j]==-1){
                    res= max(res, 1+dfs(i , j ,matrix[i][j],matrix , dp));
                }
                
            }
        }
        return res;
    }
};