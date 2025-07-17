class Solution {
public:

    bool inThreshold( int num ,vector<int> nums , int threshold){

        int cnt =0;
        for(int i = 0 ; i <nums.size() ; i++){
            cnt += ceil((double)nums[i]/num);
        }
        if(cnt>threshold) return false;
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int left =1;
        int right = -1;
        for(int i = 0 ; i <nums.size() ; i++){
            right = max(nums[i],right);
        }
        while(left<right){

            int mid = left + (right-left)/2;
            if(inThreshold(mid,nums,threshold)){
                right=mid;
            }
            else{
                left  = mid+1;
            }

        }
        return left;
    }
};