class Solution {
public:
   
    int minRemoval(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        int cnt=1e9;

        int j = 0;

        for(int i=0 ; i<n ; i++){

            while(j<n ){
                long long cal = (long long)nums[i]*k;
                if(cal>=nums[j]){
                    cnt = min ( cnt , n - (j-i+1));
                j++;
                }
                else break;
                
            }
        }
        return cnt;
    }
};