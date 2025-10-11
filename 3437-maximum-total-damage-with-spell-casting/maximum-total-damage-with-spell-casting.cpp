class Solution {
public:

    long long func(int idx , vector<pair<long long,long long>> &uniques , vector<long long>& dp){
        if(idx==uniques.size()) return 0;

        if(dp[idx]!=-1) return dp[idx];

        long long right = func(idx+1,uniques,dp);

        int k=idx+1;
        while( k<uniques.size() && uniques[idx].first + 2 >= uniques[k].first ) k++;
        long long left = uniques[idx].second + func(k,uniques,dp) ;
 
        return dp[idx]=max(left,right);
    }
    long long maximumTotalDamage(vector<int>& power) {
        
        int n = power.size();
        
        

        vector<pair<long long , long long>> uniques;
        map<int , long long> mpp;
        for(int i=0 ; i<n ; i++){
            mpp[power[i]]+=power[i];
        }
        for(auto it : mpp) uniques.push_back({it.first,it.second});


        vector<long long> dp(n , -1);
        
        return func(0,uniques,dp);
    }
};