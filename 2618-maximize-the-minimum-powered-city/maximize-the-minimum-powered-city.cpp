class Solution {
public:

    bool check(long long minPower, vector<long long> stations, int r, long long k) {
        int n = stations.size();
        long long sum = 0;
        
        // Calculate initial window sum for city 0: [max(0, 0-r), min(0+r, n-1)]
        int left = 0;
        int right = min(r, n - 1);
        for (int i = left; i <= right; i++) {
            sum += stations[i];
        }
        
        // Check each city
        for (int i = 0; i < n; i++) {
            // Calculate new window bounds for city i
            int newLeft = max(0, i - r);
            int newRight = min(i + r, n - 1);
            
            // Slide window from previous position
            if (i > 0) {
                // Add new elements on the right
                for (int j = right + 1; j <= newRight; j++) {
                    sum += stations[j];
                }
                // Remove old elements on the left
                for (int j = left; j < newLeft; j++) {
                    sum -= stations[j];
                }
            }
            
            left = newLeft;
            right = newRight;
            
            // Check if we need to add stations
            if (sum < minPower) {
                long long needed = minPower - sum;
                if (needed > k) return false;
                
                k -= needed;
                stations[right] += needed;
                sum = minPower;
            }
        }
        
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        vector<long long> longStations(stations.begin(), stations.end());
        long long low=0, high=1e14;
        while(low<high){
            long long mid = low + (high-low+1)/2;

            if(check(mid,longStations,r,k)) {
                low=mid;
            }
            else high=mid-1;
        }
        return low;
    }
};
