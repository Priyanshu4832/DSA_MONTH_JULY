class Solution {
public:
    long long maxProduct(vector<int>& nums) {

        int n=nums.size();
        
        long long res;
        for(int i=0 ; i<n ; i++) nums[i]=abs(nums[i]);

        int max1=-1e7;
        int max2=-1e7;
        for(int i=0 ; i<n ; i++){
            if(nums[i]>=max1){
                max2=max1;
                max1=nums[i];
                
            }
            if(nums[i]>max2 && nums[i]<max1) max2=nums[i];
        }
        
        res = abs(1e5*max1*max2);
        return res;



    }
};