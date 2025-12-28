class Solution {
public:
    int minAllOneMultiple(int k) {


        // if k is mutpile of 2 or 5 then last wala bit 1 ko divide nahi kar payega
        if(k%2==0 || k%5==0) return -1;
        
        long long digits = 1;
        int num = 1;

        
        // for(int i=1 ; i <=k ; i++ ){
        //     num = (num * 10 + 1)%k;
        //     if(num==0) return i+1;
        //}

        while(true){
            if(digits%k==0) return num;

            digits = (1LL*digits*10 + 1)%k;
            num+=1;
        }
        return -1;

        

    }
};