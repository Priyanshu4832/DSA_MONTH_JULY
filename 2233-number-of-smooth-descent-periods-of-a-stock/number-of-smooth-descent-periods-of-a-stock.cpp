class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        
        long long ans = 0 ;

        int l=0;
        int r = 0;

        vector<int> breaks;
        int len = 1;


        while(r<prices.size()){
            
            if(r!=0){
                if(prices[r]+1!=prices[r-1]){
                    l=r;
                }
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
};