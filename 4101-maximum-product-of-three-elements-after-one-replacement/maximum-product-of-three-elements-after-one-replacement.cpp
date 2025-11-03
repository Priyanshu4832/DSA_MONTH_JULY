class Solution {
public:
    long long maxProduct(vector<int>& nums) {

        int n=nums.size();
        
        long long res;
        for(int i=0 ; i<n ; i++) nums[i]=abs(nums[i]);
        sort(nums.begin() , nums.end());
        res = abs(1e5*1LL*nums[n-1]*nums[n-2]);
        return res;



    }
};