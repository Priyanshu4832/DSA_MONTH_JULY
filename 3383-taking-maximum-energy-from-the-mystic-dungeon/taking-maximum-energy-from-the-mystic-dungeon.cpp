class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        

        int n = energy.size();
        vector<int> hash(n);

        for(int i=n-1 ; i>=n-k ; i--) hash[i]=energy[i];

        for(int i = n-k-1 ; i>=0 ; i--){
            hash[i]= hash[i+k]+energy[i];
           
        }

        int maxi=-1e9;
        for(auto it : hash) maxi=max(maxi,it);
        return maxi;
    }
};