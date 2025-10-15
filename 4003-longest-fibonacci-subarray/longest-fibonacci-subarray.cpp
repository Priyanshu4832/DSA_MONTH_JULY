class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int k=2;
        int maxLen=0;

       
        while(k<nums.size()){

            int cnt=2;
            int i=k;
            while(i<n && (nums[i]==(nums[i-1]+nums[i-2]))){
                i++;
                cnt++;
            }
            k++;

           

            maxLen=max(maxLen , cnt);
            
        }

        return maxLen;
    }
};