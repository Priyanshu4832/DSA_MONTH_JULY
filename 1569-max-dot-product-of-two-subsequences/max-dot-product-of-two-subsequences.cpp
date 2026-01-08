class Solution {
public:

    int func(int i , int j , vector<int>& nums1, vector<int>& nums2,vector<vector<int>>& dp){

        if(i>=nums1.size() || j>=nums2.size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        //case1 
        int pick1 = nums1[i]*nums2[j] + func(i+1,j+1,nums1,nums2,dp);
        int pick2 = 0 + func(i+1,j+1,nums1,nums2,dp);
        int pick3 = 0 + func(i+1,j,nums1,nums2,dp);
        int pick4 = 0 + func(i,j+1,nums1,nums2,dp);

        return dp[i][j]= max(pick1,max(pick2,max(pick3,pick4)));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans =  func(0,0,nums1,nums2,dp);

        if(ans==0){
            bool flag = 0;
            for(int i=0 ; i<n ; i++){
                if(nums1[i]==0) flag=1;


            }
            for(int i = 0 ; i<m ; i++) if(nums2[i]==0) flag=1;

            if(flag) return 0 ;

            if(nums1[0]<0){
                int mini = INT_MAX;
                int maxi = INT_MIN;
                for(int i = 0 ; i<n ; i++){
                    
                    maxi = max(maxi,nums1[i]);
                }
                for(int i = 0 ; i<m ; i++){
                    mini = min(mini,nums2[i]);
                }
                return mini*maxi;
            }
            else{
                int mini = INT_MAX;
                int maxi = INT_MIN;
                for(int i = 0 ; i<n ; i++){
                    mini = min(mini,nums1[i]);
                    
                }
                for(int i = 0 ; i<m ; i++){
                    maxi = max(maxi,nums2[i]);
                }
                return mini*maxi;
            }

            

        }

        return ans;


    }
};