class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        int glob=0;
        int k=0;

        int maxLen=0;

        while(k<nums.size()){
            
          
            int cnt1=0,cnt2=0;
          
            while( k+1<n && nums[k]<nums[k+1]){
               
                cnt1++;
                k++;
               
                
            }
            cnt1++;
            k++;
            

            maxLen=max(maxLen , cnt1/2);
            maxLen=max(min(glob,cnt1) ,maxLen );
            cout<<maxLen<<endl;

           
            while( k+1<n && nums[k]<nums[k+1]){
                
                cnt2++;
                k++;
                
            }
            cnt2++;
            k++;
            
            maxLen = max(maxLen , cnt2/2);
            maxLen = max(maxLen , min(cnt1,cnt2));
            glob = cnt2;
           


        }
        return maxLen;
    }
};
