#include <cmath>
class Solution {
public:

    bool eat(int k , vector<int> piles , int h){

        int cnt=0;
        for(int i = 0 ; i<piles.size() ; i++ ){
            cnt += ceil((double)piles[i] / k);
        }
        if(cnt>h) return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        
        sort(piles.begin() , piles.end());
        int left =1;
        int right = piles[piles.size()-1];

        while(left<right){
            int mid  = left + (right-left)/2;
            if(eat(mid , piles , h)){
                right=mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};