class Solution {
public:

    long long func(int idx,int n,vector<int>& nums , vector<long long>& dp){
        if(idx>n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        long long skip = 0 + func(idx+1,n,nums,dp);
        long long rob  = nums[idx] + func(idx+2,n,nums,dp);
        return dp[idx]=max(skip,rob);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {
        
        long long cnt = 0 ;
        int n = nums.size();
        vector<long long> dp(nums.size(),-1);
        
        for(int i=0 ; i<n ; i++){

            if(i!=n-1 && colors[i]==colors[i+1]){

                
                int start = i;
                while(i<n-1 && colors[i]==colors[i+1]){

                    i++;
                }
                int end = i;
                
                cnt+=func(start,end,nums,dp);

            }
            else cnt+=nums[i];
        }
        return cnt;
    }
};