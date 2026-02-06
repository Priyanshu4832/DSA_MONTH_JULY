class Solution {
public:

    int func(long long atMost , vector<int>& nums , int i){
        
        int left = i+1;
        int right = nums.size()-1;

        int ans = -1;
        while(left<=right){
            int mid = (left+right)/2;

            if(nums[mid]<=atMost){
                ans = mid;
                left = mid+1;
            }
            else right = mid-1;
        }
        return ans;
    }
    int minRemoval(vector<int>& nums, int k) {
        
        sort(nums.begin() , nums.end());

        int ans = 1e6;
        int n = nums.size();
        //for(auto it : nums) cout<<it<<" ";
        //cout<<endl;

        if(1LL*nums[0]*k>=nums[n-1]) return 0;

        for(int i=0 ; i<nums.size()-1 ; i++){

            long long atMost = 1LL*nums[i]*k;

            int idx = func(atMost , nums , i);
            if(idx==-1) continue;
            //cout<<"i:"<<i<<" nums[i]:"<<nums[i]<<" idx:"<<idx<<" nums[idx]:"<<nums[idx]<<endl;
            

            ans = min(ans , i + (n-idx-1) );
        }
        if(ans==1e6) return n-1;
        return ans;
    }
};