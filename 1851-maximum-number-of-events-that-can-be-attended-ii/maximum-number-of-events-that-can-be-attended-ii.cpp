class Solution {
public:

    int binarySearch (int idx,  vector<vector<int>>& events){

        int low=0 ; 
        int ans=events.size();
        int high=events.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(events[mid][0]>events[idx][1]){
                ans = mid;
                high=mid-1;
            }
            else low=mid+1;

        }
        return ans;
    }
    int func(int idx , int k ,vector<vector<int>>& events , vector<vector<int>> &dp){
        
        if(idx==events.size() || k==0) return 0;
     
        if(dp[idx][k]!=-1) return dp[idx][k];

      
        
        int  pick = events[idx][2] + func(binarySearch(idx,events), k-1 , events, dp);
        
        int not_pick = 0 + func(idx+1 , k , events,dp);
        
        
        
        return dp[idx][k]=max(pick , not_pick);
        
        
    }
    int maxValue(vector<vector<int>>& events, int k) {
        
        vector<vector<int>> dp (events.size()+1 , vector<int>(k+1,-1));
        sort(events.begin(),events.end());
      
        return func(0,k,events,dp);

    }
};