class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        
        int n = nums.size();

        
        vector<vector<int>> arr(n,vector<int>(2049,0));

        
        for(int i=n-1 ; i>=0 ; i--){
            
            for(int j=i ; j<n ; j++){

                int x = nums[j]^nums[i];
                arr[i][x]=1;
               

            }
            
        }

        for(int i=n-2 ; i>=0 ; i--){
            for(int j=0 ; j<=2048 ; j++){
                if(arr[i+1][j]==1) arr[i][j]=1;
            }
        }

        int cnt=0;
        for(int i=0 ; i<2048 ; i++){
            for(int j=0 ; j<n ; j++){
                int same = i^nums[j];
                if(arr[j][same]==1){
                    cnt++;
                    break;
                }
            }
        }

        return cnt;
    }
};