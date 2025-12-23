class Solution {
public:

    int nextIdx( int idx  , vector<vector<int>>& events){

        int startTime = events[idx][1];

        int left = idx+1;
        int right = events.size()-1;
        int result = events.size();

        while(left<=right){
            int mid = (left+right)/2;

            if(events[mid][0]>startTime){
                right = mid-1;
                result = mid;
            }
            else{
                left = mid+1;
            }
        }
        return result;
    }

    int func(int idx , vector<vector<int>>& events ,  int left , vector<vector<int>> &dp){

        if(idx>=events.size()) return 0;
        if(left==0) return 0 ;

        if(dp[idx][left]!=-1) return dp[idx][left];

        //pick
        int pick = 0;
        if(left>0 ){
            
            int next = nextIdx(idx , events);

            pick = events[idx][2] + func(next , events  , left-1 , dp);
             
        }

        //not pick 
        int notPick = 0 + func(idx+1 , events ,  left , dp);

        return dp[idx][left] = max(pick , notPick);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        
        sort(events.begin() , events.end());
        int n = events.size();

        vector<vector<int>> dp(n,vector<int>(3,-1));
        return func(0,events , 2 , dp);

    }
};