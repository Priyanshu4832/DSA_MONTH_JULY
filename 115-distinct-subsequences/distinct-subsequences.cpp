class Solution {
public:
    int func(int idx1 , int idx2 , string&s , string&t , vector<vector<int>>& dp){

        if(idx2==t.size()) return 1;
        if(idx1==s.size()) return 0;

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        int pick1 = 0;
        int pick2 = 0;
        if(s[idx1]==t[idx2]){
            pick1 = func(idx1+1 , idx2+1 , s ,t , dp);

        }
        pick2 = func(idx1+1 , idx2 , s , t , dp);

        return dp[idx1][idx2]=(pick1+pick2);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp (s.size() , vector<int>(t.size(),-1));
        return func(0,0,s,t,dp);
    }
};