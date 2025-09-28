class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        if(nums.size()<=2) return 0;
        sort(nums.begin(),nums.end());

        int cnt = 0 ;
        int n = nums.size();
        for(int i = 0 ; i<n-2 ; i++){
            for(int j =i+1 ; j<n-1 ; j++){
                
                int r = n-1;
                while(r>j){
                    if(nums[i]+nums[j]>nums[r]) {
                        cnt++;
                        //cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                    }
                    r--;
                }
            }
        }
        return cnt;
    }
};