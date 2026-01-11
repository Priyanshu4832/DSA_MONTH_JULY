class Solution {
public:

    int func( int idx1 , int idx2 , string& text1, string& text2  , vector<vector<int>>&dp){

        if(idx1==text1.size() || idx2==text2.size()) return 0;

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        int match = 0;
        if(text1[idx1]==text2[idx2]){
            match = 1 + func(idx1+1 , idx2+1 , text1, text2 ,dp);
        }
        else{
            match = 0 +  max( {func(idx1 , idx2 + 1 , text1 , text2 , dp),  func(idx1 + 1 , idx2 , text1 , text2 , dp) , func(idx1 + 1 , idx2 +1 , text1 , text2 , dp)} );
        }

        return dp[idx1][idx2]=match;

        
    }
    
    int longestCommonSubsequence(string text1, string text2) {

        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return func(0,0,text1,text2,dp);
    }
};