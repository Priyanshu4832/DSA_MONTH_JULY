class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n = colors.size();
        int cost=0;
        for(int i=0 ; i<n-1 ; i++){
            if(colors[i]==colors[i+1]){
                int maxi=neededTime[i];
                int ccost=0;
                ccost+=neededTime[i];
                char store = colors[i];
                i++;
                while(colors[i]==store){
                    ccost += neededTime[i];
                    maxi=max(neededTime[i],maxi);
                    i++;
                }

                cost += (ccost-maxi);
                i--;
                
            }
        }
        return cost;
    }
};