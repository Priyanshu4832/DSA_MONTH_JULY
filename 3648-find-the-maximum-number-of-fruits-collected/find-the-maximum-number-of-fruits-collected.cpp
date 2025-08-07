class Solution {
public:
    long long func1(int r , int c ,vector<vector<int>>& fruits,vector<vector<long long>> &dp){
        int n = fruits.size();
        
        if(r==n-1 && c==n-1) return 0;
        //if(r>=c || c>=n) return -1e12;
        

        if(dp[r][c]!=-1) return dp[r][c];

        long long collection = 0;
        for(int i=-1 ; i<=1 ; i++){
            
            int nr = r+1;
            int nc = c+i;
            if( (nr<nc && nc<n && nc>=0 )  || (nr==n-1 && nc==n-1)  ){
                collection = max(collection , fruits[r][c] + func1(nr,nc,fruits,dp));
            }
            
        }

        return dp[r][c]=collection;
    }

    long long func2(int r , int c ,vector<vector<int>>& fruits,vector<vector<long long>> &dp){
        int n = fruits.size();
        
        if(r==n-1 && c==n-1) return 0;
        //if(r<=c || r>=n) return -1e12;
        
        

        if(dp[r][c]!=-1) return dp[r][c];

        long long collection = 0;
        for(int i=-1 ; i<=1 ; i++){
  
            int nr = r+i;
            int nc = c+1;
            if( (nr>nc && nr<n && nr>=0)   ||  (nr==n-1 && nc==n-1) ){
                collection = max(collection , fruits[r][c] + func2(nr,nc,fruits,dp));
            }
            
         
        }
        

        return dp[r][c]=collection;
    }



    int maxCollectedFruits(vector<vector<int>>& fruits) {
        

        long long collect = 0 ;
        int n = fruits.size();
        for(int i=0 ; i<n ; i++){
            collect +=fruits[i][i];
        }





        vector<vector<long long>> dp(n,vector<long long>(n,-1));
        collect+=func1(0,n-1,fruits,dp);


        vector<vector<long long>> dpp(n,vector<long long>(n,-1));
        
        collect+=func2(n-1,0,fruits,dpp);



        return collect;
    }
};