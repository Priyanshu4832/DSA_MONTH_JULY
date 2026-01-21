class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        
        vector<int> ans;
        for(auto it : nums){


            bool found = false;
            int mini = 1e9;
            int mask = 0;
            for(int i = 30 ; i>=0 ; i--){

                //check if it is set or not 
                if( ((it >> i)&1) == 1 ){
                    mask = mask | (1<<i );
                }


                int num1 = mask-1;
                int num2 = mask;
                int num3 = mask+1;

                if( num1>=0 && ((num1 | num2) == it) ){
                    mini = min(mini,num1);
                    found = true;
                }
                if((num2 | num3) == it ){
                    mini = min(mini,num2);
                    found = true;
                }


            }
            int val = (found==true) ? mini : -1;
            ans.push_back(val);
        }
        return ans;
    }
};