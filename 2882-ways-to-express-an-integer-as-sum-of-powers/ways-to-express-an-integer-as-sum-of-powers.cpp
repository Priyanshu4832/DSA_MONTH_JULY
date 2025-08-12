class Solution {
public:
    int mod = 1000000007;
    int func(int idx , int s, int n, vector<int>& arr , vector<vector<int>> &dp ){

        if(s>n) return 0;
        if(idx==arr.size()){
            return (s==n);
            
        }

        if(dp[idx][s]!=-1) return dp[idx][s];
        //pick
        int left = func(idx+1,s+arr[idx] , n , arr , dp);

        //not pick
        int right = func(idx+1,s , n , arr , dp);

        return dp[idx][s] = (left+right)%mod;

    }
    int numberOfWays(int n, int x) {
        

        vector<int> temp;
        
        int i = 1;
        while (true) {
            long long cal = 1;
            long long base = i;
            
            // Calculate i^x using long long to prevent overflow
            for (int j = 0; j < x; j++) {
                if (cal > n / base) { // Check for overflow before multiplication
                    cal = n + 1; // Set to a value > n to break
                    break;
                }
                cal *= base;
            }
            
            if (cal > n) break;
            temp.push_back((int)cal);
            i++;
        }
        
        vector<vector<int>> dp(temp.size(), vector<int>(n + 1, -1));
        return func(0, 0, n, temp, dp);
    }
};