class Solution {
public:
    int func(int i, int j, vector<vector<char>>& matrix, vector<vector<int>>& dp) {
    
        if (i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] == '0') {
            return 0;
        }
        

        if (dp[i][j] != -1)  return dp[i][j];
        
        
       
        int down = func(i + 1, j, matrix, dp);      
        int right = func(i, j + 1, matrix, dp);        
        int diagonal = func(i + 1, j + 1, matrix, dp);
        

        
        return dp[i][j] = 1 + min({down, right, diagonal});;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
   
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        int maxSquare = 0;
        
    
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    maxSquare = max(maxSquare, func(i, j, matrix, dp));
                }
            }
        }
        
        return maxSquare * maxSquare; 
    }
};
