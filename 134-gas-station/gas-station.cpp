class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        


        int n=gas.size();
        int cnt=0;
        

        int maxi=0;
        int stidx=0;
        int fuel=0;
        for(int i=0 ; i<n; i++){
            int cal=gas[i]-cost[i];

  
            cnt+=cal;
            fuel+=cal;
            if(fuel<0){
                stidx=i+1;
                fuel=0;
            }

            
        } 
        if(cnt<0) return -1;

        
        return stidx;;

        


        

    }
};