class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int maxi = 0;
        for(int i=0 ; i<nums.size() ; i++) maxi = max(maxi,nums[i]);

        int mov =0 ;
        int maxLen=0;
        int ans =0;
        for(int i=0 ; i<nums.size() ; i++){
            
            if(nums[i]==maxi){
                maxLen=1;
                int j =i+1;
                while(j<nums.size() && nums[j]==maxi){
                    maxLen++;
                    j++;
                }
                i=j-1;

            }
            ans = max(ans,maxLen);
        }

        return ans;

    }
};