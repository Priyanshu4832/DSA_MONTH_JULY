class Solution {
public:

    int func( int idx1 , int idx2 , string& word1, string& word2  , vector<vector<int>>&dp){

        if(idx1==word1.size() && idx2==word2.size()) return 0;
        if(idx1==word1.size()) return word2.size()-idx2;
        if(idx2==word2.size()) return word1.size()-idx1;

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        int steps = 0;
        if(word1[idx1]==word2[idx2]){
            steps = 0 + func(idx1 + 1 , idx2 + 1 , word1 ,word2 , dp);
        }
        //insert
        else{
            steps = 1 + min( {func(idx1 , idx2 + 1 , word1 , word2 , dp),  func(idx1 + 1 , idx2 , word1 , word2 , dp) , func(idx1 + 1 , idx2 +1 , word1 , word2 , dp)} );
        }

        return dp[idx1][idx2]=steps;
        
    }
    int minDistance(string word1, string word2) {
        
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return func(0,0,word1,word2,dp);
    }
};