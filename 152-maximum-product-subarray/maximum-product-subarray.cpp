class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int neg = 0 ;
        //return 2;

        int maxi = INT_MIN;
        int curr_max = 1;
        int curr_min = 1;

        for(int i = 0 ; i<n ; i++){

            if(nums[i]==0){
                curr_max = 1;
                curr_min = 1;
            }
            else if(nums[i]<0) swap(curr_max,curr_min);

            curr_max = max(nums[i],curr_max*nums[i]);
            curr_min = min(nums[i],curr_min*nums[i]);

            maxi = max(maxi,max(curr_max,curr_min));
        } 
        return maxi;
        
    }
};