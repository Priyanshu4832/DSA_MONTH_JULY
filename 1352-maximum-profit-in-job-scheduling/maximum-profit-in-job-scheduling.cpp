class Solution {
public:
    int bs(int target ,  vector<vector<int>>& jobs){

        int low = 0;
        int high = jobs.size();
        while(low<high){
            int mid = low + (high-low)/2;
            if(jobs[mid][0]<target){
                low = mid+1;
                
            }
            else high = mid ;
        }
        return low;
    }

    int func(int idx , vector<vector<int>>&jobs,vector<int> &dp){
        if(idx==jobs.size()) return 0 ;

        if(dp[idx]!=-1) return dp[idx];
        //pick 
        int nextIdx = bs(jobs[idx][1],jobs);
        int pick = jobs[idx][2] + func(nextIdx ,jobs,dp);

        int not_pick = 0 + func(idx+1 ,jobs,dp );

        return dp[idx]=max(pick, not_pick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        vector<vector<int>> jobs;
        for(int i = 0 ; i<startTime.size() ; i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        vector<int> dp(jobs.size()+1 , -1);
        return func(0 ,jobs , dp);
    }
};