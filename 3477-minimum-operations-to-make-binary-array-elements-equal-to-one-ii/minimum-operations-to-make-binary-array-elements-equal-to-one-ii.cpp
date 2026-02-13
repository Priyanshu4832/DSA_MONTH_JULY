class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int flips = 0 ;

        for(int i=0 ; i<nums.size() ; i++){

            if(nums[i]==0){

                if(flips%2==0){
                    flips+=1;
                }

            }
            else{

                //nums[i]==1;
                if(flips%2!=0){
                    flips+=1;
                }
            }
        }
        return flips;
    }
};