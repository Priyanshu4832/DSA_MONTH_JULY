class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        int x = extraStudents;
        priority_queue<pair<double,pair<int,int>>> maxHeap;

        for(auto it : classes){
            double improv =  ( (double)(it[0]+1)/(it[1]+1) )   - ( (double)(it[0])/(it[1]) ) ;
            maxHeap.push( { improv , { it[0],it[1] } } );
        }


        while(x>0){

            auto it = maxHeap.top().second;
            maxHeap.pop();

            double newImprov =  ( (double)(it.first+2)/(it.second+2) )   - ( (double)(it.first+1)/(it.second+1) ) ;
            maxHeap.push( { newImprov , { it.first+1,it.second+1 } } );
            x--;
        }

        double rat = 0;
        while(!maxHeap.empty()){
            auto it = maxHeap.top().second;
            double partRatio = (double)it.first/it.second;
            rat+=partRatio;
            maxHeap.pop();
        }

        return rat/(classes.size());

    }
};