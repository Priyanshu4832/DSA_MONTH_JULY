class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        
        int n = nums.size();
    
        map<int, int> mpp;
        for(int i=0 ; i<n ; i++){
            int m = ((nums[i] % value) + value) % value;
            mpp[m]++;
        }


        int i=0 ; 
        while(true){
            int k = i;
            int m = k%value;
            
            if(mpp.find(m)!=mpp.end()){
                mpp[m]--;
                if(mpp[m]==0) mpp.erase(m);
                i++;

                
            }
            else{
                break;
            }
            

        }
       
       
        return i ;
    }
};