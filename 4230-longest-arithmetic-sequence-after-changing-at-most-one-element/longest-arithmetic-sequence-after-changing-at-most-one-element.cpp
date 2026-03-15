class Solution {
public:
    int longestArithmetic(vector<int>& nums) {

        int n = nums.size();
        int maxi = 0;

        vector<int> left(n,1);
        left[1]=2;
        vector<int> right(n,1);
        right[n-2]=2;

        for(int i=2 ; i<n ; i++){
            if(nums[i]-nums[i-1]  == nums[i-1]-nums[i-2]){
                left[i]=left[i-1]+1;
            }
            else left[i]=2;
            maxi = max(left[i]+1,maxi);
        }

        for(int i=n-3 ; i>=0 ; i--){
            if(nums[i+2]-nums[i+1]  == nums[i+1]-nums[i]){
                right[i]=right[i+1]+1;
            }
            else right[i]=2;
            maxi = max(right[i]+1,maxi);
        }


       

        for(int i=1 ; i<n-1 ; i++){

            int gap = (nums[i+1]-nums[i-1]);
            if( (gap)%2==0){

                int matchGap = gap/2;
                if(i+1<n-1 && i-1>0 && (nums[i-1]-nums[i-2] == matchGap) && (nums[i+2]-nums[i+1]==matchGap)){
                    maxi = max(left[i-1]+right[i+1]+1 , maxi);
                }
                else if(i+1<n-1 && i-1>0 && (nums[i-1]-nums[i-2] == matchGap)){
                    maxi = max(left[i-1]+2 , maxi);
                }
                else if(i+1<n-1 && i-1>0 && (nums[i+2]-nums[i+1]==matchGap)){
                    maxi = max(right[i+1]+2 , maxi);
                }
                else if(i+1<n-1 && i-1==0 && (nums[i+2]-nums[i+1]==matchGap)){
                    maxi = max(left[i-1]+right[i+1]+1 , maxi);
                }
                else if(i+1==n-1 && i-1>0 && (nums[i-1]-nums[i-2]==matchGap)){
                    maxi = max(left[i-1]+right[i+1]+1 , maxi);
                }
            }
        }
        if(maxi>=n) return n;
        else return maxi;
    }
};