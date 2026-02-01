class Solution {
public:
    bool check(int mid , vector<int>& nums){
        
        int cnt=0;
        for(auto it : nums){
            int c = it/mid;
            if(it%mid!=0) c++;

            cnt+=c;
        }

        long long ch = 1LL*mid*mid;
        if(ch>=cnt) return true;
        else return false;
    }
    int minimumK(vector<int>& nums) {
        
        int low = 1;
        int high = 1e5;
        int ans=-1;

        while(low<=high){

            int mid = (high+low)/2;

            if(check(mid , nums)){
                ans = mid;
                high = mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};