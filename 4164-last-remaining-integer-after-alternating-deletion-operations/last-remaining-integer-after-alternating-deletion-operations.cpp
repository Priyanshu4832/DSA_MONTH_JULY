class Solution {
public:
    long long lastInteger(long long n) {
        
        if(n==1) return 1;

        long long len = (n+1)/2;

        bool toggle = true;
        long long start = 1;
       
        long long diff = 1;

        while(len>1){

            if(toggle){

                long long newStart = start + (len-1)*(1LL<<diff);
            
                diff++;
                len = (len+1)/2;
                toggle = false;
                
                start = newStart;
                
            }
            else{
                long long newStart = start + (-1)*(len-1)*(1LL<<diff);
                diff++;
               
                len = (len+1)/2;
                toggle = true;
                
                start = newStart;
                
            }

            
        }
        return start;
    }
};