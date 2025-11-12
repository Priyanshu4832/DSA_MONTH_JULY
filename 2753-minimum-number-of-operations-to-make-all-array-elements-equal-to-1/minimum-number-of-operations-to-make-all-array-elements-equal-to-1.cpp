class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();
        int cnt=0;
        for(int i=0 ; i<n ; i++){
            if(nums[i]==1) cnt+=1;;
        }
        if(cnt!=0) return n-cnt;
        
        int mini=1e7;
        for(int i=0 ; i<n ; i++){
            int g = nums[i];
            for(int j=i+1 ; j<n ; j++){
                g = gcd(g,nums[j]);
                if(g==1){
                    mini=min(mini,j-i);
                }
            }
        }
        if(mini!=1e7) return mini+n-1;
        return -1;
    }
};