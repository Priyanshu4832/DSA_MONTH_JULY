class Solution {
public:
    int func(int idx,int end,vector<int> nums , vector<int>& dp ){
        if(idx==end){
            return nums[end];
        }
        else if(idx<end) return 0;

       
        if(dp[idx]!=-1) return dp[idx];


        int skip = 0 + func(idx-1,end,nums,dp);
        int rob  = nums[idx] + func(idx-2,end,nums,dp);
        return dp[idx]=max(skip,rob);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
       // if(nums.size()==2) return max(nums[0],nums[1]);



        int n = nums.size();
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);

        int a=func(n-2,0,nums,dp1);
        int b=func(n-1,1,nums,dp2);
        return max(a,b);
    }
};