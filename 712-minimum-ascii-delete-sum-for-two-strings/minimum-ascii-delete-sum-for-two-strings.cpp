class Solution {
public:

    int c(int idx , string& s){
        int cost = 0;
        for(int i=idx ; i<s.size() ; i++){
            int ch = s[i]-'a'+ 97 ;
            cost+=ch;
        }
        return cost;
    }
    int func(int idx1 , int idx2 , string& s1 , string& s2 , vector<vector<int>>&dp){

        if(idx1==s1.size() && idx2==s2.size()) return 0;
        if(idx1==s1.size()) return c(idx2,s2);
        if(idx2==s2.size()) return c(idx1,s1);

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        int pick1 = 1e6;
        int pick2 = 1e6;
        int pick3 = 1e6;
        if(s1[idx1]==s2[idx2]){
            pick1 = 0 + func(idx1+1,idx2+1 , s1 , s2 , dp);
        }
        else {
            pick2 = (s1[idx1]-'a'+ 97) + func(idx1+1,idx2 , s1 , s2 , dp);
            pick3 = (s2[idx2]-'a'+ 97) + func(idx1,idx2+1 , s1 , s2 , dp);
        }

        return dp[idx1][idx2]=min({pick1,pick2,pick3});
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
        return func(0,0,s1,s2,dp);

    }
};