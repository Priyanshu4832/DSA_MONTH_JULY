#include <cmath>
class Solution {
public:

    bool eat(int k , vector<int> piles , int h){

        long cnt = 0;
        for(int i = 0 ; i<piles.size() ; i++){

            if(piles[i]%k==0){
                cnt += piles[i]/k;
            }
            else cnt+=(piles[i]/k)+1;
        }
        if(cnt<=h) return true;
        else return false;
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        
        int low=1;
        int high =*max_element(piles.begin(),piles.end());;

        int ans = high;
        while(low<=high){
            int mid =low + (high-low)/2;

            if(eat(mid,piles,h)){
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