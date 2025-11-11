class Solution {
public:

    int func(int i , int m , int n , vector<string>& strs ,vector<vector<vector<int>>> &dp){
        if(i>=strs.size()) return 0 ;

        if(dp[i][m][n]!=-1) return dp[i][m][n];
        
        int cnt1=0;
        int cnt0=0;
        for(auto ch : strs[i]){
            if(ch=='1') cnt1+=1;
            else cnt0+=1;
        }

        int pick = 0;
        if(m>=cnt0 && n>=cnt1){
            pick = 1 + func(i+1 , m-cnt0 , n-cnt1 , strs,dp);
        }
        int notPick = 0 + func(i+1,m,n,strs ,dp);

        return dp[i][m][n]=max(pick,notPick);
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<vector<int>>> dp(strs.size() , vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return func(0,m,n,strs,dp);
    }
};