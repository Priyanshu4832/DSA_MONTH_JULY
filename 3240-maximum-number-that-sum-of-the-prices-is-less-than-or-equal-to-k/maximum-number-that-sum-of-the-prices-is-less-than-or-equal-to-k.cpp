class Solution {
public:

    long long func(long long  n , int x ){


        long long totalcnt = 0;

        for(int i = x ;  i<=60 ; i+=x){
            long long blocksize = 1LL<<i;
            long long halfblocksize = 1LL<<(i-1);

            long long fullblocks = (n+1)/blocksize;

            totalcnt += 1LL*halfblocksize*fullblocks;
            long long remainder = (n+1)%blocksize;

            if(remainder>halfblocksize){
               
                totalcnt += remainder - halfblocksize;

            }

        }
        return totalcnt;
 
    }
    long long findMaximumNumber(long long k, int x) {
        
        long long low = 0;
        long long high = 1e16;
        long long ans = -1;
        while(low<=high){

            long long mid = low + (high-low)/2;
            long long val = func(mid,x);
            if(val<=k){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};