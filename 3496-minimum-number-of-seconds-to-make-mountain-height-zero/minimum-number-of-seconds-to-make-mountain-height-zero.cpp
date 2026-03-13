class Solution {
public:

    pair<bool,long long> check(long long time , int mountainHeight , vector<int>& workerTimes ){

        long long secondsAccumulated = 0;
        long long heightAccumulated = 0;

        for(int i=0 ; i<workerTimes.size() ; i++){

            long long calculateN =   ( -1 +   sqrt(1 + (8.0*(time))/workerTimes[i]  )     )/2;
            heightAccumulated += calculateN;
            //secondsAccumulated += (  workerTimes[i]*(calculateN)*(calculateN+1)  )/2;
        }

        if(heightAccumulated>=mountainHeight){
            return {true , -1};
        }
        else return {false , -1};

    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        long long low = 0;
        long long high = LLONG_MAX;
        long long ans = -1;

        while(low<=high){
            long long mid = (low) + ((high-low)/2);

            auto it = check(mid , mountainHeight , workerTimes);
            if(it.first==true){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};