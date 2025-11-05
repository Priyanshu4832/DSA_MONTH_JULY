class Solution {
public:
    bool check(int idx ,vector<int> & deficet){

        int n = deficet.size();
        

        int fuel=0;
        for(int i=idx ; i<n ; i++){
            fuel+=deficet[i];
            if(fuel<0) return false;
        }
        for(int i=0 ; i<idx ; i++){
            fuel+=deficet[i];
            if(fuel<0) return false;
        }
        return true;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        


        int n=gas.size();
        int cnt=0;
        vector<int> deficet(n);

        queue<int> q;

        int maxi=0;
        for(int i=0 ; i<n; i++){
            int cal=gas[i]-cost[i];
            deficet[i]=cal;
            cnt+=cal;
            maxi=max(maxi,cal);
            
        } 
        if(cnt<0) return -1;


        int stidx=0;
        int fuel=0;
        for(int i=0 ; i<n ; i++){
            fuel+=deficet[i];
            if(fuel<0){
                stidx=i+1;
                fuel=0;
            }
        }


        

        
        return stidx;;

        


        

    }
};