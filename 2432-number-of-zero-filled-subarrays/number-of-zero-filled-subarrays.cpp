class Solution {
public:
    long long cnt(int n){
        return (1LL*n*(n+1))/2;
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        
        int l = 0 ;
        int r = 0;
        long long tot = 0;

        int len = 0;
        while(r<nums.size()){

            if(nums[r]!=0){
                tot+=cnt(len);
                cout<<len<<endl;
                l=r+1;
               
            }

            len = max(0 , r-l+1);
            r++;

        }
        if(nums[r-1]==0){
            tot+=cnt(len);
        }
        return tot;
    }
};