class Solution {
public:

    vector<int> doo(int n){


        vector<int> temp(10);
        while(n>0){
            int digit = n%10;

            temp[digit]++;


            n=n/10;
        }
        return temp;
    }
    bool reorderedPowerOf2(int n) {
        
     
        vector<int> b  = doo(n);

        for(int i=0 ; i<=30 ; i++){
            int num = 1<<i;
            //create hashmap for this num frequency
            if(b==doo(1<<i)) return true;



        }
        return false;
        
       
    }
};