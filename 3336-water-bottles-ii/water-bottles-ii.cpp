class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        
        int empty=0;
        int cnt =0;
        while(numBottles!=0){
            cout<<"current bottles "<<numBottles<<endl;;
            if(empty==numExchange){
                empty=0;
                numBottles+=1;
                numExchange+=1;
            }
            cnt+=1;
            numBottles-=1;
            empty+=1;
        }
        if(empty==numExchange) cnt+=1;
        return cnt;
    }
};
