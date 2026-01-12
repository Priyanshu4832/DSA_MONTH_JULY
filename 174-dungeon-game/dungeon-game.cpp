class Solution {
public:

    int func(int r,int c,int m ,int n,vector<vector<int>>& dungeon , vector<vector<int>>& dp ){

        if(r==m || c==n) return 1e6;

        if(r==m-1 && c==n-1){
            int health = max(1,1-dungeon[r][c] );
            return health;
        }

        if(dp[r][c]!=-1) return dp[r][c];

        int right = func(r,c+1,m,n,dungeon,dp);
        int down = func(r+1,c,m,n,dungeon,dp);

        int healthReq = min(right,down) - dungeon[r][c];

        return dp[r][c]=max(1,healthReq);
       
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(0,0,m,n,dungeon,dp);
    }
};