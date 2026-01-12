class Solution {
public:
    // int func(int idx , int prev , vector<int>& nums , vector<map<int,int>>&dp){

    //     if(idx==nums.size()) return 0 ;

    //     if(dp[idx].find(prev)!=dp[idx].end()) return dp[idx][prev];
    //     //pick 
    //     int pick = 0;
    //     if(prev==-1e6 || nums[idx]>prev){
    //         pick = 1 + func( idx+1 , nums[idx] ,  nums , dp);

    //     }
    //     int notPick = 0 + func(idx+1 , prev , nums , dp);

    //     return dp[idx][prev]=max(pick,notPick);
    // }
    int lengthOfLIS(vector<int>& nums) {
        
        //vector<map<int,int>> dp(nums.size());
        //return func(0,-1e6,nums , dp);

        vector<int> dp(nums.size(),1);
        int maxi = 1;
        for(int i=1 ; i<nums.size() ; i++){
            for(int j = 0 ; j<i ; j++){
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;


    }
};