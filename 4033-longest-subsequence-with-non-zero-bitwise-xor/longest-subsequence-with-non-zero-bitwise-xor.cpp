class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int cnt = 0 ;
        for(int i=0 ; i<nums.size() ; i++) if(nums[i]==0) cnt++;

        if(nums.size()==cnt) return 0 ;

        int xorr = 0 ; 
        for(int i=0 ; i<nums.size() ; i++) xorr ^= nums[i];

        int n = nums.size();
        if(xorr==0) return n-1;
        else return n;
    }

};