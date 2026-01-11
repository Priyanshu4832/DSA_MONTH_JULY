class Solution {
public:

    long long func(int idx , int amt , vector<int>& coins , vector<vector<int>>& dp){

        if(amt==0) return 0;
        if(idx==coins.size()-1){
            if(amt%coins[idx]==0) return amt/coins[idx];
            else return INT_MAX;
        };

        if(dp[idx][amt]!=-1) return dp[idx][amt];
        //pick coin if i can
        long long pick = INT_MAX;
        if(amt>=coins[idx]){
            pick = 1 + func(idx,amt-coins[idx] , coins ,dp);
            
        }
        long long notPick = 0 + func(idx+1 , amt , coins,dp);

        return dp[idx][amt]=min(pick,notPick);
        

    }
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        long long ans = func(0,amount,coins,dp);
        return (ans==INT_MAX) ? -1 : ans;
    }
};