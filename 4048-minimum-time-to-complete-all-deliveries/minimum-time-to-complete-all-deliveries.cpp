class Solution {
public:

    long long lcm(int r1, int r2){
        return ((r1*r2)/gcd(r1,r2));
    }

    bool canDo(long long T , vector<int>& d, vector<int>& r){


            //3 conditions 

            long long availHoursD1=T-(T/r[0]);
            long long availHoursD2=T-(T/r[1]);


            long long availHours_ExceptCommonHours = T-floor(T/lcm(r[0],r[1]));


            if(availHoursD1>=d[0]  && availHoursD2>=d[1] && availHours_ExceptCommonHours>=(d[0]+d[1])) return true;
            return false;
    }
    long long minimumTime(vector<int>& d, vector<int>& r) {
        

        long long low = 0;
        long long high = 1e10;

        while(low<high){
            long long mid = low + (high - low) / 2;


            if(canDo(mid,d,r)){
                high=mid;
            }
            else low=mid+1;
        }
        return high;
    }
};