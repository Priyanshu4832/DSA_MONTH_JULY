class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        
        int n = nums.size();
        vector<int> hash(value,0);
    
       
        for(int i=0 ; i<n ; i++){
            int m = ((nums[i] % value) + value) % value;
            
            hash[m]++;
        }


        int i=0 ; 
        while(true){
            int k = i;
            int m = k%value;
            
            if(hash[m]!=0){
                hash[m]--;
               
                i++;

                
            }
            else{
                break;
            }
            

        }
       
       
        return i ;
    }
};