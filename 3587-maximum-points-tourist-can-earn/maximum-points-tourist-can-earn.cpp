class Solution {
public:

    int func(int city , int day , int n , int k , vector<vector<int>>& stayScore, vector<vector<int>>& travelScore ,vector<vector<int>>& dp){

        if(day==k) return 0;
        if(dp[city][day]!=-1) return dp[city][day];


        //choice 1 stay in the city
        int stay = stayScore[day][city] + func(city,day+1,n,k,stayScore,travelScore,dp);

        int move = 0;
        for(int i=0 ; i<n ; i++){
            int pts = travelScore[city][i] + func(i,day+1,n,k,stayScore,travelScore,dp);
            move = max(pts,move);
        }

        return dp[city][day]= max(stay,move);

    }
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        
        int ans = 0;
        vector<vector<int>> dp(201,vector<int>(201,-1));
        for(int i = 0 ; i<n ; i++){
            
            ans = max(ans,func(i,0,n,k,stayScore,travelScore,dp));

        }
        return ans;
    }
};