class Solution {
public:
    bool canSplit( int s , vector<int>& nums, int k){

        int cnt = 1 ;
        int sum = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]>s) return false;
            if( (sum+nums[i]) > s ){
                sum = nums[i];
                cnt+=1;
            }
            else sum+=nums[i];
        }
        if(cnt<=k) return true;
        else return false;

    }
    int splitArray(vector<int>& nums, int k) {
        
        int low=1;
        int high = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            //low = min(weights[i],low);
            high += nums[i];
        }

        int ans = high;
        while(low<=high){
            int mid = (high+low)/2;

            if(canSplit(mid,nums,k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};