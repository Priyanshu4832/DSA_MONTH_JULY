class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        if(nums.size()<=2) return 0;
        sort(nums.begin(),nums.end());

        int cnt = 0 ;
        int n = nums.size();
        for(int i = 0 ; i<n-2 ; i++){
            for(int j =i+1 ; j<n-1 ; j++){
                for(int k = j+1 ; k<n ; k++){
                    if(nums[i]+nums[j]>nums[k]) {
                        cnt++;
                        //cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                    }
                }
            }
        }
        return cnt;
    }
};